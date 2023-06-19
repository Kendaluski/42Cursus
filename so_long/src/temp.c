/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   temp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 18:40:33 by jjaen-mo          #+#    #+#             */
/*   Updated: 2023/06/19 18:41:10 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

t_data	ft_collectible_texture(t_data data)
{
	static int		cnt = 0;
	mlx_texture_t	*texture;

	while (cnt < data.max_colls)
	{
		if (cnt == data.max_colls - 1)
		{
			texture = mlx_load_png("./sprites/objects/opchest.png");
			data.colls[cnt] = mlx_texture_to_image(data.mlx, texture);
			mlx_delete_texture(texture);
			return (data);
		}
		texture = mlx_load_png("./sprites/objects/chest.png");
		data.colls[cnt] = mlx_texture_to_image(data.mlx, texture);
		mlx_delete_texture(texture);
		cnt++;
	}
	return (data);
}

void	ft_add_coll(void *data)
{
	t_data		*dataptr;
	int32_t		*posx;
	int32_t		*posy;
	int			cnt;
	static int	limit = 0;

	cnt = 0;
	dataptr = data;
	posx = &dataptr->character->instances[0].x;
	posy = &dataptr->character->instances[0].y;
	if (dataptr->map.matrix[*posy / 64][*posx / 64] == 'C')
	{
		if (limit == 0 && dataptr->coll_count < dataptr->max_colls)
		{
			while (dataptr->colls[cnt]->instances[0].x != *posx
				|| dataptr->colls[cnt]->instances[0].y != *posy)
				cnt++;
			dataptr->colls[cnt]->enabled = false;
			dataptr->map.matrix[*posy / 64][*posx / 64] = '0';
			dataptr->coll_count++;
			limit = 1;
		}
	}
	else
		limit = 0;
}

void	ft_change_exit(void *data)
{
	int32_t			prevy;
	int32_t			prevx;
	mlx_texture_t	*texture;
	t_data			*dataptr;

	dataptr = data;
	ft_add_coll(dataptr);
	ft_enemy_touch(*dataptr);
	if (dataptr->coll_count == dataptr->max_colls)
	{
		prevy = dataptr->exit->instances[0].y;
		prevx = dataptr->exit->instances[0].x;
		dataptr->exit->enabled = false;
		texture = mlx_load_png("./sprites/tilesets/ladder.png");
		dataptr->exit = mlx_texture_to_image(dataptr->mlx, texture);
		mlx_delete_texture(texture);
		mlx_image_to_window(dataptr->mlx, dataptr->exit, prevx, prevy);
	}
}
