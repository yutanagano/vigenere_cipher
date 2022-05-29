/**
 * Unit test for process_key.
 * (c) Yuta Nagano
 */
#include <stdio.h>
#include "../../src/process_key/process_key.h"
#include "../assert/assert.h"

int test_process_key()
{
    char expected[] = "TEST";

    puts("Testing process_key...");

    // Test lowercase keyword
    char keyword_lower[] = "test";
    process_key(keyword_lower);
    if (string_assert(keyword_lower, expected))
        return 1;

    // Test uppercase keyword
    char keyword_upper[] = "TEST";
    process_key(keyword_upper);
    if (string_assert(keyword_upper, expected))
        return 1;

    // Test mixed-case keyword
    char keyword_mixed[] = "tEsT";
    process_key(keyword_mixed);
    if (string_assert(keyword_mixed, expected))
        return 1;

    // Test keyword with non-alphabetic characters
    char keyword_nonalpha[] = "te$t";
    if (!process_key(keyword_nonalpha)) {
        fputs("Error: non-alphanumeric key accepted.", stderr);
        return 1;
    }

    // Test empty string keyword
    char keyword_empty[] = "";
    if (!process_key(keyword_empty)) {
        fputs("Error: empty keyword accepted.", stderr);
        return 1;
    }

    // Test finished, return 0
    return 0;
}