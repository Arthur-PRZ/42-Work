/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artperez <artperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 14:25:26 by artperez          #+#    #+#             */
/*   Updated: 2024/11/22 13:18:07 by artperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3
#endif

char	*get_next_line(int fd);
int		ft_strlen(char *str);
char	*ft_strcpy(char *dest, char *src);
int		ft_strchr(char *str, char c);
char	*ft_getline(int fd, char *buffer);
char	*ft_getline_n(char *buffer);
char	*ft_strjoin(char *s1, char *s2);

#endif