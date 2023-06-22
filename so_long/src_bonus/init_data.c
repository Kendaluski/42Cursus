/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 19:38:16 by jjaen-mo          #+#    #+#             */
/*   Updated: 2023/06/19 18:42:00 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

t_data	ft_init_data(t_data data)
{
	data.character = 0;
	data.floor = 0;
	data.wall = 0;
	data.colls = 0;
	data.exit = 0;
	data.enemies = 0;
	data.map.matrix = 0;
	data.map.width = 0;
	data.map.height = 0;
	data.coll_count = 0;
	data.max_colls = 0;
	data.enem_count = 0;
	data.steps = 0;
	data.playerposx = 0;
	data.playerposy = 0;
	return (data);
}

t_data	ft_iniciate(t_data data)
{
	data.mlx = mlx_init(data.map.width * 64, data.map.height * 64,
			"Never Gonna Give You Up", false);
	if (!data.mlx)
	{
		ft_printf("%s", mlx_strerror(mlx_errno));
		exit(EXIT_FAILURE);
	}
	data.max_colls = ft_get_max(data.map.matrix, 'C');
	data.enem_count = ft_get_max(data.map.matrix, 'B');
	data = ft_create_textures(data);
	return (data);
}
