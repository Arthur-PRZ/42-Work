/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_heredoc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artperez <artperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 11:14:00 by artperez          #+#    #+#             */
/*   Updated: 2025/05/12 18:38:12 by ctravers42       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

bool	is_heredoc_delim(char *input, char *delim)
{
	if (!input || !delim)
		return (false);
	if (ft_strncmp(input, delim, ft_strlen(delim) + 1) == 0)
		return (true);
	return (false);
}

void	exec_heredoc(t_tree *tree, int *exit_status, t_all *all, t_env *envp)
{
	int	original_stdin;

	original_stdin = dup(STDIN_FILENO);
	if (original_stdin == -1)
	{
		*exit_status = 1;
		return ;
	}
	if (dup2(tree->heredoc_fd, STDIN_FILENO) == -1)
	{
		close(original_stdin);
		*exit_status = 1;
		return ;
	}
	close(tree->heredoc_fd);
	if (tree->left)
		exec(tree->left, exit_status, all, envp);
	dup2(original_stdin, STDIN_FILENO);
	close(original_stdin);
}

static int	check_for_signals(void)
{
	if (g_signal != 0)
	{
		rl_done = 1;
		return (1);
	}
	return (0);
}

static int	handle_heredoc_signal(char *input, t_all *all)
{
	if (g_signal != 0)
	{
		g_signal = 0;
		free(input);
		all->exit_status = 130;
		return (1);
	}
	if (!input)
	{
		ft_printf("here-document delimited by end-of-file\n");
		all->exit_status = 130;
		return (1);
	}
	return (0);
}

void	read_heredoc_loop(char *delim, int pipefd[2], t_all *all)
{
	char	*input;

	rl_catch_signals = 0;
	rl_event_hook = check_for_signals;
	while (1)
	{
		input = readline("> ");
		if (handle_heredoc_signal(input, all))
			break ;
		if (is_heredoc_delim(input, delim))
		{
			free(input);
			break ;
		}
		write(pipefd[1], input, ft_strlen(input));
		write(pipefd[1], "\n", 1);
		free(input);
	}
	rl_catch_signals = 1;
}
