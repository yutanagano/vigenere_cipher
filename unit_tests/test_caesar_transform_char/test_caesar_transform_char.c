/**
 * Unit test for caesar_transform_char.
 * (c) Yuta Nagano
 */
#include <stdio.h>
#include "../../src/caesar_transform_char/caesar_transform_char.h"
#include "../../unit_tests/assert/assert.h"

int test_caesar_transform_char()
{
    char in, out;
    int shift;

    puts("Testing caesar_transform_char...");

    // Test basic transformations
    shift = 1;
    in = 'A';
    out = caesar_transform_char(in, shift);
    if (char_assert(in, out, 'B'))
        return 1;
    in = 'a';
    out = caesar_transform_char(in, shift);
    if (char_assert(in, out, 'b'))
        return 1;

    // Test negative transformations
    shift = -2;
    in = 'A';
    out = caesar_transform_char(in, shift);
    if (char_assert(in, out, 'Y'))
        return 1;
    in = 'a';
    out = caesar_transform_char(in, shift);
    if (char_assert(in, out, 'y'))
        return 1;
    
    // Test wraparound transformations
    shift = 3;
    in = 'Y';
    out = caesar_transform_char(in, shift);
    if (char_assert(in, out, 'B'))
        return 1;
    in = 'y';
    out = caesar_transform_char(in, shift);
    if (char_assert(in, out, 'b'))
        return 1;

    // Test double wraparound transformations
    shift = 29;
    in = 'Y';
    out = caesar_transform_char(in, shift);
    if (char_assert(in, out, 'B'))
        return 1;
    in = 'y';
    out = caesar_transform_char(in, shift);
    if (char_assert(in, out, 'b'))
        return 1;
    
    // Test non-alphabetic characters
    shift = 5;
    in = '!';
    out = caesar_transform_char(in, shift);
    if (char_assert(in, out, '!'))
        return 1;
    in = '0';
    out = caesar_transform_char(in, shift);
    if (char_assert(in, out, '0'))
        return 1;

    // Testing finished, return 0
    return 0;
}