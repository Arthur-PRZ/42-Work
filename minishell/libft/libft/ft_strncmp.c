/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artperez <artperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 13:29:42 by ctravers          #+#    #+#             */
/*   Updated: 2025/05/06 10:57:46 by artperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h" 

int	ft_strncmp(char *s1, char *s2, size_t n)
{
	size_t				cmp;
	unsigned char		*str1;
	unsigned char		*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	cmp = 0;
	while ((str1[cmp] || str2[cmp]) && cmp < n)
	{
		if (str1[cmp] != str2[cmp])
			return (str1[cmp] - str2[cmp]);
		cmp++;
	}
	return (0);
}
