/**
 * Transform a string according to a vigenere cipher given a key word.
 * (c) Yuta Nagano
 */
#include <string.h>
#include "../caesar_transform_char/caesar_transform_char.h"
#include "../get_shift_at_position/get_shift_at_position.h"

void string_transform(char *string, char *key, int decrypt)
{
    for (int i = 0; i < strlen(string); i++) {
        string[i] = caesar_transform_char(
            string[i],
            get_shift_at_position(key, i, decrypt)
        );
    }
}