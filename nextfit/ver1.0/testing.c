#include <stdint.h>
#include <stdio.h>

struct BlockHeader
{
    size_t size;
    int a;
};

int main(void)
{
    printf("%zu", sizeof(struct BlockHeader));
}
