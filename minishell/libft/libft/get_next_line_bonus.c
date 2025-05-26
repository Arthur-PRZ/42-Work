/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artperez <artperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 10:11:32 by ctravers          #+#    #+#             */
/*   Updated: 2025/05/06 10:59:22 by artperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/get_next_line_bonus.h"

char	*ft_readline(int fd, char *buffer)
{
	char		*temp_buf;
	ssize_t		readbytes;

	readbytes = 1;
	temp_buf = ft_calloc_gnl((BUFFER_SIZE + 1), sizeof(char));
	if (temp_buf == NULL)
		return (NULL);
	if (!buffer)
	{
		buffer = ft_calloc_gnl(1, sizeof(char));
		if (buffer == NULL)
			return (free(temp_buf), free(buffer), NULL);
	}
	while (readbytes > 0)
	{
		readbytes = read(fd, temp_buf, BUFFER_SIZE);
		if (readbytes < 0)
			return (free(buffer), free(temp_buf), NULL);
		temp_buf[readbytes] = '\0';
		buffer = ft_free_gnl(buffer, temp_buf);
		if (!buffer || ft_strchr_gnl(buffer, '\n'))
			break ;
	}
	free(temp_buf);
	return (buffer);
}

char	*ft_free_gnl(char *buffer, char *temp_buf)
{
	char	*temp;

	temp = ft_strjoin_gnl(buffer, temp_buf);
	if (!temp)
	{
		free(buffer);
		free(temp_buf);
		return (NULL);
	}
	free(buffer);
	return (temp);
}

char	*ft_getline(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] != '\0' && buffer[i] != '\n')
		i++;
	line = ft_calloc_gnl((i + 2), sizeof(char));
	if (line == NULL)
		return (NULL);
	i = 0;
	while (buffer[i] != '\0' && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
		line[i] = '\n';
	return (line);
}

char	*update_buffer(char *buffer)
{
	int		i;
	int		j;
	char	*new_buffer;

	i = 0;
	j = 0;
	while (buffer[i] != '\0' && buffer[i] != '\n')
		i++;
	if (!buffer[i])
		return (free(buffer), NULL);
	new_buffer = ft_calloc_gnl((ft_strlen_gnl(buffer + i, 1) + 2),
			sizeof(char));
	if (new_buffer == NULL)
		return (NULL);
	i++;
	while (buffer[i + j])
	{
		new_buffer[j] = buffer[i + j];
		j++;
	}
	new_buffer[j] = '\0';
	free(buffer);
	return (new_buffer);
}

char	*get_next_line(int fd)
{
	char			*line;
	static char		*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = ft_readline(fd, buffer);
	if (ft_strlen_gnl(buffer, 0) == 0)
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	line = ft_getline(buffer);
	if (line == NULL)
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	buffer = update_buffer(buffer);
	free(buffer);
	buffer = NULL;
	return (line);
}
