# get_next_line

## a function that returns a line read from a file descriptor

*“Line” is a succession of characters that end with ’\n’ (ascii code 0x0a) or with End Of File (EOF).*

* The first parameter is the file descriptor that will be used to read.
* The second parameter is the address of a pointer to a character that will be used
to save the line read from the file descriptor.
* The return value can be 1, 0 or -1 depending on whether a line has been read,
when the reading has been completed, or if an error has happened respectively.
* Function return its result without ’\n’.
* Calling function in a loop will then allow to read the text
available on a file descriptor one line at a time until the end of the text, no matter
the size of either the text or one of its lines.