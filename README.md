# Get_next_line
## Functionality
'get_next_line(int fd)' returns a line given a file descriptor. This function can be repeatadly used to continuously return the next lines in the file. To get the file descriptor (fd) use the "open" function found in the "fcntl.h" system libary.

To read the next lines on every function call a static variables is used. All memory is free'd once get_next_line reaches the end of file in which it will return NULL.

## Setup
'#include "get_next_line.h'

PASSED WITH 100%
