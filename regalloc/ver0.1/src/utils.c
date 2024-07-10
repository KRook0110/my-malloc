#include <stdlib.h>

#include "constants.h"
#include <inttypes.h>

size_t bit_to_byte(size_t target_bit) {
    return (target_bit + (BYTE_SIZE - 1)) / BYTE_SIZE; // + (BYTE_SIZE - 1) is to round up
}

size_t byte_to_bit(size_t target_byte) {
    return target_byte * BYTE_SIZE;
}

uint64_t index_mask[64] = {
    (1LL << 1) - 1,
    (1LL << 2) - 1,
    (1LL << 3) - 1,
    (1LL << 4) - 1,
    (1LL << 5) - 1,
    (1LL << 6) - 1,
    (1LL << 7) - 1,
    (1LL << 8) - 1,
    (1LL << 9) - 1,
    (1LL << 10) - 1,
    (1LL << 11) - 1,
    (1LL << 12) - 1,
    (1LL << 13) - 1,
    (1LL << 14) - 1,
    (1LL << 15) - 1,
    (1LL << 16) - 1,
    (1LL << 17) - 1,
    (1LL << 18) - 1,
    (1LL << 19) - 1,
    (1LL << 20) - 1,
    (1LL << 21) - 1,
    (1LL << 22) - 1,
    (1LL << 23) - 1,
    (1LL << 24) - 1,
    (1LL << 25) - 1,
    (1LL << 26) - 1,
    (1LL << 27) - 1,
    (1LL << 28) - 1,
    (1LL << 29) - 1,
    (1LL << 30) - 1,
    (1LL << 31) - 1,
    (1LL << 32) - 1,
    (1LL << 33) - 1,
    (1LL << 34) - 1,
    (1LL << 35) - 1,
    (1LL << 36) - 1,
    (1LL << 37) - 1,
    (1LL << 38) - 1,
    (1LL << 39) - 1,
    (1LL << 40) - 1,
    (1LL << 41) - 1,
    (1LL << 42) - 1,
    (1LL << 43) - 1,
    (1LL << 44) - 1,
    (1LL << 45) - 1,
    (1LL << 46) - 1,
    (1LL << 47) - 1,
    (1LL << 48) - 1,
    (1LL << 49) - 1,
    (1LL << 50) - 1,
    (1LL << 51) - 1,
    (1LL << 52) - 1,
    (1LL << 53) - 1,
    (1LL << 54) - 1,
    (1LL << 55) - 1,
    (1LL << 56) - 1,
    (1LL << 57) - 1,
    (1LL << 58) - 1,
    (1LL << 59) - 1,
    (1LL << 60) - 1,
    (1LL << 61) - 1,
    (1LL << 62) - 1,
    ~0
};

uint64_t index_to_mask(size_t index) {
    return index_mask[index];
}




