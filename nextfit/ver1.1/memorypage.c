#include <sys/mman.h>
#include <memory.h>

enum Sizes {
    SMALL,
    MEDIUM,
    LARGE,
};

typedef struct MemoryPage
{
    size_t size;
    void* next_page;
}
MemoryPage;
MemoryPage *ptr_head_page = NULL;


void* find_page_start(MemoryPage* mempage)
{
    return ((void*) mempage + sizeof(MemoryPage));
}

MemoryPage* create_new_page(int alloc_size) {

    MemoryPage new_page_values = {
        alloc_size + sizeof(MemoryPage),
        NULL
    };

    MemoryPage *new_allocated_mem = mmap(
            NULL,
            ,
            PROT_READ | PROT_WRITE,
            MAP_ANONYMOUS | MAP_SHARED,
            -1,
            0
            )

    if(ptr_head_page == NULL) {
    }
}
