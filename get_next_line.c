/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tford <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 10:07:00 by tford             #+#    #+#             */
/*   Updated: 2022/02/20 14:56:54 by tford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

//returns up to line end, then changes remainder to start at line end
static char	*adjust_line(char **rem)
{
	size_t	len;
	size_t	j;
	char	*line;
	char	*tmp;

	len = 0;
	if (*rem == NULL || **rem == '\0')
	{
		return (NULL);
	}
	while ((*rem)[len] != '\n' && (*rem)[len] != '\0')
		len++;
	if ((*rem)[len] == '\n')
		len++;
	line = (char *) ft_calloc(len + 1, sizeof(char));
	if (line == NULL)
		return (NULL);
	j = 0;
	while (j < len)
	{
		line[j] = (*rem)[j];
		j++;
	}
	tmp = *rem;
	*rem = ft_strjoin(NULL, tmp + len);
	if (*rem == NULL)
		return (NULL);
	free (tmp);
	return (line);
}

static int	str_isline(char *str)
{
	if (str == NULL)
	{
		return (0);
	}
	while (*str)
	{
		if (*str == '\n')
		{
			return (1);
		}
		str++;
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static char	*remainder;
	char		*buf_str;
	char		*tmp;
	ssize_t		read_return;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf_str = (char *) ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (buf_str == NULL)
		return (NULL);
	while (!str_isline(remainder))
	{
		read_return = read(fd, buf_str, BUFFER_SIZE);
		if (read_return == -1)
		{
			free(buf_str);
			return (NULL);
		}
		if (read_return == 0)
			break;
		buf_str[read_return] = '\0';
		tmp = remainder;
		remainder = ft_strjoin(tmp, buf_str);
		if (tmp != NULL)
			free(tmp);
	}
	//free(buf_str);
	return (adjust_line(&remainder));
}

#include <fcntl.h>
#include <stdio.h>
int	main()
{
	int fd = open("testfile", O_RDONLY);
	int	i;

	i = 0;
	while (i < 12)
	{
		char *ptr = get_next_line(fd);
		printf("%s", ptr);
		//printf("%s = %p\n", ptr, ptr);
		i++;
	}
	_CrtDumpMemoryLeaks();
}