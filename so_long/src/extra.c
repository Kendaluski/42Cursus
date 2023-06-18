/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 19:38:16 by jjaen-mo          #+#    #+#             */
/*   Updated: 2023/06/18 19:53:37 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

mlx_image_t	*ft_put_steps(t_data *data, char *str, mlx_image_t *steps)
{
	mlx_image_t	*phrase;
	static int	first = 0;

	if (steps)
		mlx_delete_image(data->mlx, steps);
	if (first == 0)
	{
		phrase = mlx_put_string(data->mlx, "Steps: ", 0, 0);
		mlx_image_to_window(data->mlx, phrase, 0, 0);
		first++;
	}
	steps = mlx_put_string(data->mlx, str, 64, 0);
	mlx_image_to_window(data->mlx, steps, 64, 0);
	free(str);
	return (steps);
}

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

void	ft_change_sprite(t_data *data, char key)
{
	mlx_texture_t	*texture;
	int32_t			posx;
	int32_t			posy;

	texture = NULL;
	if (key == 'w')
		texture = mlx_load_png("./sprites/player/back.png");
	else if (key == 'a')
		texture = mlx_load_png("./sprites/player/left.png");
	else if (key == 's')
		texture = mlx_load_png("./sprites/player/idle.png");
	else if (key == 'd')
		texture = mlx_load_png("./sprites/player/right.png");
	posx = data->character->instances[0].x;
	posy = data->character->instances[0].y;
	data->character->instances[0].enabled = false;
	data->character = mlx_texture_to_image(data->mlx, texture);
	mlx_delete_texture(texture);
	mlx_image_to_window(data->mlx, data->character, posx, posy);
	data->character->instances->enabled = true;
}

t_data	ft_iniciate(t_data data)
{
	data.mlx = mlx_init(data.map.width * 64, data.map.height * 64,
			"Never Gonna Give You Up", false);
	if (!data.mlx)
		ft_exit_error();
	data.max_colls = ft_get_max(data.map.matrix, 'C');
	data.enem_count = ft_get_max(data.map.matrix, 'B');
	data = ft_create_textures(data);
	return (data);
}
