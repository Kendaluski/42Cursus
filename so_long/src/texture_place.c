/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_place.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 18:55:28 by jjaen-mo          #+#    #+#             */
/*   Updated: 2023/06/02 18:10:49 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	ft_wall(int height, int width)
{
	mlx_image_to_window(g_data.mlx, g_data.wall, width * 64, height * 64);
}

void	ft_floor(int height, int width)
{
	mlx_image_to_window(g_data.mlx, g_data.floor, width * 64, height * 64);
}

void	ft_player(int height, int width)
{
	mlx_image_to_window(g_data.mlx, g_data.floor, width * 64, height * 64);
	mlx_image_to_window(g_data.mlx, g_data.character, width * 64, height * 64);
}

void	ft_collectible(int height, int width)
{
	static int cnt = 0;
	
	mlx_image_to_window(g_data.mlx, g_data.floor, width * 64, height * 64);
	if(cnt < g_data.max_colls)
	{
		mlx_image_to_window(g_data.mlx, g_data.colls[cnt], width * 64, height * 64);
		cnt++;
	}
}

void	ft_exit_img(int height, int width)
{
	mlx_image_to_window(g_data.mlx, g_data.floor, width * 64, height * 64);
	mlx_image_to_window(g_data.mlx, g_data.exit, width * 64, height * 64);
}
