/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnascime <cnascime@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 19:42:39 by cnascime          #+#    #+#             */
/*   Updated: 2022/09/17 15:04:02 by cnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
char	*reader(int fd, char *temp);
char	*reaper(char *temp);
char	*rescuer(char *temp);
char	*ft_strjoin(char *statik, char *buffer);
size_t	ft_strlen(const char *string);
char	*ft_strchr(const char *lookingfor, int character);

#endif