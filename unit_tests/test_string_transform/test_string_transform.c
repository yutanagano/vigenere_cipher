/**
 * Unit test for string_transform
 * (c) Yuta Nagano
 */
#include <stdio.h>
#include <string.h>
#include "../../src/string_transform/string_transform.h"
#include "../assert/assert.h"

int test_string_transform()
{
    char key[] = "ABC";

    puts("Testing string_transform...");

    // Test on string with only alphabets
    char alphabets[] = "thisISaTEST";
    string_transform(alphabets, key, 0);
    if (string_assert(alphabets, "tiksJUaUGSU"))
        return 1;
    string_transform(alphabets, key, 1);
    if (string_assert(alphabets, "thisISaTEST"))
        return 1;

    // Test on mixed string
    char mixed[] = "This is a test?!";
    string_transform(mixed, key, 0);
    if (string_assert(mixed, "Tiks ks c ugsu?!"))
        return 1;
    string_transform(mixed, key, 1);
    if (string_assert(mixed, "This is a test?!"))
        return 1;

    // Test on string with only non-alphabets
    char nonalpha[] = "012 !?-+[]";
    string_transform(nonalpha, key, 0);
    if (string_assert(nonalpha, "012 !?-+[]"))
        return 1;
    string_transform(nonalpha, key, 0);
    if (string_assert(nonalpha, "012 !?-+[]"))
        return 1;

    // Test on empty string
    char empty[] = "";
    string_transform(empty, key, 0);
    if (string_assert(empty, ""))
        return 1;
    string_transform(empty, key, 1);
    if (string_assert(empty, ""))
        return 1;

    // Test finished, return 0
    return 0;
}