/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 20:05:53 by jjaen-mo          #+#    #+#             */
/*   Updated: 2024/09/24 18:31:21 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	ft_draw_minimap(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	while (data->map->map[x])
	{
		y = 0;
		while (data->map->map[x][y])
		{
			if (data->map->map[x][y] == '1')
				mlx_image_to_window(data->mlx, data->minimap->wall, y * 16, x
					* 16);
			else if (data->map->map[x][y] == 'N' || data->map->map[x][y] == 'S'
				|| data->map->map[x][y] == 'E' || data->map->map[x][y] == 'W')
				mlx_image_to_window(data->mlx, data->minimap->player, y * 16, x
					* 16);
			y++;
		}
		x++;
	}
}
