/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 19:38:16 by jjaen-mo          #+#    #+#             */
/*   Updated: 2023/06/12 19:54:34 by jjaen-mo         ###   ########.fr       */
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
