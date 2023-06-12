/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 13:54:22 by jjaen-mo          #+#    #+#             */
/*   Updated: 2023/06/12 19:22:54 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	ft_get_max(char **map, char c)
{
	int	cnt;
	int	cnt2;
	int	max;

	cnt = 0;
	max = 0;
	while (map[cnt])
	{
		cnt2 = 0;
		while (map[cnt][cnt2])
		{
			if (map[cnt][cnt2] == c)
				max++;
			cnt2++;
		}
		cnt++;
	}
	return (max);
}

t_data	ft_malloc_colls(t_data data)
{
	data.colls = malloc(sizeof(mlx_image_t *) * data.max_colls + 1);
	data.colls[data.max_colls] = 0;
	return (data);
}

t_data	ft_create_textures(t_data data)
{
	mlx_texture_t	*texture;
	static int		cnt = 0;

	texture = mlx_load_png("./sprites/player/skyrim.png");
	data.character = mlx_texture_to_image(data.mlx, texture);
	mlx_delete_texture(texture);
	texture = mlx_load_png("./sprites/tilesets/grass.png");
	data.floor = mlx_texture_to_image(data.mlx, texture);
	mlx_delete_texture(texture);
	data = ft_malloc_colls(data);
	while (cnt < data.max_colls)
	{
		texture = mlx_load_png("./sprites/objects/chest.png");
		data.colls[cnt] = mlx_texture_to_image(data.mlx, texture);
		mlx_delete_texture(texture);
		cnt++;
	}
	texture = mlx_load_png("./sprites/tilesets/walls/wall.png");
	data.wall = mlx_texture_to_image(data.mlx, texture);
	mlx_delete_texture(texture);
	texture = mlx_load_png("./sprites/tilesets/walls/doorC.png");
	data.exit = mlx_texture_to_image(data.mlx, texture);
	mlx_delete_texture(texture);
	data = ft_enemy_texture(data);
	return (data);
}

t_data	ft_gen_player(t_data data)
{
	int	cnt;
	int	cnt2;

	cnt = 0;
	while (data.map.matrix[cnt])
	{
		cnt2 = 0;
		while (data.map.matrix[cnt][cnt2])
		{
			if (data.map.matrix[cnt][cnt2] == 'P')
				data = ft_player(cnt, cnt2, data);
			cnt2++;
		}
		cnt++;
	}
	return (data);
}

t_data	ft_gen_map(t_data data)
{
	int	cnt;
	int	cnt2;

	cnt = 0;
	while (data.map.matrix[cnt])
	{
		cnt2 = 0;
		while (data.map.matrix[cnt][cnt2])
		{
			if (data.map.matrix[cnt][cnt2] == '1')
				mlx_image_to_window(data.mlx, data.wall, cnt2 * 64, cnt * 64);
			if (data.map.matrix[cnt][cnt2] == '0')
				mlx_image_to_window(data.mlx, data.floor, cnt2 * 64, cnt * 64);
			if (data.map.matrix[cnt][cnt2] == 'C')
				ft_collectible(cnt, cnt2, data);
			if (data.map.matrix[cnt][cnt2] == 'E')
				ft_exit_img(cnt, cnt2, data);
			if (data.map.matrix[cnt][cnt2] == 'B')
				ft_enemies(data, cnt2, cnt);
			cnt2++;
		}
		cnt++;
	}
	data = ft_gen_player(data);
	return (data);
}
