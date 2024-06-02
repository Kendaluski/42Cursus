/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_manage.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 23:07:28 by jjaen-mo          #+#    #+#             */
/*   Updated: 2024/06/02 23:32:28 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

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
				dataptr->map) != 1)
			ft_add_step(dataptr, posx, posy, 'w');
		if (keydata.key == MLX_KEY_A && ft_next_pos(*posy / 64, *posx / 64, 'a',
				dataptr->map) != 1)
			ft_add_step(dataptr, posx, posy, 'a');
		if (keydata.key == MLX_KEY_S && ft_next_pos(*posy / 64, *posx / 64, 's',
				dataptr->map) != 1)
			ft_add_step(dataptr, posx, posy, 's');
		if (keydata.key == MLX_KEY_D && ft_next_pos(*posy / 64, *posx / 64, 'd',
				dataptr->map) != 1)
			ft_add_step(dataptr, posx, posy, 'd');
		if (keydata.key == MLX_KEY_ESCAPE)
			mlx_close_window(dataptr->mlx);
	}
}

void	ft_add_step(t_data *data, int32_t *posx, int32_t *posy, char key)
{
	if (key == 'w')
		*posy -= 64;
	if (key == 'a')
		*posx -= 64;
	if (key == 's')
		*posy += 64;
	if (key == 'd')
		*posx += 64;
	data->steps++;
	ft_printf("Steps: %i\n", data->steps);
}
