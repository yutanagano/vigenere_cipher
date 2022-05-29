## Vigenere Cipher, implemented in C

This is a simple C project implementing the Vigenere cipher, a derivative of
the Caesar cipher. Where the Caesar cipher uses a single key value to shift all
characters in a message, the Vigenere cipher uses a multi-character word as a
key, where each letter represents a particular shift value (A=0, B=1, etc.).
See [the wikipedia page](https://en.wikipedia.org/wiki/Vigen%C3%A8re_cipher)
for more details.

## Building

Make sure that you have [gcc](https://en.wikipedia.org/wiki/GNU_Compiler_Collection)
installed on your system. Clone this repo. Then, inside the root directory of
this project, run:

    make main

This will compile a binary of this project onto the current directory. The file
will be named `vcipher`.

## Testing

To run the unit tests, run:

    make test

This will compile a test suite and then run it straight after. If the output
says:

    Tests finished, no errors found.

the tests are still passing.

> Note: The testing suite may output certain lines such as `Bad input: keyword 
> contains non-alphabetical character $` while running the test suite, but this
> is expected.