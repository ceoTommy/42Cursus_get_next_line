/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tford <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 15:05:30 by tford             #+#    #+#             */
/*   Updated: 2022/03/01 15:14:32 by tford            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>

//	main fuctionality files	//
char	*get_next_line(int fd);

//	utils, can be replaced with libft //
void	*ft_calloc(size_t n_blocks, size_t size);
size_t	ft_strlen(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
void	*ft_bzero(void *b, size_t len);

#endif
