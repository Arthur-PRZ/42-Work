/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artperez <artperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 13:36:09 by artperez          #+#    #+#             */
/*   Updated: 2024/11/22 13:56:48 by artperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_getline(int fd, char *buffer)
{
	char		*buf;
	ssize_t		readbytes;

	readbytes = 1;
	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
	{
		buffer = malloc(1);
		if (!buffer)
			return (NULL);
		buffer[0] = '\0';
	}
	while (readbytes > 0)
	{
		readbytes = read(fd, buf, BUFFER_SIZE);
		if (readbytes < 1)
			return (NULL);
		buffer = ft_strjoin(buffer, buf);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (buffer);
}

char	*ft_getline_n(char *buffer)
{
	char	*line;
	
	line = malloc((ft_strlen(buffer) + 1) * sizeof(char));
	line = ft_strcpy(line, buffer);
	return (line);
}

char	*get_next_line(int fd)
{
	char			*line;
	static char		*buffer;
	int				len;

	len = 1;
	buffer = ft_getline(fd, buffer);
	line = ft_getline_n(buffer);
	return (line);
}

int	main()
{
	int	file;
	char *str;

	file = open("/home/artperez/Stud/exercices/get_next_line/test.txt", O_RDONLY);
	if (file == -1)
	{
		printf("t'as pas reussi a ouvrir le fichier nullos");
		return (0);
	}
	str = malloc(10000 * sizeof(char));
	str = get_next_line(file);
	printf("%s", str);
	close(file);
	free(str);
}