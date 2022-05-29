/**
 * Testing suite for vigenere cipher project.
 * (c) Yuta Nagano
 */
#include <stdio.h>
#include "../unit_tests/test_caesar_transform_char/test_caesar_transform_char.h"
#include "../unit_tests/test_get_shift_at_position/test_get_shift_at_position.h"
#include "../unit_tests/test_process_key/test_process_key.h"
#include "../unit_tests/test_string_transform/test_string_transform.h"

int main()
{
    puts("Running unit tests...");

    // Run unit tests
    if (test_caesar_transform_char())
        return 1;
    if (test_process_key())
        return 1;
    if (test_get_shift_at_position())
        return 1;
    if (test_string_transform())
        return 1;
    
    // Tests finished, return 0
    puts("Tests finished, no errors found.");
    return 0;
}