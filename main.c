#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int	main()
{
	int fd = open("testfile", O_RDONLY);
	int	i;

	i = 0;
	while (i < 2)
	{
		char *ptr = get_next_line(fd);
		printf("%s", ptr);
		//printf("%s = %p\n", ptr, ptr);
		i++;
	}
}

