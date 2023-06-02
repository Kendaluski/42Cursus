/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_manage.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 18:25:52 by jjaen-mo          #+#    #+#             */
/*   Updated: 2023/06/02 19:23:26 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void ft_change_exit(void *img)
{
	int32_t			prevy;
	int32_t			prevx;
	mlx_texture_t	*texture;
	mlx_image_t *extra;

	extra = img;
	if(g_data.coll_count == g_data.max_colls)
	{
		prevy = g_data.exit->instances[0].y;
		prevx = g_data.exit->instances[0].x;
		g_data.exit->enabled = false;
		texture = mlx_load_png("./sprites/tilesets/walls/doorO.png");
		g_data.exit = mlx_texture_to_image(g_data.mlx, texture);
		mlx_delete_texture(texture);
		mlx_image_to_window(g_data.mlx, g_data.exit, prevx, prevy);
	}
}

int	ft_next_pos(int32_t height, int32_t width, char key, char c)
{
	int		res;
	char	**map;

	res = 0;
	map = g_data.map.matrix;
	if (map[height - 1][width] && map[height - 1][width] == c && key == 'w')
		res = 1;
	if (map[height][width + 1] && map[height][width + 1] == c && key == 'd')
		res = 1;
	if (map[height + 1][width] && map[height + 1][width] == c && key == 's')
		res = 1;
	if (map[height][width - 1] && map[height][width - 1] == c && key == 'a')
		res = 1;
	return (res);
}

void	ft_movement(mlx_key_data_t keydata, void *window)
{
	mlx_t	*mlx;
	int32_t	*posx;
	int32_t	*posy;

	mlx = window;
	posx = &g_data.character->instances[0].x;
	posy = &g_data.character->instances[0].y;
	if (keydata.action == MLX_PRESS)
	{
		if (keydata.key == MLX_KEY_W && ft_next_pos(*posy / 64, *posx / 64, 'w',
				'1') != 1)
			*posy -= 64;
		if (keydata.key == MLX_KEY_A && ft_next_pos(*posy / 64, *posx / 64, 'a',
				'1') != 1)
			*posx -= 64;
		if (keydata.key == MLX_KEY_S && ft_next_pos(*posy / 64, *posx / 64, 's',
				'1') != 1)
			*posy += 64;
		if (keydata.key == MLX_KEY_D && ft_next_pos(*posy / 64, *posx / 64, 'd',
				'1') != 1)
			*posx += 64;
		if (keydata.key == MLX_KEY_ESCAPE)
			ft_close_window();
		ft_open_exit();
	}
}

void	ft_malloc_colls(void)
{
	int cnt;

	cnt = 0;
	g_data.colls = malloc(sizeof(mlx_image_t *) * g_data.max_colls + 1);
	g_data.colls[g_data.max_colls] = 0;
}

void	ft_add_coll(void *img)
{
	mlx_image_t	*player;
	char		**map;
	int32_t		*posx;
	int32_t		*posy;
	static int	limit = 0;

	player = img;
	map = g_data.map.matrix;
	posx = &player->instances[0].x;
	posy = &player->instances[0].y;
	if (map[*posy / 64][*posx / 64] == 'C')
	{
		if (limit == 0 && g_data.coll_count < g_data.max_colls)
		{
			g_data.colls[g_data.coll_count]->enabled=false;
			g_data.coll_count++;
			limit = 1;
		}
	}
	else
		limit = 0;
}
