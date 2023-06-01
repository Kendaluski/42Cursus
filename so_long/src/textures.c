/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 13:54:22 by jjaen-mo          #+#    #+#             */
/*   Updated: 2023/06/01 19:01:06 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

// void ft_resize_imgs(void)
// {
// 	int width;
// 	int height;


// }

void	ft_create_textures(void)
{
	mlx_texture_t	*texture;

	texture = mlx_load_png("./sprites/player/idle.png");
	g_data.character = mlx_texture_to_image(g_data.mlx, texture);
	mlx_delete_texture(texture);
	texture = mlx_load_png("./sprites/tilesets/grass.png");
	g_data.floor = mlx_texture_to_image(g_data.mlx, texture);
	mlx_delete_texture(texture);
	texture = mlx_load_png("./sprites/objects/chest.png");
	g_data.coll = mlx_texture_to_image(g_data.mlx, texture);
	mlx_delete_texture(texture);
	texture = mlx_load_png("./sprites/tilesets/walls/wall.png");
	g_data.wall = mlx_texture_to_image(g_data.mlx, texture);
	mlx_delete_texture(texture);
	texture = mlx_load_png("./sprites/tilesets/walls/doorC.png");
	g_data.exit = mlx_texture_to_image(g_data.mlx, texture);
	mlx_delete_texture(texture);
}
void	ft_gen_map(void)
{
	ft_create_textures();
	int cnt;
	int cnt2;
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
			if (g_data.map.matrix[cnt][cnt2] == 'P')
				ft_player(cnt, cnt2);
			if (g_data.map.matrix[cnt][cnt2] == 'C')
				ft_collectible(cnt, cnt2);
			if (g_data.map.matrix[cnt][cnt2] == 'E')
				ft_exit_img(cnt, cnt2);
			cnt2++;
		}
		cnt++;
	}
}
