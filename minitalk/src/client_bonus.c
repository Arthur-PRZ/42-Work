/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artperez <artperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 09:15:39 by artperez          #+#    #+#             */
/*   Updated: 2025/03/12 10:31:02 by artperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk_bonus.h"

volatile sig_atomic_t	g_sending = NOT_READY;

void	next_handler(int signum)
{
	(void)signum;
	g_sending = READY;
}

void	end_handler(int signum)
{
	(void)signum;
	ft_printf("Message received\n");
	exit (EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	int	i;
	int	pid;

	i = 0;
	if (argc != 3 || argv[2][0] == '\0')
	{
		write(2, "Error, arguments invalid\n", 25);
		return (1);
	}
	pid = ft_atoi(argv[1]);
	signal_block(SIGUSR1, next_handler, false);
	signal_block(SIGUSR2, end_handler, false);
	while (argv[2][i])
	{
		send_char(pid, argv[2][i]);
		i++;
	}
	send_char(pid, '\0');
	return (0);
}

void	send_char(pid_t pid, char c)
{
	int	i;

	i = 0;
	while (i < CHAR_BIT)
	{
		if ((c & (1 << i)) == 0)
			kill_check(pid, SIGUSR1);
		else
			kill_check(pid, SIGUSR2);
		i++;
		while (g_sending == NOT_READY)
			usleep(42);
		g_sending = NOT_READY;
	}
}
