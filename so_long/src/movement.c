/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 18:25:52 by jjaen-mo          #+#    #+#             */
/*   Updated: 2023/05/31 19:58:49 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	ft_movement(mlx_key_data_t keydata, void *window)
{
	mlx_t	*mlx;

	mlx = window;
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		g_data.img->instances[0].y -= 32;
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		g_data.img->instances[0].x -= 32;
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		g_data.img->instances[0].y += 32;
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		g_data.img->instances[0].x += 32;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(g_data.mlx);
}
