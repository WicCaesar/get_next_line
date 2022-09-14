/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnascime <cnascime@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 19:37:05 by cnascime          #+#    #+#             */
/*   Updated: 2022/09/12 06:59:51 by cnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "get_next_line.h"

/* The static function keeps whatever value is passed onto it until the program
is closed. It is by default initialised at 0, if not declared otherwise. */
char	*get_next_line(int fd)
{	
	char		*line;
	static char	*temp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	temp = reader(fd, temp); // reads file until newline or EOF
	if (!temp)
		return (NULL);
	line = reaper(temp); // slices the part before next line
	temp = rescuer(temp); // gets what was left behind
	return (line);
}

char	*reader(int fd, char *temp)
{
	char	*auxl;
	int		bytes_read;

	auxl = malloc(BUFFER_SIZE + 1);
	bytes_read = read(fd, auxl, BUFFER_SIZE);
	if (!auxl || bytes_read < 0)
		return (NULL);
	while (bytes_read > 0)
	{
		auxl[bytes_read] = '\0';
		if (!temp)
			temp = ft_strdup(auxl);
		else
			temp = ft_strjoin(temp, auxl);
		if (ft_strchr(auxl, '\n')) // se encontrar \n, para de ler
			break ;
		bytes_read = read(fd, auxl, BUFFER_SIZE); // se não encontrar, continua lendo - CORTAR?
	}
	free(auxl);
	return (temp); // free(temp)
}
/* Uses read(fd, *buffer, nbytes) to add characters to the stash. */
// Aloca memória para o buffer (auxl) malloc + tratamentos de erro
// Enquanto não encontrar o \n ou o EOF && enquanto byte (?) for maior que 0
// byte = read
// Se o retorno de read (agora passado para byte) for -1, libera o buffer e retorna NULL
// Coloca o \0 no final do buffer
// Concatena o temp com buffer (auxl)

/* Adds the content of our buffer to the end of our stash. */
// 



/* Extracts all characters from our stash and stores them in our line
stopping after the first /n it encounters. */
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

/* After extracting the line that was read, we don't need those characters. */
char	*rescuer(char *temp)
{
	char	*auxl;
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
	auxl = malloc(sizeof(char) * (ft_strlen(temp) - i + 1));
	if (!auxl)
		return (NULL);
	i++;
	j = 0;
	while (temp[i] != '\0')
		auxl[j++] = temp[i++];
	auxl[j] = '\0';
	free(temp);
	return (auxl);
}
