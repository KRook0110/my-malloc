/*
    Notes:

        find first 1 bit in a integer : number & ( ( number - 1 ) << 1 )
                                        then just look up using a table { 1:1, 2:2, 4:3, 8:4, 16:5, ... }

*/

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


/*

+-------------------------------- Arena Block -------------------------------+
|                                                                            |
|   +--- Container ---+         +---Container 2---+                          |
|   |                 |         |                 |                          |
|   |      Header     |         |      Header     |                          |
|   +-----------------+         +-----------------+                          |
|   |                 |         |                 |                          |
|   |      State      |         |      State      |                          |
|   |                 |         |                 |          ETC....         |
|   +-----------------+         +-----------------+                          |
|   |                 |         |                 |                          |
|   |                 |         |                 |                          |
|   |                 |         |                 |                          |
|   |     Alloc       |         |      Alloc      |                          |
|   |                 |         |                 |                          |
|   |                 |         |                 |                          |
|   |                 |         |                 |                          |
|   +-----------------+         +-----------------+                          |
|                                                                            |
+----------------------------------------------------------------------------+


*/
