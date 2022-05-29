/**
 * Header file for assert.c
 * (c) Yuta Nagano
 */

int int_assert(int out, int expected);
int char_assert(char in, char out, char expected);
int string_assert(char *out, char *expected);