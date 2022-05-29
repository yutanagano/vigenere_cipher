/**
 * Unit test for get_shift_at_position
 * (c) Yuta Nagano
 */
#include <stdio.h>
#include "../../src/get_shift_at_position/get_shift_at_position.h"
#include "../assert/assert.h"

int test_get_shift_at_position()
{
    char key_shifts[] = "BCDE";

    puts("Testing get_shift_at_position...");

    // Test positions in encryption mode
    if (int_assert(get_shift_at_position(key_shifts, 0, 0), 1))
        return 1;
    if (int_assert(get_shift_at_position(key_shifts, 1, 0), 2))
        return 1;
    if (int_assert(get_shift_at_position(key_shifts, 2, 0), 3))
        return 1;
    if (int_assert(get_shift_at_position(key_shifts, 3, 0), 4))
        return 1;
    if (int_assert(get_shift_at_position(key_shifts, 4, 0), 1))
        return 1;
    if (int_assert(get_shift_at_position(key_shifts, 5, 0), 2))
        return 1;

    // Test positions in decryption mode
    if (int_assert(get_shift_at_position(key_shifts, 0, 1), -1))
        return 1;
    if (int_assert(get_shift_at_position(key_shifts, 1, 1), -2))
        return 1;
    if (int_assert(get_shift_at_position(key_shifts, 2, 1), -3))
        return 1;
    if (int_assert(get_shift_at_position(key_shifts, 3, 1), -4))
        return 1;
    if (int_assert(get_shift_at_position(key_shifts, 4, 1), -1))
        return 1;
    if (int_assert(get_shift_at_position(key_shifts, 5, 1), -2))
        return 1;

    // Tests finished, return 0
    return 0;
}