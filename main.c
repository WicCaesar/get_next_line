/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnascime <cnascime@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 14:11:15 by jocardos          #+#    #+#             */
/*   Updated: 2022/09/16 17:36:18 by cnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
// #include "get_next_line_bonus.h"
#include <stdio.h>
#include <fcntl.h>

// Main para a parte bônus
/*int main(int argc, char **argv)
{
	char	*line;
	int		i;
	int		fd;
	int		count;

	if (argc < 2)
		return (0);
	count = 1;
	printf("\n============================================================================================================================================\n");
	printf("                                                            PRIMEIRO ARQUIVO                                                                  ");
	printf("\n============================================================================================================================================\n");
	printf("\n");
	while(count < argc)
	{
		fd = open(argv[count++], O_RDONLY);
		i = 1;
		while (i < 3000)
		{
			line = get_next_line(fd);
			printf("Linha [%02d]: %s\n", i, line);
			free(line);
			i++;
			if (line == NULL)
				break;
		}
		close(fd);
		if (argc != count)
		{
		printf("\n============================================================================================================================================\n");
		printf("                                                             PRÓXIMO ARQUIVO                                                                  ");
		printf("\n============================================================================================================================================\n");
		printf("\n");
		}
	}
}*/

// Main somente para a parte obrigatória
int	main(void)
{
	char	*line;
	int		i;
	int		fd;

	i = 0;
	// fd = open("testes/teste7", O_RDONLY); // Aqui é só alterar o número do arquivo que deseja testar
	fd = open("gibberish.txt", O_RDONLY);
	while (i < 15)
	{
		line = get_next_line(fd);
		printf("%04d: %s \n", i, line);
		free(line);
		i++;
	}
	close(fd);
}
