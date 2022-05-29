/**
 * Contains code to transform uppercase ASCII characters to another one based
 * on a Caesar cipher shift value.
 * (c) Yuta Nagano
 */

char caesar_transform_char(char c, int shift)
{
    int offset;

    // If the character is upper case, transform accordingly
    if ((c >= 'A') && (c <= 'Z')) {
        offset = c - 'A' + 26;
        offset = (offset + shift) % 26;
        return 'A' + offset;
    }
    // If the character is lower case, transform accordingly
    if ((c >= 'a') && (c <= 'z')) {
        offset = c - 'a' + 26;
        offset = (offset + shift) % 26;
        return 'a' + offset;
    }
    // If the character is not alphabetic, it is not transformed
    return c;
}