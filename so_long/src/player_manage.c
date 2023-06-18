/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_manage.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 18:25:52 by jjaen-mo          #+#    #+#             */
/*   Updated: 2023/06/18 17:16:00 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

t_data	ft_init_data(t_data data)
{
	data.character = 0;
	data.floor = 0;
	data.wall = 0;
	data.colls = 0;
	data.exit = 0;
	data.enemies = 0;
	data.map.matrix = 0;
	data.map.width = 0;
	data.map.height = 0;
	data.coll_count = 0;
	data.max_colls = 0;
	data.enem_count = 0;
	data.steps = 0;
	data.playerposx = 0;
	data.playerposy = 0;
	return (data);
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

int	ft_next_pos(int32_t height, int32_t width, char key, char **map)
{
	int	res;

	res = 0;
	if (map[height - 1][width] && map[height - 1][width] == '1' && key == 'w')
		res = 1;
	if (map[height][width + 1] && map[height][width + 1] == '1' && key == 'd')
		res = 1;
	if (map[height + 1][width] && map[height + 1][width] == '1' && key == 's')
		res = 1;
	if (map[height][width - 1] && map[height][width - 1] == '1' && key == 'a')
		res = 1;
	return (res);
}

void	ft_movement(mlx_key_data_t keydata, void *data)
{
	t_data	*dataptr;
	int32_t	*posx;
	int32_t	*posy;

	dataptr = data;
	posx = &dataptr->character->instances[0].x;
	posy = &dataptr->character->instances[0].y;
	if (keydata.action == MLX_PRESS)
	{
		if (keydata.key == MLX_KEY_W && ft_next_pos(*posy / 64, *posx / 64, 'w',
				dataptr->map.matrix) != 1)
			ft_add_step(dataptr, posx, posy, 'w');
		if (keydata.key == MLX_KEY_A && ft_next_pos(*posy / 64, *posx / 64, 'a',
				dataptr->map.matrix) != 1)
			ft_add_step(dataptr, posx, posy, 'a');
		if (keydata.key == MLX_KEY_S && ft_next_pos(*posy / 64, *posx / 64, 's',
				dataptr->map.matrix) != 1)
			ft_add_step(dataptr, posx, posy, 's');
		if (keydata.key == MLX_KEY_D && ft_next_pos(*posy / 64, *posx / 64, 'd',
				dataptr->map.matrix) != 1)
			ft_add_step(dataptr, posx, posy, 'd');
		if (keydata.key == MLX_KEY_ESCAPE)
			ft_close_window(dataptr);
		ft_open_exit(*dataptr);
	}
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
