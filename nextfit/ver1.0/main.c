#include <stdio.h>
#include "my_malloc.h"

int
main(void)
{
    int *a = (int*) my_malloc(sizeof(int) * 10);
    int *b = (int*) my_malloc(sizeof(int) * 20);
    printf("%llu, %llu\n", (unsigned long long) a, (unsigned long long) b);
}
