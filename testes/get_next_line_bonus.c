/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnascime <cnascime@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 19:37:05 by cnascime          #+#    #+#             */
/*   Updated: 2022/09/16 17:34:58 by cnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* The static function keeps whatever value is passed onto it until the program
is closed. It is by default initialised at 0, if not declared otherwise. */
char	*get_next_line(int fd)
{	
	char		*line;
	static char	*temp[1024];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	temp[fd] = reader(fd, temp[fd]);
	if (!temp[fd])
		return (NULL);
	line = reaper(temp[fd]);
	temp[fd] = rescuer(temp[fd]);
	return (line);
}

char	*reader(int fd, char *temp)
{
	char	*auxiliary;
	int		bytes_read;

	auxiliary = malloc(BUFFER_SIZE + 1);
	bytes_read = read(fd, auxiliary, BUFFER_SIZE);
	if (!auxiliary || bytes_read < 0)
		return (NULL);
	while (bytes_read > 0)
	{
		auxiliary[bytes_read] = '\0';
		if (!temp)
			temp = ft_strdup(auxiliary);
		else
			temp = ft_strjoin(temp, auxiliary);
		if (ft_strchr(auxiliary, '\n'))
			break ;
		bytes_read = read(fd, auxiliary, BUFFER_SIZE); // se não encontrar \n, continua lendo - CORTAR?
	}
	free(auxiliary);
	return (temp);
}

char	*reaper(char *temp)
{
	char	*line;
	int		i;

	i = 0;
	while (temp[i] != '\n' && temp[i] != '\0')
		i++;
	line = malloc(sizeof(char) * (i + 1)); // i + 2? para o \n e o \0?
	if (!line)
		return (NULL);
	i = 0;
	while (temp[i] != '\n' && temp[i] != '\0')
	{
		line[i] = temp[i];
		i++;
	} // talvez aqui precise verificar se tem \n e copiar antes do \0
	line[i] = '\0';
	return (line);
}

char	*rescuer(char *temp)
{
	char	*auxiliary;
	int		i;
	int		j;

	i = 0;
	while (temp[i] != '\n' && temp[i] != '\0')
		i++;
	if (temp[i] == '\0')
	{
		free(temp);
		return (NULL);
	}
	auxiliary = malloc(sizeof(char) * (ft_strlen(temp) - i + 1));
	if (!auxiliary)
		return (NULL);
	i++;
	j = 0;
	while (temp[i] != '\0')
		auxiliary[j++] = temp[i++];
	auxiliary[j] = '\0';
	free(temp);
	return (auxiliary);
}
