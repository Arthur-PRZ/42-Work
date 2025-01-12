/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artperez <artperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 09:32:58 by artperez          #+#    #+#             */
/*   Updated: 2025/01/10 11:00:54 by artperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "../minilibx-linux/mlx.h"
#include "../libft/libft.h"
#include <X11/keysym.h>

typedef struct s_mlx_data
{
    void    *mlx_start;
    void    *mlx_window;
}   t_mlx_data;

#define HEIGHT 800
#define WIDTH 800

int	handle_input(int keysym, t_mlx_data *ptr);


#endif