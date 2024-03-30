#ifndef __MY_MALLOC_H
#define __MY_MALLOC_H

#include <stdlib.h>

int dest_malloc();

void* my_malloc(size_t alloc_size);

int my_free(void *ptr_to_be_freed);

void* my_realloc(void* ptr_to_be_reallocated, size_t alloc_size);

#endif
