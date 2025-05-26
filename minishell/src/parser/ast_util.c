/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_util.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artperez <artperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 09:30:46 by artperez          #+#    #+#             */
/*   Updated: 2025/05/12 16:47:00 by ctravers42       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	free_tree(t_tree *tree)
{
	if (!tree)
		return ;
	free_tree(tree->left);
	free_tree(tree->right);
	if (tree->token)
		free_list(&tree->token);
	(free(tree), tree = NULL);
}

t_tree	*create_node(t_token *token)
{
	t_tree	*res;

	res = malloc(sizeof(t_tree));
	res->right = NULL;
	res->left = NULL;
	res->token = token;
	res->heredoc_fd = -1;
	return (res);
}
