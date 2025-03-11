/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artperez <artperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 14:18:35 by artperez          #+#    #+#             */
/*   Updated: 2025/03/11 15:28:21 by artperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

void    Signal(int sigum, void *handler, bool use_siginfo)
{
    struct sigaction    sa;

    ft_memset(&sa, 0, sizeof(sa));
    if (use_siginfo)
    {
        sa.sa_flags = SA_SIGINFO;
        sa.sa_sigaction = handler;
    }
	else
		sa.sa_sigaction = handler;
    sigemptyset(&sa.sa_mask);
    sigaddset(&sa.sa_mask, SIGUSR1);
    sigaddset(&sa.sa_mask, SIGUSR2);
    if (sigaction(sigum, &sa, NULL) == -1)
    {
        write(2, "sigaction failed\n", 17);
        exit(EXIT_FAILURE);
    }
}