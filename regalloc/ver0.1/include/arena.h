#ifndef ARENA_H_
#define ARENA_H_

#include <stdlib.h>
#include <stdbool.h>

/**/
typedef struct ArenaTag {
    size_t size; // size of bytes, not including the header size
    size_t container_count; // the total number of containers
    struct ArenaTag *next_arena; // the next arena, if null then there is no next arena
} Arena;


/*
    Checks if the targeted range is in the arena or not.
*/
bool check_in_arena(Arena* arena, void* begin_pointer, void* end_pointer);

#endif
