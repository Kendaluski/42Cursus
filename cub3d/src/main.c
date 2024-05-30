/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 13:01:32 by jjaen-mo          #+#    #+#             */
/*   Updated: 2024/05/30 18:56:10 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_init_data(t_data *data)
{
	data->mlx = mlx_init(1024, 512, "Cub3D", false);
	ft_read_map("map.cub", data);
	ft_print_map(data->map);
	mlx_loop(data->mlx);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc != 2)
	{
		printf("[ERROR] No map specified\n");
		return (1);
	}
	if (argc == 2)
	{
		if (ft_strncmp(argv[1] + ft_strlen(argv[1]) - 4, ".cub", 4) != 0)
		{
			printf("[ERROR] Invalid file extension\n");
			return (1);
		}
	}
	data = malloc(sizeof(t_data));
	ft_init_data(data);
	free(data);
}
