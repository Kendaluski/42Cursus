/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 13:54:22 by jjaen-mo          #+#    #+#             */
/*   Updated: 2023/06/02 18:32:17 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void ft_close_window(void)
{
	
	free(g_data.colls);
	mlx_close_window(g_data.mlx);
}

void	ft_get_max_colls(void)
{
	int	cnt;
	int	cnt2;

	cnt = 0;
	while (g_data.map.matrix[cnt])
	{
		cnt2 = 0;
		while (g_data.map.matrix[cnt][cnt2])
		{
			if (g_data.map.matrix[cnt][cnt2] == 'C')
				g_data.max_colls++;
			cnt2++;
		}
		cnt++;
	}
}

void	ft_create_textures(void)
{
	mlx_texture_t	*texture;
	static int		cnt = 0;

	texture = mlx_load_png("./sprites/player/idle.png");
	g_data.character = mlx_texture_to_image(g_data.mlx, texture);
	mlx_delete_texture(texture);
	texture = mlx_load_png("./sprites/tilesets/grass.png");
	g_data.floor = mlx_texture_to_image(g_data.mlx, texture);
	mlx_delete_texture(texture);
	ft_malloc_colls();
	while (cnt < g_data.max_colls)
	{
		texture = mlx_load_png("./sprites/objects/chest.png");
		g_data.colls[cnt] = mlx_texture_to_image(g_data.mlx, texture);
		mlx_delete_texture(texture);
		cnt++;
	}
	texture = mlx_load_png("./sprites/tilesets/walls/wall.png");
	g_data.wall = mlx_texture_to_image(g_data.mlx, texture);
	mlx_delete_texture(texture);
	texture = mlx_load_png("./sprites/tilesets/walls/doorC.png");
	g_data.exit = mlx_texture_to_image(g_data.mlx, texture);
	mlx_delete_texture(texture);
}

void	ft_gen_player(void)
{
	int	cnt;
	int	cnt2;

	cnt = 0;
	while (g_data.map.matrix[cnt])
	{
		cnt2 = 0;
		while (g_data.map.matrix[cnt][cnt2])
		{
			if (g_data.map.matrix[cnt][cnt2] == 'P')
				ft_player(cnt, cnt2);
			cnt2++;
		}
		cnt++;
	}
}

void	ft_gen_map(void)
{
	int	cnt;
	int	cnt2;

	ft_get_max_colls();
	ft_create_textures();
	cnt = 0;
	while (g_data.map.matrix[cnt])
	{
		cnt2 = 0;
		while (g_data.map.matrix[cnt][cnt2])
		{
			if (g_data.map.matrix[cnt][cnt2] == '1')
				ft_wall(cnt, cnt2);
			if (g_data.map.matrix[cnt][cnt2] == '0')
				ft_floor(cnt, cnt2);
			if (g_data.map.matrix[cnt][cnt2] == 'C')
				ft_collectible(cnt, cnt2);
			if (g_data.map.matrix[cnt][cnt2] == 'E')
				ft_exit_img(cnt, cnt2);
			cnt2++;
		}
		cnt++;
	}
	ft_gen_player();
}
