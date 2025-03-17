/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artperez <artperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 09:12:43 by artperez          #+#    #+#             */
/*   Updated: 2025/03/17 09:28:57 by artperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk_bonus.h"

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	ft_printf("PID: %i\n", pid);
	signal_block(SIGUSR1, sigusr_handler, true);
	signal_block(SIGUSR2, sigusr_handler, true);
	while (1)
		pause();
	return (0);
}

void	sigusr_handler(int signum, siginfo_t *info, void *more_info)
{
	static int					i;
	static unsigned char		c;
	static char					*str = NULL;
	static pid_t				pid_sender;

	(void)more_info;
	pid_sender = info->si_pid;
	if (signum == SIGUSR2)
		c |= (1 << i);
	i++;
	if (i == 8)
	{
		i = 0;
		if (c == '\0')
		{
			ft_printf("%s\n", str);
			kill_check(pid_sender, SIGUSR2);
			c = 0;
			(free(str), str = NULL);
			return ;
		}
		str = ft_realloc(str, c);
		c = 0;
	}
	kill_check(pid_sender, SIGUSR1);
}
