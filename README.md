# Get_next_line
## Functionality
`get_next_line(int fd)` returns a line given a file descriptor. This function can be repeatadly used to continuously return the next lines in the file. To get the file descriptor (fd) use the [open](https://man7.org/linux/man-pages/man2/open.2.html) function found in the *fcntl.h* system libary.

To read the next lines on every function call a static variables is used. All memory is free'd once get_next_line reaches the end of file in which it will return NULL.

## Limitations
Won't handle different file discriptors as inputs throught the program until NULL is returned

Only handles ascii decimal characters.

## Use
1. Clone the project into your working directory 1
2. `#include "get_next_line.h` as a header in your C program 2
3. Use the funstion in your program `get_next_line(int fd)` 3
4. Compile get_next_line.c, get_next_line_utils.c and your program 4

### 42 Info
PASSED WITH 100%

42 GRADS: 100%
{: .alert .alert-success}
