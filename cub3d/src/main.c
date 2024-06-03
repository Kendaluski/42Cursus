/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 13:01:32 by jjaen-mo          #+#    #+#             */
/*   Updated: 2024/06/03 19:25:19 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	hook(void *param)
{
	t_data	*data;
	int32_t	*posx;
	int32_t	*posy;

	data = param;
	posx = &data->character->instances[0].x;
	posy = &data->character->instances[0].y;
	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(data->mlx);
	if (mlx_is_key_down(data->mlx, MLX_KEY_W))
	{
		*posy += data->deltay;
		*posx += data->deltax;
	}
	if (mlx_is_key_down(data->mlx, MLX_KEY_S))
	{
		*posy -= data->deltay;
		*posx -= data->deltax;
	}
	if (mlx_is_key_down(data->mlx, MLX_KEY_A))
	{
		data->pangle -= 0.1;
		if (data->pangle < 0)
			data->pangle += 2 * PI;
		data->deltax = cos(data->pangle) * 5;
		data->deltay = sin(data->pangle) * 5;
	}
	if (mlx_is_key_down(data->mlx, MLX_KEY_D))
	{
		data->pangle += 0.1;
		if (data->pangle > 2 * PI)
			data->pangle -= 0;
		data->deltax = cos(data->pangle) * 5;
		data->deltay = sin(data->pangle) * 5;
	}
}

void	ft_init_data(t_data *data)
{
	data->mlx = mlx_init(2048, 1024, "Cub3D", false);
	ft_read_map("map.cub", data);
	ft_gen_map(data);
	data->pangle = 0;
	data->deltax = cos(data->pangle) * 5;
	data->deltay = sin(data->pangle) * 5;
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
	data->full = mlx_new_image(data->mlx, 2048, 1024);
	mlx_image_to_window(data->mlx, data->full, 0, 0);
	ft_get_hw(data);
	mlx_loop_hook(data->mlx, hook, data);
	mlx_loop_hook(data->mlx, drawRays3D, data);
	mlx_loop(data->mlx);
	free(data);
}
