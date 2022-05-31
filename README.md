## Vigenere Cipher, implemented in C

This is a simple C project implementing the Vigenere cipher, a derivative of
the Caesar cipher. Where the Caesar cipher uses a single key value to shift all
characters in a message, the Vigenere cipher uses a multi-character word as a
key, where each letter represents a particular shift value (A=0, B=1, etc.).
See [the wikipedia page](https://en.wikipedia.org/wiki/Vigen%C3%A8re_cipher)
for more details.

## Use

The program (the executable will be named `vcipher` once compiled) will take in
a cipher key as a command line option (using -k) and output an accordingly 
encrypted version of each line of text it sees in the standard input stream.

> Note: `vcipher` will only read up to 100 characters per line in the standard
> input.

By default, it will run in encryption mode, but by specifying decryption mode
(using option -d) it can decrypt messages symmetrically using the same key as
well.

    $ echo "text" | ./vcipher -k key
    > divd

    $ echo "divd" | ./vcipher -k key -d
    > text

> Note: The cipher will preserve letter capitalisation in the output. All
> non-alphabetic characters will remain untouched by `vcipher`, but note that 
> in this implementation, the non-alphabetic characters still contribute to the
> text-key alignment process. See below for an illustration.

    $ echo "text text0text" | ./vcipher -k key
    > divd robr0xchx

    ... because the key-text alignment is as below ...

    key:    k e y k e y k e y k e y k e
    text:   t e x t   t e x t 0 t e x t
    -----------------------------------
            d i v d   r o b r 0 x c h x

## Building

Make sure that you have [gcc](https://en.wikipedia.org/wiki/GNU_Compiler_Collection)
and [make](https://en.wikipedia.org/wiki/Make_(software)) installed on your
system. Clone this repo. Then, inside the root directory of this project, run:

    make main

This will compile a binary of this project onto the current directory. The file
will be named `vcipher`.

If you don't have or don't want to use make, you can manually build by
compiling and linking the files as listed below.

    gcc \
     main/main.c \
	 src/process_key/process_key.c \
	 src/string_transform/string_transform.c \
	 src/caesar_transform_char/caesar_transform_char.c \
	 src/get_shift_at_position/get_shift_at_position.c \
	 -o vcipher

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