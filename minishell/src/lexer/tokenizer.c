/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artperez <artperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 10:32:38 by ctravers42        #+#    #+#             */
/*   Updated: 2025/04/23 10:14:56 by artperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

bool	is_valid_cmd(char *cmd)
{
	if (is_builtin(cmd))
		return (true);
	if (cmd_in_path(cmd))
		return (true);
	return (false);
}

t_type	get_redirection_type(char *str)
{
	if (ft_strncmp(str, "<", 2) == 0)
		return (INPUT_REDIRECTION);
	else if (ft_strncmp(str, ">", 2) == 0)
		return (OUTPUT_REDIRECTION);
	else if (ft_strncmp(str, ">>", 3) == 0)
		return (OUTPUT_REDIRECTION_APPEND);
	else if (ft_strncmp(str, "<<", 3) == 0)
		return (HEREDOC);
	return (0);
}

t_token	*check_pipe_redirect(t_token *token)
{
	if (token->is_env == false && ft_strncmp(token->str, "|",
			ft_strlen(token->str)) == 0)
		token->arg_type = PIPE;
	else if (token->is_env == false && is_rdr(token->str))
		token->arg_type = get_redirection_type(token->str);
	return (token);
}

t_token	*process_token(t_token **head, int *exit_status, t_all *all)
{
	all->token = check_pipe_redirect(all->token);
	all = clean_tokens(all, exit_status);
	if (all == NULL)
		return (free_list(head), NULL);
	all->token = process_clean_token(all->token);
	return (all->token);
}

t_all	*tokenizer(char *input, int *exit_status, t_all *all)
{
	t_token	*current;
	t_token	*head;

	all->token = split_list(input);
	current = all->token;
	head = all->token;
	all->exit_status = (*exit_status);
	while (current)
	{
		all->token = current;
		all->token = process_token(&head, exit_status, all);
		if (all->token == NULL)
			return (all);
		if (current && current->str[0] != '|' && !is_rdr(current->str)
			&& !is_first_cmd(head, current))
			current->arg_type = ARGS;
		current = current->next;
	}
	all->token = head;
	return (all);
}
