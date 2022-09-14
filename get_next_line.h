/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnascime <cnascime@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 19:42:39 by cnascime          #+#    #+#             */
/*   Updated: 2022/09/12 03:30:58 by cnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 23
# endif

char	*get_next_line(int fd);
char	*reader(int fd, char *temp);
char	*reaper(char *temp);
char	*rescuer(char *temp);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *string);
void	*ft_memmove(void *dst, const void *src, size_t len);
char	*ft_strchr(const char *lookingfor, int character);
#endif