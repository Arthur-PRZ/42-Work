/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artperez <artperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 10:15:34 by ctravers          #+#    #+#             */
/*   Updated: 2025/05/06 10:59:14 by artperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/get_next_line_bonus.h"

void	*ft_calloc_gnl(size_t nmemb, size_t size)
{
	void	*tab;
	size_t	i;

	i = 0;
	if (nmemb != 0 && size > SIZE_MAX / nmemb)
		return (NULL);
	tab = malloc(nmemb * size);
	if (tab == 0)
	{
		tab = NULL;
		return (tab);
	}
	while (i < nmemb * size)
	{
		((char *)tab)[i] = 0;
		i++;
	}
	return (tab);
}

int	ft_strlen_gnl(char *str, int a)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	if (a == 1)
	{
		while (str[i] != '\0')
			i++;
	}
	else if (a == 0)
	{
		while (str[i] != '\0' && (i == 0 || str[i - 1] != '\n'))
			i++;
	}
	return (i);
}

int	ft_strchr_gnl(char *str, char c)
{
	int	i;

	i = 0;
	if (str[0] == c)
		return (1);
	while (str[i] != '\0' && str[i] != c)
	{
		i++;
		if (str[i] == c)
			return (1);
	}
	return (0);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		a;

	i = 0;
	a = 0;
	if (s1 == NULL && s2 == NULL)
		return (NULL);
	str = ft_calloc_gnl(ft_strlen_gnl(s2, 1) + ft_strlen_gnl(s1, 1) + 1,
			sizeof(char));
	if (str == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[a] != '\0')
	{
		str[i] = s2[a];
		i++;
		a++;
	}
	str[i] = '\0';
	return (str);
}
