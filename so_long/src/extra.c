/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 19:38:16 by jjaen-mo          #+#    #+#             */
/*   Updated: 2023/06/13 01:34:18 by jjaen-mo         ###   ########.fr       */
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

t_data ft_collectible_texture(t_data data)
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