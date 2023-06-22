/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 13:54:22 by jjaen-mo          #+#    #+#             */
/*   Updated: 2023/06/22 21:58:14 by jjaen-mo         ###   ########.fr       */
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

	texture = mlx_load_png("./sprites/player/idle.png");
	data.character = mlx_texture_to_image(data.mlx, texture);
	mlx_delete_texture(texture);
	texture = mlx_load_png("./sprites/tilesets/planks_acacia.png");
	data.floor = mlx_texture_to_image(data.mlx, texture);
	mlx_delete_texture(texture);
	data = ft_malloc_colls(data);
	texture = mlx_load_png("./sprites/tilesets/cobblestone.png");
	data.wall = mlx_texture_to_image(data.mlx, texture);
	mlx_delete_texture(texture);
	texture = mlx_load_png("./sprites/tilesets/doorO.png");
	data.exit = mlx_texture_to_image(data.mlx, texture);
	mlx_delete_texture(texture);
	data = ft_collectible_texture(data);
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
			{
				data = ft_player(cnt, cnt2, data);
				data.playerposx = cnt2;
				data.playerposy = cnt;
			}
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
			cnt2++;
		}
		cnt++;
	}
	data = ft_gen_player(data);
	return (data);
}
