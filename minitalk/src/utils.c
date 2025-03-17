/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artperez <artperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 14:18:35 by artperez          #+#    #+#             */
/*   Updated: 2025/03/17 09:28:20 by artperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

void	signal_block(int sigum, void *handler, bool use_siginfo)
{
	struct sigaction	sa;

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

void	kill_check(int pid, int signum)
{
	if (kill(pid, signum) < 0)
	{
		write(2, "Error, sending signum\n", 22);
		exit (EXIT_FAILURE);
	}
}

char	*ft_realloc(char *str1, char c)
{
	int		i;
	int		a;
	int		len;
	char	*return_str;

	i = -1;
	a = 0;
	if (str1 == NULL)
	{
		return_str = malloc(2);
		if (return_str == NULL)
			return (NULL);
		return_str[0] = c;
		return_str[1] = '\0';
		return (return_str);
	}
	len = ft_strlen(str1) + 2;
	return_str = malloc(len * sizeof(char));
	if (return_str == NULL)
		return (NULL);
	while (str1[++i] != '\0')
		return_str[i] = str1[i];
	return_str[i] = c;
	return_str[i + 1] = '\0';
	return (free(str1), return_str);
}
