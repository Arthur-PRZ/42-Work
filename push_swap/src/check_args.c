/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artperez <artperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 10:10:50 by artperez          #+#    #+#             */
/*   Updated: 2025/03/03 16:07:41 by artperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void check_duplicate(t_list **list_a, char **tab)
{
	int		number;
	t_list *temp;
	t_list *i;
	
	temp = *list_a;
	while (temp != NULL)
	{
		number = temp->nb;
		i = temp->next;
		while (i != NULL)
		{
			if (number == i->nb)
			{
				write(2, "Error\n", 6);
				free_all(list_a, tab);
			}
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

char	*ft_itoa(int nbr)
{
	int		i;
	char	*str;
	int		s;
	int		a;

	i = 0;
	a = 0;
	i = ft_strlen_int(nbr);
	str = malloc((i + 1) * sizeof(char));
	str[i] = '\0';
	if (nbr < 0)
	{
		str[0] = '-';
		nbr = nbr * (-1);
	}
	while(nbr != 0)
	{
		s = nbr % 10;
		str[i - 1] = s + 48;
		nbr = nbr / 10;
		i--;
	}
	return (str);
}
