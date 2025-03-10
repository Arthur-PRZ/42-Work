/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artperez <artperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 10:10:50 by artperez          #+#    #+#             */
/*   Updated: 2025/03/07 09:46:14 by artperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	check_duplicate(t_list **list_a, char **tab)
{
	int		number;
	t_list	*temp;
	t_list	*i;

	temp = *list_a;
	while (temp != NULL)
	{
		number = temp->nb;
		i = temp->next;
		while (i != NULL)
		{
			if (number == i->nb)
				exit_error(list_a, tab, NULL);
			i = i->next;
		}
		temp = temp->next;
	}
}

int	ft_strlen_int(int nbr)
{
	int	i;

	i = 1;
	if (nbr < 0)
	{
		if (nbr == INT_MIN)
			return (11);
		nbr *= -1;
		i++;
	}
	if (nbr < 10)
		return (i);
	while (nbr > 9)
	{
		i++;
		nbr = nbr / 10;
	}
	return (i);
}

bool	ft_same(char *str1, char *str2)
{
	int	i;

	i = 0;
	while (str1[i] || str2[i])
	{
		if (str1[i] != str2[i])
			return (false);
		i++;
	}
	return (true);
}

char	*ft_malloc(int nbr)
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
	i = ft_strlen_int(nbr);
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
