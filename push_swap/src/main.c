/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artperez <artperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 10:23:10 by artperez          #+#    #+#             */
/*   Updated: 2025/02/04 11:30:31 by artperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_taking_list(char **argv, t_list_a *list_a, int argc)
{
	int	a;
	char	**tab;
	
	a = 0;
	tab = ft_split(argv[1], ' ');
	if (tab == NULL)
		return ;
	ft_lstnew();
	if (argc == 2)
	{
		list_a = ft_lstnew(ft_atoi(argv[1]));
		return ;
	}
	while (argv[a])
	{
		if (a == 0)
			ft_lstnew(ft_atoi(argv[1]));
		list_a->a = ft_atoi(argv[a]);
		list_a = list_a->next;
		a++;
	}
} 

int	main(int argc, char **argv)
{
	t_list_a list_a;

	if (argc == 1)
		return (0);
	ft_taking_list(argv, &list_a, argc);
}