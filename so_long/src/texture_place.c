/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_place.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 18:55:28 by jjaen-mo          #+#    #+#             */
/*   Updated: 2023/06/05 14:52:18 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

t_data	ft_player(int height, int width, t_data data)
{
	mlx_image_to_window(data.mlx, data.floor, width * 64, height * 64);
	mlx_image_to_window(data.mlx, data.character, width * 64, height * 64);
	return (data);
}

void	ft_collectible(int height, int width, t_data data)
{
	static int	cnt = 0;

	mlx_image_to_window(data.mlx, data.floor, width * 64, height * 64);
	if (cnt < data.max_colls)
	{
		mlx_image_to_window(data.mlx, data.colls[cnt], width * 64, height * 64);
		cnt++;
	}
}

void	ft_exit_img(int height, int width, t_data data)
{
	mlx_image_to_window(data.mlx, data.floor, width * 64, height * 64);
	mlx_image_to_window(data.mlx, data.exit, width * 64, height * 64);
}
