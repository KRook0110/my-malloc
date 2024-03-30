#include <sys/mman.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <memory.h>
#include "my_malloc.h"

// for ease of use
#define idx_to_ptr(idx) (current_page.start + idx)
#define ptr_to_idx(ptr) ((void*)ptr - current_page.start)
#define data_to_header(ptr) ( (struct BlockHeader*) ((void*) ptr - sizeof(struct BlockHeader)) )
#define header_to_data(ptr) ((void*) ptr + ptr->size)

const int DEFAULT_MMAP_SIZE = 4096;
bool initialized_page = false;

enum State
{
    WORKING = 0,
    FAILED = -1
};


/*
 * struct BlockHeader Notes.
 * functionality : As a header for each malloc block.
 * 1. next and prev depends on DEFAULT_MMAP_SIZE,
 *    if the max possible value of next and prev is smaller than DEFAULT_MMAP_SIZE,
 *    enlarge the int.
 */
typedef int16_t page_idx;
struct BlockHeader
{
    size_t size;
    page_idx next, prev; // if the value is less than 0 then there is no next or prev
};
struct BlockHeader *ptr_head_block = NULL;

/*
 * functionality :
 */
struct Page
{
    size_t size;
    void *start;
};
struct Page current_page;

// Helpers
page_idx
get_available_size(struct BlockHeader *ptr_block)
{
    register page_idx end_of_block = ptr_to_idx(ptr_block) + ptr_block->size;
    if(ptr_block->next == -1)
        return (DEFAULT_MMAP_SIZE - end_of_block);
    return (ptr_block->next - end_of_block);
}


/*
 * functionality : Pages a memory block and initializes current_page.
 * returns : integer
 * parameters : -
 */
enum State
init_malloc()
{

    if(initialized_page)
    {
        printf("initMalloc : this malloc doesn't support multiple pages yet.");
        return FAILED;
    }

    current_page.start = mmap(
            NULL,
            DEFAULT_MMAP_SIZE,
            PROT_READ | PROT_WRITE,
            MAP_ANONYMOUS | MAP_SHARED,
            -1,
            0
        );

    if(current_page.start == NULL)
    {
        printf("init_malloc : mmap failed to page a memory block.\n");
        return FAILED;
    }

    current_page.size = DEFAULT_MMAP_SIZE;
    initialized_page = true;
    return WORKING;

}

/*
 * destMalloc Notes.
 * 1. daellocate mapped memory.
 */
int
dest_malloc()
{

    if(!initialized_page)
    {
        printf("init_malloc : Memoory page isn't initialized.\n");
        return (int) FAILED; // FAILED = -1
    }

    initialized_page = false;
    return munmap(current_page.start, DEFAULT_MMAP_SIZE);

}


void*
find_empty_block(struct BlockHeader *ptr_block)
{
    if(ptr_head_block == NULL && DEFAULT_MMAP_SIZE >= ptr_block->size) // if no blocks are initialized
    {
        ptr_head_block = current_page.start;
        ptr_block->next = -1;
        ptr_block->prev = -1;
        return current_page.start;
    }

    if(ptr_to_idx(ptr_head_block) >= ptr_block->size) // check for space in front of the head block
    {

        ptr_block->next = ptr_to_idx(ptr_head_block);
        ptr_block->prev = -1;

        ptr_head_block->prev = ptr_to_idx(current_page.start);
        ptr_head_block = current_page.start;

        return ptr_head_block;

    }

    struct BlockHeader *ptr_current_block = ptr_head_block;
    while(1)
    {
        void *ptr_end_of_block = (void*) ptr_current_block + ptr_current_block->size;
        page_idx available_size = get_available_size(ptr_current_block);
        if(available_size >= ptr_block->size) {

            ptr_block->next = ptr_current_block->next;
            ptr_block->prev = ptr_to_idx(ptr_current_block);

            ptr_current_block->next = ptr_to_idx(ptr_end_of_block);
            if(ptr_block->next != -1)
                ( (struct BlockHeader*) idx_to_ptr(ptr_block->next))->prev = ptr_to_idx(ptr_end_of_block);

            return ptr_end_of_block;
        }
        if(ptr_current_block->next == -1) break;
        ptr_current_block = (struct BlockHeader* ) idx_to_ptr(ptr_current_block->next);
    }

    return NULL;
}

void*
my_malloc(size_t alloc_size)
{

    if(!initialized_page)
        if(init_malloc() == FAILED)
            exit(-1);

    struct BlockHeader temp;
    temp.size = alloc_size + sizeof(struct BlockHeader);

    struct BlockHeader *ptr_empty_block = (struct BlockHeader*) find_empty_block(&temp);
    *ptr_empty_block = temp;
    return (void*) ptr_empty_block + sizeof(struct BlockHeader);

}

int
my_free(void *ptr_free_block)
{

    struct BlockHeader *ptr_current_block = data_to_header(ptr_free_block);
    if(ptr_current_block->next >= DEFAULT_MMAP_SIZE || // just in case it fails
            ptr_current_block->next < 0 ||
            ptr_current_block->prev >= DEFAULT_MMAP_SIZE ||
            ptr_current_block->prev < 0)
    {
        printf("FAILED : next or prev is out of bounds\n");
        return FAILED;
    }
    if(ptr_current_block->next == -1 && ptr_current_block->next == -1)
    {
        ptr_head_block = NULL;
        return WORKING;
    }

    if(ptr_current_block->prev != -1)
        ((struct BlockHeader*) idx_to_ptr(ptr_current_block->prev))->next = ptr_current_block->next;
    else
        ptr_head_block = (struct BlockHeader*)idx_to_ptr(ptr_current_block->next);

    if(ptr_current_block->next != -1)
        ((struct BlockHeader*) idx_to_ptr(ptr_current_block->next))->prev = ptr_current_block->prev;

    return WORKING;

}

void*
my_realloc(void* ptr_data, size_t alloc_size)
{

    struct BlockHeader *ptr_block = data_to_header(ptr_data);
    size_t needed_size = alloc_size + sizeof(struct BlockHeader) - ptr_block->size;
    page_idx available_size = get_available_size(ptr_block);

    if(available_size >= needed_size)
    {
        ptr_block->size = alloc_size;
        return ptr_data;
    }

    void* new_allocated_memory = my_malloc(alloc_size);
    memcpy(new_allocated_memory, ptr_data, ( (ptr_block->size < alloc_size)?ptr_block->size:alloc_size ) );
    my_free(ptr_data);
    return new_allocated_memory;
}

