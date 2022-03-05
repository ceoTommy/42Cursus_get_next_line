# Get_next_line
### Now included in my Libft libary
`char * get_next_line(int fd)`
## Functionality
Returns a string given a file descriptor. This function can be repeatadly used to continuously return the next lines in the file. To get the file descriptor (fd) use the [open](https://man7.org/linux/man-pages/man2/open.2.html) function found in the *fcntl.h* system libary.

To read the next lines on every function call a static variables is used. All memory is free'd once get_next_line reaches the end of file in which it will return NULL.

## Limitations
Undefined return with alternaing file discriptors, NULL must be a return before changing file descriptors

Only handles ascii decimal characters.

## Use
1. Clone the project into your working directory
2. `#include "get_next_line.h` as a header in your C program
3. Use the function in your program `get_next_line(int fd)`
4. Compile get_next_line.c, get_next_line_utils.c and your program

## 42_GRADE
🟢 PASSED WITH 100%
