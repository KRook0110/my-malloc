#include <errno.h>
#include <inttypes.h>
#include <memory.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>

// Settings
#define _DEBUG_MODE_

#define BYTE_SIZE 8LLU
#define MEGABYTE_SIZE 1000000LLU

// Utils {{{

// Debug Tools
#ifdef _DEBUG_MODE_
#define dbg(value, format) printf(#value " : %" format "\n", value)
#define dbgf(format, ...) printf(format, __VA_ARGS__)
#else
#define dbg(value, format)
#define dbgf(format, ...)
#endif

size_t bit_to_byte(size_t target_bit) {
    return (target_bit + (BYTE_SIZE - 1)) /
           BYTE_SIZE; // + (BYTE_SIZE - 1) is to round up
}

size_t byte_to_bit(size_t target_byte) { return target_byte * BYTE_SIZE; }

uint64_t index_mask[64] = {(1LL << 1) - 1,  (1LL << 2) - 1,  (1LL << 3) - 1,
                           (1LL << 4) - 1,  (1LL << 5) - 1,  (1LL << 6) - 1,
                           (1LL << 7) - 1,  (1LL << 8) - 1,  (1LL << 9) - 1,
                           (1LL << 10) - 1, (1LL << 11) - 1, (1LL << 12) - 1,
                           (1LL << 13) - 1, (1LL << 14) - 1, (1LL << 15) - 1,
                           (1LL << 16) - 1, (1LL << 17) - 1, (1LL << 18) - 1,
                           (1LL << 19) - 1, (1LL << 20) - 1, (1LL << 21) - 1,
                           (1LL << 22) - 1, (1LL << 23) - 1, (1LL << 24) - 1,
                           (1LL << 25) - 1, (1LL << 26) - 1, (1LL << 27) - 1,
                           (1LL << 28) - 1, (1LL << 29) - 1, (1LL << 30) - 1,
                           (1LL << 31) - 1, (1LL << 32) - 1, (1LL << 33) - 1,
                           (1LL << 34) - 1, (1LL << 35) - 1, (1LL << 36) - 1,
                           (1LL << 37) - 1, (1LL << 38) - 1, (1LL << 39) - 1,
                           (1LL << 40) - 1, (1LL << 41) - 1, (1LL << 42) - 1,
                           (1LL << 43) - 1, (1LL << 44) - 1, (1LL << 45) - 1,
                           (1LL << 46) - 1, (1LL << 47) - 1, (1LL << 48) - 1,
                           (1LL << 49) - 1, (1LL << 50) - 1, (1LL << 51) - 1,
                           (1LL << 52) - 1, (1LL << 53) - 1, (1LL << 54) - 1,
                           (1LL << 55) - 1, (1LL << 56) - 1, (1LL << 57) - 1,
                           (1LL << 58) - 1, (1LL << 59) - 1, (1LL << 60) - 1,
                           (1LL << 61) - 1, (1LL << 62) - 1, ~0};

uint64_t index_to_mask(size_t index) { return index_mask[index]; }

uint64_t bit_to_index(uint64_t target_bytes) {
    return __builtin_ctz(target_bytes) + 1;
}

// }}}

typedef struct Container {
    struct Container *ptr_next_container;
    size_t size;
    size_t jump_size;
    uint64_t *bitmap;
    size_t bitmap_size;
    void *data_start;
    size_t data_size;
} Container;

#define BITMAP_TYPE_SIZE (*((Container *)0)->bitmap)

/*
    Requested size on bytes
*/
Container *create_container(size_t requested_size, size_t jump_size,
                            Container *ptr_next_container) {

    if (requested_size % jump_size != 0) {
        fprintf(stderr, "requested_size is not dividable by jump_size\n");
        return NULL;
    }

    size_t total_state_size = bit_to_byte(requested_size / jump_size);
    size_t total_size = requested_size + total_state_size + sizeof(Container);

    void *ptr_new_container_position;
    // ptr_new_container_position = sbrk(total_size);
    // ptr_new_container_position = mmap(NULL, total_size, PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_SHARED, -1, 0);
    ptr_new_container_position = malloc(total_size);

    if (ptr_new_container_position == NULL) {
        printf("%llu\n", errno);
        printf("Mapping Failed\n");
        return NULL;
    }

    memset(ptr_new_container_position, 0,
           sizeof(Container) + bit_to_byte(total_state_size));
    // memset(ptr_new_container_position, 0,total_size);

    Container new_container_data = {
        ptr_next_container,
        total_size,
        jump_size,
        (uint64_t *)ptr_new_container_position + sizeof(Container),
        requested_size / jump_size, // in bits
        ptr_new_container_position + sizeof(Container) + total_state_size,
        requested_size};

    *(Container *)(ptr_new_container_position) = new_container_data;
    return ptr_new_container_position;
}

