/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tford <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 10:07:00 by tford             #+#    #+#             */
/*   Updated: 2022/02/07 17:52:09 by tford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>

//remove me
#include <stdio.h>

//returns up to line end, then changes remainder to start at line end
static char	*adjust_line(char **remainder)
{
	size_t	i;
	size_t	j;
	char	*line;

	i = 0;
	while((*remainder)[i] != '\n')
		i++;
	i++;
	line = (char *) ft_calloc(i + 1, sizeof(char));
	if (line == NULL)
		return (NULL);
	j = 0;
	while (j < i)
	{
		line[j] = (*remainder)[j];
		j++;
	}
	*remainder = *remainder + i;
	return (line);
}

static int	str_isline(char *str)
{
	if (str == NULL)
		return (0);
	while (*str != '\n')
	{
		if (*str == '\0')
		{
			return (0);
		}	
		str++;
	}
	return (1);
}

char	*get_next_line(int fd)
{
	static char	*remainder;
	char		*buf_str;
	char		*tmp;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		return (NULL);
	}
	buf_str = (char *) ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (buf_str == NULL)
	{
		return (NULL);
	}
	while (!str_isline(remainder))
	{
		if (read(fd, buf_str, BUFFER_SIZE) < 0)
			return (NULL);
		tmp = ft_strjoin(remainder, buf_str);
		//free(buf_str);
		remainder = tmp;
	}
	return (adjust_line(&remainder));
}

#include <fcntl.h>
#include <stdio.h>
int main(int ac, char **av)
{
	int fd = open(av[1], O_RDONLY);
	int	i;

	if (ac <= 1)
		printf("include file");
	i = 0;
	while (i < 3)
	{
		printf("[%s]", get_next_line(fd));
		i++;
	}
}
