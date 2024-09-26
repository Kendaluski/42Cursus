/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ceiling_floor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 17:21:02 by jjaen-mo          #+#    #+#             */
/*   Updated: 2024/09/24 17:21:03 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	ft_fill_canvas(t_data *data)
{
	ft_gen_cealing(data);
	ft_gen_floor(data);
}

void	ft_gen_cealing(t_data *data)
{
	int	cnt;
	int	cnt2;
	int	color;

	cnt = 0;
	color = ft_rgb_to_hex(data->map->c);
	while (cnt < HEIGHT / 2)
	{
		cnt2 = 0;
		while (cnt2 < WIDTH)
		{
			mlx_put_pixel(data->screen, cnt2, cnt, color);
			cnt2++;
		}
		cnt++;
	}
}

void	ft_gen_floor(t_data *data)
{
	int	cnt;
	int	cnt2;
	int	color;

	cnt = HEIGHT / 2;
	color = ft_rgb_to_hex(data->map->f);
	while (cnt < HEIGHT)
	{
		cnt2 = 0;
		while (cnt2 < WIDTH)
		{
			mlx_put_pixel(data->screen, cnt2, cnt, color);
			cnt2++;
		}
		cnt++;
	}
}
