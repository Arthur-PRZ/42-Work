/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artperez <artperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 09:26:56 by artperez          #+#    #+#             */
/*   Updated: 2025/03/11 14:13:41 by artperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include "../libft/libft.h"
#include <stdbool.h>
#include <stdlib.h>

enum
{
    READY,
    NOT_READY
};
void send_char(pid_t pid, char c);
void sigusr_handler(int signum, siginfo_t *info, void *more_info);
void Signal(int sigum, void *handler, bool use_siginfo);

#endif