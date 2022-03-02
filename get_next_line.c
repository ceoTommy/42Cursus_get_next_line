/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tford <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 12:36:41 by tford             #+#    #+#             */
/*   Updated: 2022/03/02 12:48:52 by tford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static size_t	line_len(char *str);

//returns upto end of line or the null
//changes remainder to the remainding left
static char	*line_move(char **rem)
{
	size_t	len;
	char	*line;
	char	*tmp;

	if (*rem == NULL)
		return (NULL);
	if (**rem == '\0')
	{
		free(*rem);
		return (NULL);
	}
	len = line_len(*rem);
	line = (char *) ft_calloc(len + 1, sizeof(char));
	if (line == NULL)
	{
		return (NULL);
	}
	ft_strlcpy(line, *rem, len + 1);
	tmp = *rem;
	*rem = ft_strjoin(NULL, tmp + len);
	free(tmp);
	return (line);
}

//returns string length until a (inclusive)\n or (exclusive)\0
static size_t	line_len(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
		{
			i++;
			break ;
		}
		i++;
	}
	return (i);
}

//returns true if the string has a /n in it
static int	str_is_line(char *str)
{
	if (str == NULL)
		return (0);
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

//reads a read_size amount from a fd
//returns a new string of (src + read)
static char	*read_join(int fd, const char *src, int read_size)
{
	char	*buf_str;
	char	*joined;

	buf_str = (char *) ft_calloc(read_size + 1, sizeof(char));
	if (buf_str == NULL)
		return (NULL);
	if (read(fd, buf_str, read_size) <= 0)
	{
		free(buf_str);
		return (NULL);
	}
	joined = ft_strjoin(src, buf_str);
	free(buf_str);
	return (joined);
}

//returns gets the next line from the file
//until no lines left then it returns null
//has a static remainder variable which holds the left over
char	*get_next_line(int fd)
{
	static char	*remainder;
	char		*tmp;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		return (NULL);
	}
	while (!str_is_line(remainder))
	{
		tmp = read_join(fd, remainder, BUFFER_SIZE);
		if (tmp == NULL)
		{
			break ;
		}
		if (remainder != NULL)
			free(remainder);
		remainder = tmp;
	}
	return (line_move(&remainder));
}
