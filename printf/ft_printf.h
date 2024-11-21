/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artperez <artperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 09:03:47 by artperez          #+#    #+#             */
/*   Updated: 2024/11/21 11:48:18 by artperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <stdint.h>

size_t	ft_strlen(const char *s);
int		ft_printf(const char *format, ...);
int		search_type(char c, va_list args);
int		ft_putnbr(int n);
void	ft_putchar(char c);
int		ft_strlen_int(int nbr);
int		ft_putstr_len(char *s);
int		base16(unsigned int nbr, char c);
int		print_p(void *ptr);
int		uns_ft_putnbr(unsigned int n);
int		long_base16(unsigned long nbr, char c);

#endif