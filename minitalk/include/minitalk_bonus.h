/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artperez <artperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 09:26:56 by artperez          #+#    #+#             */
/*   Updated: 2025/03/13 13:04:41 by artperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# define _GNU_SOURCE
# include <stdio.h>
# include <unistd.h>
# include <sys/types.h>
# include <signal.h>
# include "../libft/libft.h"
# include <stdbool.h>
# include <stdlib.h>

enum
{
	READY,
	NOT_READY
};
void	send_char(pid_t pid, char c);
void	sigusr_handler(int signum, siginfo_t *info, void *more_info);
void	signal_block(int sigum, void *handler, bool use_siginfo);
void	kill_check(int pid, int signum);
char	*ft_realloc(char *str1, char c);


#endif