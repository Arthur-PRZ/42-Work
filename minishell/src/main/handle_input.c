/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artperez <artperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 10:14:07 by artperez          #+#    #+#             */
/*   Updated: 2025/05/12 16:47:07 by ctravers42       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	handle_null_input(char *input)
{
	printf("exit\n");
	free(input);
}

void	process_valid_input(t_all *all)
{
	signal(SIGINT, sigint_handler_default);
	signal(SIGQUIT, sigquit_handler);
	exec(all->tree, &all->exit_status, all, all->env);
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, sigint_handler_prompt);
	if (all && all->tree && all->tree->token)
		free_list(&all->tree->token);
	if (all && all->tree)
		free_tree(all->tree);
	else if (all->token)
		free_list(&all->token);
}

int	is_valid_input(char *input)
{
	int	result;

	result = 0;
	if (input[0] != '\0' && input[skip_space(input)] != '\0')
		result = 1;
	return (result);
}

int	handle_input(t_all *all, char *input)
{
	if (is_valid_input(input))
	{
		all = tokenizer(input, &all->exit_status, all);
		if (all && all->token
			&& !errors_managements(all->token, &all->exit_status))
			all->tree = ast(all->token);
		if (input && *input)
			add_history(input);
		prepare_all_heredocs(all->tree, all);
		process_valid_input(all);
	}
	return (0);
}
