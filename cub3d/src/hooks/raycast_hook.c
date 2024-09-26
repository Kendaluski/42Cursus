/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_hook.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 18:00:51 by jjaen-mo          #+#    #+#             */
/*   Updated: 2024/09/25 18:53:12 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	ft_draw_line(t_data *data, int x, int drawstart)
{
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		if (y < drawstart)
			mlx_put_pixel(data->screen, x, y, data->c_color);
		else
			mlx_put_pixel(data->screen, x, y, data->f_color);
		y++;
	}
}

static void	ft_calculate_step(t_player *player)
{
	if (player->rdx < 0)
	{
		player->stepx = -1;
		player->sidedistx = (player->posx - player->mapx) * player->ddx;
	}
	else
	{
		player->stepx = 1;
		player->sidedistx = (player->mapx + 1.0 - player->posx) * player->ddx;
	}
	if (player->rdy < 0)
	{
		player->stepy = -1;
		player->sidedisty = (player->posy - player->mapy) * player->ddy;
	}
	else
	{
		player->stepy = 1;
		player->sidedisty = (player->mapy + 1.0 - player->posy) * player->ddy;
	}
}

static void	ft_dda(t_data *data, t_player *player)
{
	while (player->hit == 0)
	{
		if (player->sidedistx < player->sidedisty)
		{
			player->sidedistx += player->ddx;
			player->mapx += player->stepx;
			player->side = 0;
		}
		else
		{
			player->sidedisty += player->ddy;
			player->mapy += player->stepy;
			player->side = 1;
		}
		if (data->map->map[player->mapy][player->mapx] == '1')
			player->hit = 1;
	}
	if (player->side == 0)
		player->perpwalldist = (player->sidedistx - player->ddx);
	else
		player->perpwalldist = (player->sidedisty - player->ddy);
	player->lineheight = HEIGHT / player->perpwalldist;
}

static void	ft_draw_start_end(t_player *player)
{
	player->drawstart = (int)-player->lineheight / 2 + HEIGHT / 2;
	if (player->drawstart < 0)
		player->drawstart = 0;
	player->drawend = (int)player->lineheight / 2 + HEIGHT / 2;
	if (player->drawend >= HEIGHT)
		player->drawend = HEIGHT - 1;
}

void	ft_raycasting(void *d)
{
	int			x;
	t_data		*data;
	t_player	*player;

	x = 0;
	data = (t_data *)d;
	ft_clear_screen(data->screen);
	player = data->player;
	while (x < WIDTH)
	{
		player->camerax = 2 * x / (double)WIDTH - 1;
		player->rdx = player->dirx + player->planex * player->camerax;
		player->rdy = player->diry + player->planey * player->camerax;
		player->mapx = (int)player->posx;
		player->mapy = (int)player->posy;
		ft_calculate_deltas(player);
		player->hit = 0;
		ft_calculate_step(player);
		ft_dda(data, player);
		ft_draw_start_end(player);
		ft_draw_line(data, x, player->drawstart);
		ft_texture_calc(data, player, data->textures, x);
		x++;
	}
}
