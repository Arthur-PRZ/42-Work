/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artperez <artperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 12:06:22 by ctravers42        #+#    #+#             */
/*   Updated: 2025/04/24 13:41:28 by artperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	skip_quotes(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i] && (str[i] == '\'' || str[i] == '\"'))
		i++;
	return (i);
}

int	skip_simples_quotes(char *str)
{
	int	i;

	i = 0;
	while (str[i] && (str[i] == '\''))
		i++;
	return (i);
}

void	free_list(t_token **tokens)
{
	t_token	*current;
	t_token	*next;

	current = *tokens;
	next = current->next;
	while (current)
	{
		if (next != NULL)
			next = current->next;
		free(current->str);
		free(current);
		current = next;
	}
	*tokens = NULL;
}

int	is_rdr(char *input)
{
	return (ft_strncmp(input, "<", ft_strlen(input)) == 0
		|| ft_strncmp(input, ">", ft_strlen(input)) == 0
		|| ft_strncmp(input, ">>", ft_strlen(input)) == 0
		|| ft_strncmp(input, "<<", ft_strlen(input)) == 0);
}

bool	check_env_paths_part1(char *path_env, char **path_copy_ptr)
{
	char	*path_copy;

	path_copy = ft_strdup(path_env);
	if (!path_copy)
		return (false);
	*path_copy_ptr = path_copy;
	return (true);
}
