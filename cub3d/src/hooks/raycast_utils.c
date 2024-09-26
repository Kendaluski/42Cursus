/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 19:45:28 by jjaen-mo          #+#    #+#             */
/*   Updated: 2024/09/25 18:51:20 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	ft_calculate_deltas(t_player *player)
{
	if (player->rdx == 0)
		player->ddx = 1e30;
	else
		player->ddx = fabs(1 / player->rdx);
	if (player->rdy == 0)
		player->ddy = 1e30;
	else
		player->ddy = fabs(1 / player->rdy);
}

void	ft_pick_texture(t_player *player, t_textures *textures)
{
	if (player->side == 1)
	{
		if (player->rdy > 0)
			textures->use = textures->no;
		else
			textures->use = textures->so;
	}
	else
	{
		if (player->rdx > 0)
			textures->use = textures->ea;
		else
			textures->use = textures->we;
	}
}

void	ft_texture_coord(t_player *player, t_textures *textures)
{
	if (player->side == 0)
		textures->wallx = player->posy + player->perpwalldist * player->rdy;
	else
		textures->wallx = player->posx + player->perpwalldist * player->rdx;
	textures->wallx -= floor(textures->wallx);
	textures->texx = (int)(textures->wallx * (double)textures->use->width);
	if (player->side == 0 && player->rdx > 0)
		textures->texx = textures->use->width - textures->texx - 1;
	if (player->side == 1 && player->rdy < 0)
		textures->texx = textures->use->width - textures->texx - 1;
}

uint32_t	ft_pixel_to_rgb(uint8_t *pixel, int x)
{
	uint8_t		red;
	uint8_t		green;
	uint8_t		blue;
	uint8_t		alpha;
	uint32_t	color;

	red = pixel[x];
	green = pixel[x + 1];
	blue = pixel[x + 2];
	alpha = pixel[x + 3];
	color = 0;
	color |= (red << 24);
	color |= (green << 16);
	color |= (blue << 8);
	color |= alpha;
	return (color);
}

void	ft_texture_calc(t_data *data, t_player *player, t_textures *textures,
		int x)
{
	int		pos;
	double	step;
	double	texpos;
	int		y;
	int		texy;

	ft_pick_texture(player, textures);
	ft_texture_coord(player, textures);
	step = 1.0 * textures->use->height / player->lineheight;
	texpos = (player->drawstart - HEIGHT / 2 + player->lineheight / 2) * step;
	y = player->drawstart;
	while (y < player->drawend)
	{
		texy = (int)texpos & (textures->use->height - 1);
		texpos += step;
		pos = (texy * textures->use->width + textures->texx) * 4;
		textures->color = ft_pixel_to_rgb(textures->use->pixels, pos);
		mlx_put_pixel(data->screen, x, y, textures->color);
		y++;
	}
}
