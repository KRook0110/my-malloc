#include <stdio.h>
#include "my_malloc.c"
#include "my_malloc.h"

int
main(void)
{
    void* x = my_malloc(100);
    *(int*)x = 10;
}
