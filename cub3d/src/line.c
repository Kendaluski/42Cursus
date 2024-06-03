/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 17:27:18 by jjaen-mo          #+#    #+#             */
/*   Updated: 2024/06/03 17:47:56 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	get_sum(double x, double ray)
{
	if (x < ray)
		return (1);
	else
		return (-1);
}

void	draw_ray_minimap_y(t_data *data)
{
    double posy;
    double posx;
    double rayy;
    double rayx;
    double m;
    double n;
    double sumy;

    posy = (data->playerposy) * 128;
    rayy = data->deltay * 128;
    rayx = data->deltax * 128;
    m = (rayy - posy) / ((rayx - (data->playerposx) * 128));
    n = posy - (m * (data->playerposx) * 128);
    sumy = get_sum(posy, rayy);
    while ((int)posy != (int)rayy)
    {
        posx = (posy - n) / m;
        if (posy >= 0 && posy < 10 * 128 && posx >= 0
            && posx < 10 * 128)
            mlx_put_pixel(data->full, (int)posx,
                (int)posy, 0xFF0000FF);
        posy += sumy;
    }
}
