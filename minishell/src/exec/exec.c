/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artperez <artperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 10:29:51 by artperez          #+#    #+#             */
/*   Updated: 2025/05/07 13:00:43 by artperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_env	*create_node_env(char *key, char *value)
{
	t_env	*node;

	node = malloc(sizeof(t_env));
	if (!node)
		return (NULL);
	node->key = ft_strdup(key);
	node->value = ft_strdup(value);
	node->full_str = get_full_str(node->key, node->value);
	node->next = NULL;
	return (node);
}

char	**create_args(t_token *token)
{
	t_token	*current;
	char	**res;
	int		i;
	int		j;

	i = 1;
	current = token->next;
	while (current && current->arg_type != PIPE && !is_rdr(current->str))
	{
		i++;
		current = current->next;
	}
	current = token->next;
	res = malloc((i + 1) * sizeof(char *));
	res[0] = ft_strdup(token->str);
	j = 1;
	while (j < i && current && current->arg_type != PIPE
		&& !is_rdr(current->str))
	{
		res[j] = ft_strdup(current->str);
		current = current->next;
		j++;
	}
	res[i] = NULL;
	return (res);
}

int	count_env(t_env *envp)
{
	int	count;

	count = 0;
	while (envp)
	{
		count++;
		envp = envp->next;
	}
	return (count);
}

char	**create_tab(t_env *envp)
{
	char	**envc;
	int		i;
	int		count;

	i = 0;
	count = count_env(envp);
	envc = malloc(sizeof(char *) * (count + 1));
	if (!envc)
		return (NULL);
	while (envp)
	{
		envc[i] = ft_strdup(envp->full_str);
		if (!envc[i])
		{
			while (--i >= 0)
				free(envc[i]);
			free(envc);
			return (NULL);
		}
		i++;
		envp = envp->next;
	}
	envc[i] = NULL;
	return (envc);
}

void	exec(t_tree *tree, int *exit_status, t_all *all, t_env *envp)
{
	if (!tree)
		return ;
	if (tree->token->arg_type == PIPE)
		exec_pipe(tree, all, envp);
	else if (tree->token->arg_type == OUTPUT_REDIRECTION_APPEND)
		exec_append_mode(tree, exit_status, all, envp);
	else if (tree->token->arg_type == HEREDOC)
		exec_heredoc(tree, exit_status, all, envp);
	else if (tree->token->arg_type == OUTPUT_REDIRECTION)
		exec_output_redirection(tree, exit_status, all, envp);
	else if (tree->token->arg_type == INPUT_REDIRECTION)
		exec_input_redirection(tree, exit_status, all, envp);
	else if (is_builtin(tree->token->str) == true)
		which_builtin(tree, exit_status, all, envp);
	else
		do_cmd(tree, exit_status, envp, all);
}
