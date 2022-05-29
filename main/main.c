/**
 * Implementation of the vigenere cipher on C.
 * Can handle messages of up to 100 characters per line.
 * (c) Yuta Nagano
 */
#include <stdio.h>
#include <unistd.h>
#include "../src/process_key/process_key.h"
#include "../src/string_transform/string_transform.h"

int main(int argc, char *argv[])
{
    char *key = "";
    char line[101];
    char ch;
    int decrypt = 0;

    // Read command line options
    while ((ch = getopt(argc, argv, "k:d")) != EOF) {
        switch (ch) {
        case 'k':
            key = optarg;
            break;
        case 'd':
            decrypt = 1;
            break;
        default:
            return 1;
        }
    }

    // Process key and throw errors if necessary
    if (process_key(key))
        return 1;

    // Keep reading lines from stdin, and printing out the transformed version
    while (fgets(line, 100, stdin)) {
        string_transform(line, key, decrypt);
        printf(line);
    }

    // Once done, exit with code 0
    return 0;
}