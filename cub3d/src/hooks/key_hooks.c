/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 17:36:52 by jjaen-mo          #+#    #+#             */
/*   Updated: 2024/09/25 18:42:44 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	ft_rot_left(t_data *data)
{
	data->player->olddirx = data->player->dirx;
	data->player->dirx = data->player->dirx * cos(-0.1) - data->player->diry
		* sin(-0.1);
	data->player->diry = data->player->olddirx * sin(-0.1) + data->player->diry
		* cos(-0.1);
	data->player->oldplanex = data->player->planex;
	data->player->planex = data->player->planex * cos(-0.1)
		- data->player->planey * sin(-0.1);
	data->player->planey = data->player->oldplanex * sin(-0.1)
		+ data->player->planey * cos(-0.1);
}

static void	ft_rot_right(t_data *data)
{
	data->player->olddirx = data->player->dirx;
	data->player->dirx = data->player->dirx * cos(0.1) - data->player->diry
		* sin(0.1);
	data->player->diry = data->player->olddirx * sin(0.1) + data->player->diry
		* cos(0.1);
	data->player->oldplanex = data->player->planex;
	data->player->planex = data->player->planex * cos(0.1)
		- data->player->planey * sin(0.1);
	data->player->planey = data->player->oldplanex * sin(0.1)
		+ data->player->planey * cos(0.1);
}

static double	ft_distance(double x1, double y1, double x2, double y2)
{
	return (sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2)));
}

static int	ft_next_pos(t_data *data, char c)
{
	double	nextx;
	double	nexty;
	double	dis;

	if (c == 'W')
	{
		nextx = data->player->posx + data->player->dirx * 0.1;
		nexty = data->player->posy + data->player->diry * 0.1;
	}
	if (c == 'S')
	{
		nextx = data->player->posx - data->player->dirx * 0.1;
		nexty = data->player->posy - data->player->diry * 0.1;
	}
	if (c == 'A' || c == 'D')
		ft_next_pos2(data, c, &nextx, &nexty);
	if (data->map->map[(int)nexty][(int)nextx] == '1')
	{
		dis = ft_distance(data->player->posx, data->player->posy, nextx, nexty);
		if ((int)dis < 0.1)
			return (1);
	}
	return (0);
}

void	ft_key_hook(mlx_key_data_t key, void *d)
{
	t_data	*data;

	data = (t_data *)d;
	if (key.action == MLX_PRESS)
	{
		if (key.key == MLX_KEY_ESCAPE)
		{
			mlx_close_window(data->mlx);
			ft_clean_exit(data);
		}
	}
	if (mlx_is_key_down(data->mlx, MLX_KEY_W) && ft_next_pos(data, 'W') == 0)
		ft_up(data);
	if (mlx_is_key_down(data->mlx, MLX_KEY_S) && ft_next_pos(data, 'S') == 0)
		ft_down(data);
	if (mlx_is_key_down(data->mlx, MLX_KEY_D) && ft_next_pos(data, 'D') == 0)
		ft_right(data);
	if (mlx_is_key_down(data->mlx, MLX_KEY_A) && ft_next_pos(data, 'A') == 0)
		ft_left(data);
	if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT))
		ft_rot_right(data);
	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT))
		ft_rot_left(data);
}
