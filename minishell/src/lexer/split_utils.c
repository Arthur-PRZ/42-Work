/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artperez <artperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 10:05:58 by artperez          #+#    #+#             */
/*   Updated: 2025/04/11 09:05:08 by artperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*
	Fonction use : malloc
	Used by : split_list
	Description : Create a new node and add the str send to the str 
		of the struct.
	Fonction operation : Malloc the node and initializing all variables
		of the struct.
	Return value : t_token *.
*/
t_token	*lstnew_ms(void *str)
{
	t_token	*list;

	list = malloc(sizeof(t_token));
	if (list == NULL)
		return (NULL);
	list->str = str;
	list->arg_type = TYPE_UNKNOW;
	list->next = NULL;
	list->is_clean = false;
	list->is_env = false;
	return (list);
}

/*
	Fonction use : malloc
	Used by : split_list
	Description : Malloc a new str with int i as the size of the str
		and adding the char c of the str sended in the new one.
	Fonction operation : Malloc the new str with the size of i and then fill it
		with the str sended
	Return value : char *.
*/
char	*strndup_ms(const char *s, int i)
{
	char	*dest;
	int		a;

	a = 0;
	dest = malloc((i + 1) * sizeof(char));
	if (dest == 0)
		return (0);
	while (a < i)
	{
		dest[a] = s[a];
		a++;
	}
	dest[a] = '\0';
	return (dest);
}

/*
	Fonction use : None
	Used by : split_list
	Description : skip spaces;
	Fonction operation : loop while char = ' ';
	Return value : int.
*/
int	skip_space(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	return (i);
}

/*
	Fonction use : None
	Used by : split_list
	Description : if it is a separator return true, if not return false;
	Fonction operation : if it is a separator return true, if not return false;
	Return value : bool.
*/
bool	separator(char c)
{
	if (c == '<' || c == '>' || c == '|' || c == ' ')
		return (true);
	return (false);
}