size_t find_closing_bitmap_pair(Container *target_container,
                                size_t start_state_idx) {

    uint64_t byte_index = start_state_idx /
                          (BYTE_SIZE * sizeof(*((Container *)0)->bitmap)),
             bit_index_relative =
                 start_state_idx %
                 (BYTE_SIZE * sizeof(*((Container *)0)->bitmap));

    uint64_t masked = target_container->bitmap[byte_index] &
                      ~index_to_mask(bit_index_relative);
    uint64_t cur = masked & ((masked - 1) << 1);
    if (cur > 0) {
        return BYTE_SIZE * sizeof(*((Container *)0)->bitmap) * byte_index +
               __builtin_ctzll(cur);
    }

    uint64_t index = byte_index + 1;
    while (index * (BYTE_SIZE * sizeof(*((Container *)0)->bitmap)) + 63 <
           target_container->bitmap_size) {
        cur = target_container->bitmap[index];
        if (cur > 0) {
            return index * BYTE_SIZE * sizeof(*((Container *)0)->bitmap) +
                   __builtin_ctzll(cur);
        }
        index++;
    }

    cur = __builtin_ctzll(target_container->bitmap[index]);
    if (cur < target_container->bitmap_size %
                  (BYTE_SIZE * sizeof(*((Container *)0)->bitmap))) {
        return cur + index * BYTE_SIZE * sizeof(*((Container *)0)->bitmap);
    }

    return -1;
}

size_t data_ptr_to_bitmap_idx(Container *target_container, void *ptr_data) {
    return (ptr_data - (void *)target_container->data_start) /
           target_container->jump_size;
}

void clean_containers(Container *target_container) {

    Container *current_container = target_container;

    while (current_container != NULL) {
        Container *temp = current_container;
        current_container = current_container->ptr_next_container;
        munmap((void *)temp, temp->size);
    }
}

bool check_bitmap(Container *target_container, size_t index) {
    size_t bitmap_index =
        index / (BYTE_SIZE * sizeof(*((Container *)0)->bitmap));
    size_t relative_index =
        index % (BYTE_SIZE * sizeof(*((Container *)0)->bitmap));
    return ((target_container->bitmap[bitmap_index] & (1 >> relative_index)) >
            0);
}

size_t find_empty_bitmap_index(Container *target_container,
                               size_t target_space) {
    size_t cur_index = 0;
    size_t target_jumps = (target_space + (target_container->jump_size - 1)) /
                          target_container->jump_size;

    do {
        bool in_alloced_space = check_bitmap(target_container, cur_index);
        size_t closing_index =
            find_closing_bitmap_pair(target_container, cur_index);
        if (closing_index == 0)
            closing_index = target_container->bitmap_size;
        if (!in_alloced_space && (closing_index - cur_index) >= target_jumps) {
            return cur_index;
        }
        cur_index = closing_index + (in_alloced_space);

    } while (cur_index < target_container->bitmap_size);
    return -1;
}

void set_bit(uint64_t *bitmap, size_t index, bool value) {
    size_t bitmap_index =
        index / (BYTE_SIZE * sizeof(*((Container *)0)->bitmap));
    size_t relative_index =
        index % (BYTE_SIZE * sizeof(*((Container *)0)->bitmap));
    if (value == 1) {
        bitmap[bitmap_index] |= 1 << relative_index;
    } else {
        bitmap[bitmap_index] &= ~(1 << relative_index);
    }
}

void *bitmap_index_to_ptr(Container *container, size_t bitmap_index) {
    return container->data_start + bitmap_index * container->jump_size;
}

void *regalloc(Container *target_container,
               size_t alloc_size) { // alloc_size in bytes
    size_t needed_bitmap_space =
        (alloc_size + (target_container->jump_size - 1)) /
        target_container->jump_size;
    size_t new_alloc_position =
        find_empty_bitmap_index(target_container, alloc_size);
    set_bit(target_container->bitmap, new_alloc_position, 1);
    if (needed_bitmap_space == 1) {
        set_bit(target_container->bitmap, new_alloc_position + 1, 1);
    } else {
        set_bit(target_container->bitmap,
                new_alloc_position + needed_bitmap_space - 1, 1);
    }
    return bitmap_index_to_ptr(target_container, new_alloc_position);
}

void regfree(Container *target_container, void *ptr_data) {
    size_t idx = data_ptr_to_bitmap_idx(target_container, ptr_data);
    if (check_bitmap(target_container, idx) == 0) {
        return;
    }
    size_t closing_pair_index = find_closing_bitmap_pair(target_container, idx);
    set_bit(target_container->bitmap, idx, 0);
    set_bit(target_container->bitmap, closing_pair_index, 0);
}

void print_bitmap_index(Container *target_container) {
    for (size_t i = 0; i < target_container->bitmap_size; i++) {
        size_t bitmap_index =
            i / (BYTE_SIZE * sizeof(*((Container *)0)->bitmap));
        size_t relative_index =
            i % (BYTE_SIZE * sizeof(*((Container *)0)->bitmap));

        if (target_container->bitmap[bitmap_index] & (1LLU << relative_index)) {
            printf("%zu ", i);
        }
    }
    printf("\n");
}

void print_bitmap(Container *target_container) {
    size_t amount_of_bytes = bit_to_byte(target_container->bitmap_size);
    for (int i = 0; i < amount_of_bytes; i++) {
        printf("%lu ", target_container->bitmap[i]);
    }
    printf("\n");
}

int main(int argc, char **argv) {
    if(argc == 1) return 1;
    int n = 100;
    int size = atoi(argv[1]);
    int jump_size = 1;

    Container *temp = create_container((n) * (size) , (jump_size), NULL);
    getchar();
    getchar();

    return 0;
}

