#ifndef _REGALLOC_H_
#define _REGALLOC_H_

#include <stdlib.h>
#include <inttypes.h>

typedef struct Container {
    struct Container *ptr_next_container;
    size_t size;
    size_t jump_size;
    uint64_t *bitmap;
    size_t bitmap_size;
    void *data_start;
    size_t data_size;
} Container;

void *regalloc(Container* target_container, size_t alloc_size);

Container *create_container(size_t requested_size, size_t jump_size, Container *ptr_next_container);

void regfree(Container* target_container, void* ptr_data);

#endif
