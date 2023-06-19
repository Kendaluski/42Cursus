/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_manage.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 18:25:52 by jjaen-mo          #+#    #+#             */
/*   Updated: 2023/06/19 18:41:52 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

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

void	ft_add_step(t_data *data, int32_t *posx, int32_t *posy, char key)
{
	static mlx_image_t	*steps = NULL;
	char				*str;

	if (key == 'w')
		*posy -= 64;
	if (key == 'a')
		*posx -= 64;
	if (key == 's')
		*posy += 64;
	if (key == 'd')
		*posx += 64;
	ft_change_sprite(data, key);
	data->steps++;
	str = ft_itoa(data->steps);
	steps = ft_put_steps(data, str, steps);
}
