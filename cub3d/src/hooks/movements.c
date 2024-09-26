/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 18:38:49 by jjaen-mo          #+#    #+#             */
/*   Updated: 2024/09/25 18:41:21 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	ft_next_pos2(t_data *data, char c, double *nextX, double *nextY)
{
	if (c == 'A')
	{
		*nextX = data->player->posx - data->player->diry * 0.1;
		*nextY = data->player->posy + data->player->dirx * 0.1;
	}
	if (c == 'D')
	{
		*nextX = data->player->posx + data->player->diry * 0.1;
		*nextY = data->player->posy - data->player->dirx * 0.1;
	}
}

void	ft_up(t_data *data)
{
	data->player->posx += data->player->dirx * 0.1;
	data->player->posy += data->player->diry * 0.1;
	data->minimap->player->instances[0].x = data->player->posx * 16;
	data->minimap->player->instances[0].y = data->player->posy * 16;
}

void	ft_down(t_data *data)
{
	data->player->posx -= data->player->dirx * 0.1;
	data->player->posy -= data->player->diry * 0.1;
	data->minimap->player->instances[0].x = data->player->posx * 16;
	data->minimap->player->instances[0].y = data->player->posy * 16;
}

void	ft_right(t_data *data)
{
	data->player->posx -= data->player->diry * 0.1;
	data->player->posy += data->player->dirx * 0.1;
	data->minimap->player->instances[0].x = data->player->posx * 16;
	data->minimap->player->instances[0].y = data->player->posy * 16;
}

void	ft_left(t_data *data)
{
	data->player->posx += data->player->diry * 0.1;
	data->player->posy -= data->player->dirx * 0.1;
	data->minimap->player->instances[0].x = data->player->posx * 16;
	data->minimap->player->instances[0].y = data->player->posy * 16;
}
