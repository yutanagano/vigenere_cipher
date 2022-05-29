/**
 * Given a keyword, standardise so that all characters are uppercase. Throw
 * errors if keyword contains non-alphabetic characters.
 * (c) Yuta Nagano
 */
#include <string.h>
#include <stdio.h>

int process_key(char *key)
{
    // If key string empty, throw error
    if (strlen(key) == 0) {
        fputs("Bad input: keyword empty.\n", stderr);
        return 1;
    }

    // Iterate through every letter in the key word
    for (int i = 0; i < strlen(key); i++) {
        // If character is upper case, leave alone
        if ((key[i] >= 'A') && (key[i] <= 'Z'))
            continue;
        
        // If character is lower case, capitalise
        if ((key[i] >= 'a') && (key[i] <= 'z')) {
            key[i] -= 32;
            continue;
        }
        
        // Otherwise, keyword contains non-alphabetical character, throw error
        fprintf(
            stderr,
            "Bad input: keyword contains non-alphabetical character %c\n",
            key[i]
        );
        return 1;
    }

    // Processing finished, return 0
    return 0;
}