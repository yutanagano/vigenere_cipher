/**
 * Given an encryption keyword, get the caesar cipher shift value at a given
 * character position in a target text.
 * (c) Yuta Nagano
 */
#include <string.h>
#include <stdio.h>

int get_shift_at_position(char *key, int position, int decrypt)
{
    // Calculate which letter in the key the position corresponds to
    position %= strlen(key);

    // Calculate the shift at that position
    int shift = key[position] - 'A';

    // Return the negative shift if decrypting
    if (decrypt)
        return -shift;
    
    // Otherwise just return the shift value
    return shift;
}