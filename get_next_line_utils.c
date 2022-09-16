/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnascime <cnascime@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 22:24:53 by cnascime          #+#    #+#             */
/*   Updated: 2022/09/16 17:34:57 by cnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *s1)
{
	char	*ditto;
	int		length;

	length = ft_strlen(s1) + 1;
	ditto = malloc(sizeof(*ditto) * length);
	if (ditto == NULL)
		return (NULL);
	ditto = ft_memmove(ditto, s1, length);
	return (ditto);
}

size_t	ft_strlen(const char *string)
{
	size_t	length;

	length = 0;
	if (!string)
		return (0);
	while (string[length] != '\0')
		length++;
	return (length);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*pdst;
	char	*psrc;

	pdst = (char *)dst;
	psrc = (char *)src;
	if (dst == src)
		return (dst);
	if (psrc < pdst)
	{
		while (len--)
			*(pdst + len) = *(psrc + len);
		return (dst);
	}
	while (len--)
		*pdst++ = *psrc++;
	return (dst);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1length;
	size_t	s2length;
	size_t	totallength;
	char	*superbonder;

	if (!s1 || !s2)
		return (NULL);
	s1length = ft_strlen(s1);
	s2length = ft_strlen(s2);
	totallength = s1length + s2length + 1;
	superbonder = malloc(sizeof(char) * totallength);
	if (!superbonder)
		return (NULL);
	ft_memmove(superbonder, s1, s1length);
	ft_memmove((superbonder + s1length), s2, s2length);
	superbonder[totallength - 1] = '\0';
	free ((char *)s1);
	return (superbonder);
}

char	*ft_strchr(const char *lookingfor, int character)
{
	size_t	i;

	i = 0;
	while (lookingfor[i] != '\0')
	{
		if (lookingfor[i] == (char)character)
			return ((char *)lookingfor + i);
		i++;
	}
	if (lookingfor[i] == (char)character)
		return ((char *)lookingfor + i);
	return (0);
}
