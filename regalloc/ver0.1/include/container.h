#ifndef CONTAINER_H_
#define CONTAINER_H_

#include <stdlib.h>

/*
    block_count -> Number of blocks the container has
    block_size -> the number of size(number of bytes) of a single block inside of the container( all blocks inside the container have the same size, though the number can vary between containers)
    next_container -> is a pointer to the next container, if the value of next_container is NULL then there is no next_container
*/
typedef struct ContainerTag {
    size_t block_size;
    size_t block_count;
    struct ContainerTag *next_container;
} Container;


size_t get_container_state_size(Container target_container);


size_t get_container_alloc_size(Container target_container);


size_t get_container_total_size(Container target_container);

void* get_end_of_container(Container* target_container);

#endif
