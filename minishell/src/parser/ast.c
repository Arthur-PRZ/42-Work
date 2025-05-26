/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artperez <artperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 12:48:01 by artperez          #+#    #+#             */
/*   Updated: 2025/05/07 11:50:12 by artperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_token	*find_op(t_token *tokens)
{
	t_token	*res;
	t_token	*current;

	res = NULL;
	current = tokens;
	while (current)
	{
		if (current->arg_type == PIPE)
			res = current;
		if (res == NULL && (current->arg_type == INPUT_REDIRECTION
				|| current->arg_type == OUTPUT_REDIRECTION
				|| current->arg_type == HEREDOC
				|| current->arg_type == OUTPUT_REDIRECTION_APPEND))
			res = current;
		current = current->next;
	}
	return (res);
}

void	split_token(t_token **left, t_token **right,
	t_token *tokens, t_token *op)
{
	t_token	*current;

	current = NULL;
	if (!tokens || !op)
	{
		*left = NULL;
		*right = NULL;
		return ;
	}
	*left = tokens;
	while (tokens && tokens != op)
	{
		current = tokens;
		tokens = tokens->next;
	}
	if (current)
		current->next = NULL;
	*right = op->next;
	if ((*left)->str == op->str)
		*left = NULL;
	op->next = NULL;
}

static void	link_args_and_op(t_token *args, t_token *op, t_token *current)
{
	t_token	*last_arg;

	last_arg = args;
	while (last_arg && last_arg->next)
		last_arg = last_arg->next;
	last_arg->next = op;
	if (current != op)
		current->next = args;
}

t_token	*reorganize_args_after_redir(t_token *tokens, t_token *op)
{
	t_token	*file_token;
	t_token	*args;
	t_token	*current;

	if (!tokens || !op || !op->next)
		return (tokens);
	file_token = op->next;
	if (file_token && file_token->next)
	{
		args = file_token->next;
		file_token->next = NULL;
		if (tokens == op)
		{
			link_args_and_op(args, op, op);
			return (args);
		}
		current = tokens;
		while (current && current != op && current->next != op)
			current = current->next;
		if (current)
			link_args_and_op(args, op, current);
	}
	return (tokens);
}

t_tree	*ast(t_token *tokens)
{
	t_tree	*root;
	t_token	*op;
	t_token	*left;
	t_token	*right;

	if (!tokens)
		return (NULL);
	left = NULL;
	right = NULL;
	op = find_op(tokens);
	if (op == NULL)
		return (create_node(tokens));
	if (is_rdr(op->str))
		tokens = reorganize_args_after_redir(tokens, op);
	split_token(&left, &right, tokens, op);
	root = create_node(op);
	if (left)
		root->left = ast(left);
	if (right)
		root->right = ast(right);
	return (root);
}
