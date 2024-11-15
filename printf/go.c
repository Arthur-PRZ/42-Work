/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artperez <artperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 14:04:01 by artperez          #+#    #+#             */
/*   Updated: 2024/11/15 14:46:09 by artperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>

void	chearch_type(char c, va_list args)
{
	if (str[i] == 'c')
		
	if (str[i] == 's')
	if (str[i] == 'p')
	if (str[i] == 'd')
	if (str[i] == 'i')
	if (str[i] == 'u')
	if (str[i] == 'x')
	if (str[i] == 'X')
	if (str[i] == '%')

}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	va_start(args, str);
	
	va_arg
	while(str[i])
	{
		while (str[i] != '\0' && str[i] != '%')
		{
			ft_putchar_fd(str[i], 1),
				i++;
		}
		if (str[i] == '%')
		{
			i++;
			if (str[i] != 'c' && str[i] != 's' && str[i] != 'p' && str[i] != 'd' 
			&& str[i] != 'i' && str[i] != 'u' && str[i] != 'x' && str[i] != 'X' 
			&& str[i] != '%')
				ft_putchar_fd(str[i], 1),
			else
				chearch_types(str[i], args)
		}
	}
}
