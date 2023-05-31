/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 12:47:02 by jjaen-mo          #+#    #+#             */
/*   Updated: 2023/05/31 20:41:35 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	ft_exit_error(void)
{
	ft_printf("%s", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

// int	main(void)
// {
// 	mlx_texture_t	*texture;

// 	mlx_set_setting(MLX_MAXIMIZED, false);
// 	g_data.mlx = mlx_init(WIDTH, HEIGHT, "Never Gonna Give You Up", true);
// 	if (!g_data.mlx)
// 		ft_exit_error();
// 	texture = mlx_load_png("./sprites/player/idle.png");
// 	if (!texture)
// 		ft_exit_error();
// 	g_data.img = mlx_texture_to_image(g_data.mlx, texture);
// 	if (!g_data.img)
// 		ft_exit_error();
// 	if (!g_data.img || (mlx_image_to_window(g_data.mlx, g_data.img, 0, 0) < 0))
// 		ft_exit_error();
// 	mlx_key_hook(g_data.mlx, ft_movement, g_data.mlx);
// 	mlx_loop(g_data.mlx);
// 	mlx_terminate(g_data.mlx);
// 	return (EXIT_SUCCESS);
// }

int	main(int argc, char *argv[])
{
	if (argc == 2)
	{
		ft_printf("Map: \n%s\nMap Height: %i || Map Width: %i",
				ft_read_file(argv[1]), g_map.height, g_map.width);
	}
}