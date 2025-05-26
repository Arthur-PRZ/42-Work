/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artperez <artperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 12:32:55 by artperez          #+#    #+#             */
/*   Updated: 2025/04/03 12:22:26 by ctravers42       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*
	Use fonctions : None.
	Used by : split_list.
	Description :  browse the str for having the good size to malloc for strndup
	Function operation : browse the str while the char is '\0', '<', '>', '|'
		allowing to strdup to have the good size for malloc exemple : 
		str = ">> nullos.txt"   str = "> nullos.txt"
				i++						i++
		returning 2 for strdup that malloc two for >>;
	Return value : int
*/
int	get_str_size_redirection(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && (str[i] == '<' || str[i] == '>' || str[i] == '|'))
		i++;
	return (i);
}

/*
	Use fonctions : None.
	Used by : split_list.
	Description :  browse the str for having the good size to malloc for strndup
	Function operation : browse the str while the char is '\0', '<', '>', '|'
		allowing to strdup to have the good size for malloc exemple : 
		str = "echo hello >> nullos.txt" ....  str = " hello >> nullos.txt"
				i++						           str[i] = ' ' so stop
		returning 4 for strdup that malloc four for echo;
	Return value : int
*/
int	get_str_size(char *str)
{
	int	i;

	i = 0;
	while (separator(str[i]) == false && str[i] != '\0')
	{
		if (str[i] == '\"' || str[i] == '\'')
		{
			i++;
			while (str[i] != '\0' && str[i] != '\"' && str[i] != '\'')
			{
				i++;
			}
		}
		if (str[i] != '\0')
			i++;
	}
	return (i);
}

/*
	Use fonctions : skip_space, lstnew_ms, strndup_ms_args_cmd, strndup_ms
		get_str_size, get_str_size_redirection, get_str_size_quote.
	Used by :
	Description : Split the str return by readline in nodes in a chained list.
	Function operation : The function use one int 
		to browse list str by str and it allow to strdup in a the str of 
		the nodes at the right place(a), exemple :
		str : "Hello world"
					[a]
		a send "world" to strdnup. And i do that in a while that end 
		when the str is '\0' and a current->next that allow me to create nodes.
	Return value : t_token *.
*/
t_token	*split_list(char *str)
{
	t_token	*list;
	t_token	**current;
	int		a;

	current = &list;
	a = skip_space(str);
	while (str[a] != '\0')
	{
		if ((str[a] == '<' || str[a] == '>' || str[a] == '|'))
		{
			*current = lstnew_ms(strndup_ms(str + a,
						get_str_size_redirection(str + a)));
			current = &((*current)->next);
			a = a + get_str_size_redirection(str + a);
			a = a + skip_space(str + a);
		}
		else
		{
			*current = lstnew_ms(strndup_ms(str + a, get_str_size(str + a)));
			current = &((*current)->next);
			a = a + get_str_size(str + a);
			a = a + skip_space(str + a);
		}
	}
	return (list);
}
