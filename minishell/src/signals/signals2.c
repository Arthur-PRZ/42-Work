/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artperez <artperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 10:53:12 by artperez          #+#    #+#             */
/*   Updated: 2025/05/12 17:23:44 by ctravers42       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	signal_heredoc_setup(int signum)
{
	g_signal = signum;
	write(1, "^C", 2);
}

void	signal_heredoc_stop(int signum)
{
	g_signal = signum;
	write(1, "\n", 1);
}

void	set_sigint_heredoc(void)
{
	struct sigaction	sa;

	sa.sa_handler = signal_heredoc_setup;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sigaction(SIGINT, &sa, NULL);
	signal(SIGQUIT, signal_heredoc_stop);
}
