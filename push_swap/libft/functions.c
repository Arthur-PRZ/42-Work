/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artperez <artperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 09:41:54 by artperez          #+#    #+#             */
/*   Updated: 2025/03/03 10:03:00 by artperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr_len(char *s)
{
	int	i;

	i = 0;
	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (s[i] != '\0')
	{
		write(1, &s[i], 1);
		i++;
	}
	return (ft_strlen_printf(s));
}

size_t	ft_strlen_printf(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_putnbr_printf(int n)
{
	int	len;
	int	recursive_len;

	len = 0;
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{
		ft_putchar('-');
		len++;
		n = n * -1;
	}
	if (n > 9)
	{
		recursive_len = ft_putnbr_printf(n / 10);
		ft_putnbr_printf(n % 10);
		len = len + recursive_len;
	}
	else
		ft_putchar(n + '0');
	return (len + 1);
}
