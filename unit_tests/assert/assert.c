/**
 * Helper assertion functions for the testing suite.
 * (c) Yuta Nagano
 */
#include <stdio.h>

int int_assert(int out, int expected)
{
    // If match, return 0
    if (out == expected)
        return 0;

    fprintf(
        stderr,
        "Error: expected %i, got %i\n",
        expected,
        out
    );
    return 1;
}

int char_assert(char in, char out, char expected)
{
    // If output as expected, return 0
    if (out == expected)
        return 0;

    // Otherwise, print error message and return 1
    fprintf(
        stderr,
        "Error: input %c, expected %c, got %c.\n",
        in,
        expected,
        out
    );
    return 1;
}

int string_assert(char *out, char *expected)
{
    // Compare each value in the string
    for (int i = 0; out[i] != '\0'; i++) {
        // If unequal, throw error
        if (out[i] != expected[i]) {
            fprintf(
                stderr,
                "Error: array unequal at index %i: (%hi/%c, %hi/%c)\n",
                i,
                out[i],
                out[i],
                expected[i],
                expected[i]
            );
            return 1;
        }
    }

    // Comparison finished, return 0
    return 0;
}