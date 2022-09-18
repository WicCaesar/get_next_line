/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnascime <cnascime@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 13:52:47 by cnascime          #+#    #+#             */
/*   Updated: 2022/09/17 15:34:29 by cnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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

char	*ft_strjoin(char *statik, char *buffer)
{
	size_t	i;
	size_t	j;
	char	*superbonder;

	if (!statik)
	{
		statik = malloc(1 * sizeof(char));
		statik[0] = '\0';
	}
	if (!buffer)
		return (NULL);
	superbonder = malloc(1 * ((ft_strlen(statik) + ft_strlen(buffer)) + 1));
	if (!superbonder)
		return (NULL);
	i = -1;
	j = 0;
	if (statik)
		while (statik[++i] != '\0')
			superbonder[i] = statik[i];
	while (buffer[j] != '\0')
		superbonder[i++] = buffer[j++];
	superbonder[ft_strlen(statik) + ft_strlen(buffer)] = '\0';
	free (statik);
	return (superbonder);
}

char	*ft_strchr(const char *lookingfor, int character)
{
	size_t	i;

	i = 0;
	if (!lookingfor)
		return (0);
	if (character == '\0')
		return ((char *)&lookingfor[ft_strlen(lookingfor)]);
	while (lookingfor[i] != '\0')
	{
		if (lookingfor[i] == (char)character)
			return ((char *)lookingfor + i);
		i++;
	}
	return (0);
}