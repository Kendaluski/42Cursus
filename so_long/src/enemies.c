/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   steps_enemies.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 16:49:25 by jjaen-mo          #+#    #+#             */
/*   Updated: 2023/06/19 18:34:43 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

t_data	ft_malloc_enemies(t_data data)
{
	int	cnt;

	cnt = 0;
	data.enemies = malloc(sizeof(mlx_image_t *) * data.enem_count + 1);
	data.enemies[data.enem_count] = 0;
	return (data);
}

t_data	ft_enemy_texture(t_data data)
{
	int				cnt;
	mlx_texture_t	*texture;

	cnt = 0;
	data = ft_malloc_enemies(data);
	while (cnt < data.enem_count)
	{
		texture = mlx_load_png("./sprites/enemies/draugr.png");
		data.enemies[cnt] = mlx_texture_to_image(data.mlx, texture);
		mlx_delete_texture(texture);
		cnt++;
	}
	return (data);
}

void	ft_enemies(t_data data, int width, int height)
{
	static int	cnt = 0;

	mlx_image_to_window(data.mlx, data.floor, width * 64, height * 64);
	if (cnt < data.enem_count)
	{
		mlx_image_to_window(data.mlx, data.enemies[cnt], width * 64, height
			* 64);
		cnt++;
	}
}

void	ft_enemy_touch(t_data data)
{
	int		cnt;
	int32_t	posx;
	int32_t	posy;

	cnt = 0;
	posx = data.character->instances[0].x;
	posy = data.character->instances[0].y;
	while (cnt < data.enem_count)
	{
		if (posx == data.enemies[cnt]->instances[0].x
			&& posy == data.enemies[cnt]->instances[0].y)
		{
			ft_printf("You lose!\n");
			ft_add_step(&data, &posx, &posy, 'w');
			exit(0);
		}
		cnt++;
	}
}
