/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tford <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 10:08:03 by tford             #+#    #+#             */
/*   Updated: 2022/02/20 14:46:49 by tford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

void	*ft_bzero(void *b, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
		((unsigned char *) b)[i++] = 0;
	return (b);
}

void	*ft_calloc(size_t n_blocks, size_t size)
{
	void	*p;

	p = malloc(n_blocks * size);
	if (p != NULL)
	{
		ft_bzero(p, n_blocks * size);
	}
	return (p);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	if (str == NULL)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*p;
	size_t	i;
	size_t	j;

	i = ft_strlen(s1) + ft_strlen(s2);
	p = (char *) malloc((i + 1) * sizeof(char));
	if (p == NULL)
	{
		return (NULL);
	}
	i = 0;
	while (s1 != NULL && s1[i])
	{
		p[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		p[i + j] = s2[j];
		j++;
	}
	p[i + j] = '\0';
	return (p);
}
