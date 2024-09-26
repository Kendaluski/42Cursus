/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_render.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 17:54:45 by jjaen-mo          #+#    #+#             */
/*   Updated: 2024/09/25 18:43:02 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	ft_player_data(t_data *data)
{
	data->player->diry = 0;
	data->player->dirx = 0;
	data->player->planey = 0.66;
	data->player->planex = 0.66;
	if (data->map->p == 'N')
	{
		data->player->diry = -1;
		data->player->planex = 0.66;
	}
	else if (data->map->p == 'S')
	{
		data->player->diry = 1;
		data->player->planex = -0.66;
	}
	else if (data->map->p == 'E')
	{
		data->player->dirx = 1;
		data->player->planex = 0.66;
	}
	else if (data->map->p == 'W')
	{
		data->player->dirx = -1;
		data->player->planey = -0.66;
	}
}

void	ft_player_pos(t_data *data)
{
	int		cnt;
	int		cnt2;
	char	c;

	cnt = 0;
	while (data->map->map[cnt] != NULL)
	{
		cnt2 = 0;
		while (data->map->map[cnt][cnt2] != '\0')
		{
			c = data->map->map[cnt][cnt2];
			if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
			{
				data->player->posx = cnt2;
				data->player->posy = cnt;
				data->map->p = c;
				ft_player_data(data);
				return ;
			}
			cnt2++;
		}
		cnt++;
	}
}
