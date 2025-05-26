/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artperez <artperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 10:35:33 by artperez          #+#    #+#             */
/*   Updated: 2025/05/02 10:40:45 by artperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include <limits.h>

char	*get_env_value(t_env *env, const char *key)
{
	while (env)
	{
		if (ft_strcmp(env->key, key) == 0)
			return (env->value);
		env = env->next;
	}
	return (NULL);
}

int	ft_int_strlen(int nbr)
{
	int	i;

	i = 1;
	if (nbr == 0)
		return (1);
	if (nbr < 0)
	{
		nbr *= -1;
		i++;
	}
	if (nbr < 10)
		return (i);
	while (nbr > 10)
	{
		i++;
		nbr = nbr / 10;
	}
	return (i);
}

static char	*ft_malloc(int nbr)
{
	char	*str;

	if (nbr == 0)
	{
		str = ft_calloc(2, sizeof(char));
		if (str == NULL)
			return (NULL);
		str[0] = '0';
		return (str);
	}
	else if (nbr == INT_MIN)
	{
		str = ft_calloc(12, sizeof(char));
		if (str == NULL)
			return (NULL);
		str = "-2147483648";
		return (str);
	}
	return (NULL);
}

char	*ft_itoa(int nbr)
{
	int		i;
	char	*str;
	int		s;

	i = 0;
	i = ft_int_strlen(nbr);
	if (nbr == 0)
		return (ft_malloc(nbr));
	if (nbr == INT_MIN)
		return (ft_strdup("-2147483648"));
	str = malloc((i + 1) * sizeof(char));
	str[i] = '\0';
	if (nbr < 0)
	{
		str[0] = '-';
		nbr = nbr * (-1);
	}
	while (nbr != 0)
	{
		s = nbr % 10;
		str[i - 1] = s + 48;
		nbr = nbr / 10;
		i--;
	}
	return (str);
}
