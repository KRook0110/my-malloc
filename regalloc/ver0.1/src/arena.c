#include <stdbool.h>
#include <stdlib.h>

#include "arena.h"

void*  get_end_of_arena(Arena* arena) {
    return (void*) arena + arena->size + sizeof(Arena);
}

void* get_begin_of_arena(Arena* arena) { // gets the begining where the arena of container starts ( in front of the arena header )
    return (void*) arena + sizeof(Arena);
}

/*
    Checks if the targeted range is in the arena or not.
*/
bool check_in_arena(Arena* arena, void* begin_pointer, void* end_pointer) {
    if(begin_pointer > end_pointer) return false;
    if(begin_pointer < get_begin_of_arena(arena)){
        return false;
    }
    if(begin_pointer >= get_end_of_arena(arena)) {
        return false;
    }
    return true;
}
