#include <memory.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/types.h>



#include "container.h"
#include "constants.h"
#include "utils.h"
#include "regalloc.h"
#include "arena.h"


/*
    returns the size of state
*/
size_t get_container_state_size(Container target_container) {
    return bit_to_byte(target_container.block_count);
}

/*
    returns the size allocated for memoy allocation in the container
*/
size_t get_container_alloc_size(Container target_container) {
    return target_container.block_count * target_container.block_size;
}

/*
    Gets the total size of the target container
*/
size_t get_container_total_size(Container target_container) {
    return get_container_state_size(target_container) +
           get_container_alloc_size(target_container) +
           sizeof(Container);
}

void* get_end_of_container(Container* target_container) {
    return (void*)target_container + get_container_total_size(*target_container);
}


/*
    gets the maximum block count for with maximum size & block_size. Accounts for container header size
*/
size_t get_maximum_block_count(size_t maximum_size, size_t block_size) {

    size_t total_available_size = maximum_size - sizeof(Container);
    size_t block_size_with_state = byte_to_bit(block_size) + 1;

    return byte_to_bit(total_available_size)  / block_size_with_state;
}


void* get_starting_state_position(Container* target_container) {
    return (void*)target_container + sizeof(Container) + get_container_alloc_size(*target_container);
}

bool check_in_container(Container* target_container, void* alloc_position, size_t alloc_size) {
    if(alloc_position < (void*)target_container + sizeof(Container)) {
        return false;
    }
    if(alloc_position + alloc_size - 1 >= get_starting_state_position(target_container)) {
        return false;
    }
    return true;
}



