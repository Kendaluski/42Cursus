/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 22:15:18 by jjaen-mo          #+#    #+#             */
/*   Updated: 2024/06/03 17:42:45 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_player(int height, int width, t_data *data)
{
	mlx_image_to_window(data->mlx, data->character, width * 128, height * 128);
}

void	ft_create_textures(t_data *data)
{
	mlx_texture_t	*texture;

	texture = mlx_load_png("./textures/player.png");
	data->character = mlx_texture_to_image(data->mlx, texture);
	mlx_delete_texture(texture);
	texture = mlx_load_png("./textures/wall.png");
	data->wall = mlx_texture_to_image(data->mlx, texture);
	mlx_delete_texture(texture);
    texture = mlx_load_png("./textures/floor.png");
    data->floor = mlx_texture_to_image(data->mlx, texture);
    mlx_delete_texture(texture);
}

void	ft_gen_player(t_data *data)
{
	int	cnt;
	int	cnt2;

	cnt = 0;
	while (data->map[cnt])
	{
		cnt2 = 0;
		while (data->map[cnt][cnt2])
		{
			if (data->map[cnt][cnt2] == 'N')
			{
				ft_player(cnt, cnt2, data);
				data->playerposx = cnt2;
				data->playerposy = cnt;
			}
			cnt2++;
		}
		cnt++;
	}
}

void	ft_gen_map(t_data *data)
{
	int	cnt;
	int	cnt2;

	cnt = 0;
    ft_create_textures(data);
	while (data->map[cnt])
	{
		cnt2 = 0;
		while (data->map[cnt][cnt2])
		{
			if (data->map[cnt][cnt2] == '1')
				mlx_image_to_window(data->mlx, data->wall, cnt2 * 128, cnt * 128);
            if (data->map[cnt][cnt2] == '0')
                mlx_image_to_window(data->mlx, data->floor, cnt2 * 128, cnt * 128);
			cnt2++;
		}
		cnt++;
	}
	ft_gen_player(data);
}