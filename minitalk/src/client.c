/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artperez <artperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 09:15:39 by artperez          #+#    #+#             */
/*   Updated: 2025/03/11 15:29:32 by artperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

volatile sig_atomic_t   sending = NOT_READY;

void    next_handler(int signum)
{
    (void)signum;
    sending = READY;
}

void    end_handler(int signum)
{
    (void)signum;
    ft_printf("Message received\n");
    exit (EXIT_SUCCESS);    
}
int	main(int argc, char **argv)
{
	int	i;
    int pid;
	
	i = 0;
    if (argc != 3)
    {
        write(2, "Error, argument invalid\n", 24);
        return (1);
    }
    pid = ft_atoi(argv[1]);
    Signal(SIGUSR1, next_handler, false);
    Signal(SIGUSR2, end_handler, false);
	while (argv[2][i])
	{
		send_char(pid, argv[2][i]);
		i++;
	}
	send_char(pid, '\0');
    return (0);
}

void send_char(pid_t pid, char c)
{
	int i;
    
    i = 0;
    while (i < CHAR_BIT)
    {
        if ((c & (1 << i)) == 0)
            kill(pid, SIGUSR1);
        else
            kill(pid, SIGUSR2);
        i++;
        while (sending == NOT_READY)
            usleep(42);
        sending = NOT_READY;
    }
}
