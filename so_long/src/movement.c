/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 18:25:52 by jjaen-mo          #+#    #+#             */
/*   Updated: 2023/06/01 19:38:21 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	ft_movement(mlx_key_data_t keydata, void *window)
{
	mlx_t	*mlx;

	mlx = window;
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		g_data.character->instances[0].y -= 64;
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		g_data.character->instances[0].x -= 64;
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		g_data.character->instances[0].y += 64;
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		g_data.character->instances[0].x += 64;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(g_data.mlx);
}
