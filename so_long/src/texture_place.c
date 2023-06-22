/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_place.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 18:55:28 by jjaen-mo          #+#    #+#             */
/*   Updated: 2023/06/22 21:57:11 by jjaen-mo         ###   ########.fr       */
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

void	ft_leaks(void)
{
	system("leaks -q so_long");
}

void	ft_open_exit(t_data data)
{
	int		cnt;
	t_data	*ptr;

	cnt = 0;
	ptr = &data;
	if (data.coll_count == data.max_colls)
	{
		data.exit->enabled = true;
		if (data.map.matrix[data.character->instances[0].y
				/ 64][data.character->instances[0].x / 64] == 'E')
		{
			ft_printf("¡You Won!\n");
			ft_close_window(ptr);
		}
	}
}
