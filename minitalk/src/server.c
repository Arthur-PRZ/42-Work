/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artperez <artperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 09:12:43 by artperez          #+#    #+#             */
/*   Updated: 2025/03/11 15:32:09 by artperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

int	main()
{
	pid_t pid;

	pid = getpid();
	ft_printf("PID: %i\n", pid);
	Signal(SIGUSR1, sigusr_handler, true);
	Signal(SIGUSR2, sigusr_handler, true);
    while (1)
        pause();
    return (0);
}

void sigusr_handler(int signum, siginfo_t *info, void *more_info)
{
    (void)more_info;
	static int i = 0;
	static unsigned char c = 0;
    static pid_t pid_sender;
    
    pid_sender = info->si_pid;
    if (signum == SIGUSR2)
        c |= (1 << i);
    i++;
    if (i == 8)
    {
        if (c == '\0')
        {
            write(1, "\n", 1);
            kill(pid_sender, SIGUSR2);
            return ;
        }
        write(1, &c, 1);
        i = 0;
        c = 0;
    }
    kill(pid_sender, SIGUSR1);
}
