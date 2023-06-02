/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 12:47:02 by jjaen-mo          #+#    #+#             */
/*   Updated: 2023/06/02 19:24:09 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	ft_open_exit(void)
{
	if (g_data.coll_count == g_data.max_colls)
	{
		g_data.exit->enabled = true;
		if (g_data.map.matrix[g_data.character->instances[0].y
			/ 64][g_data.character->instances[0].x / 64] == 'E')
		{
			ft_printf("¡You Won!\n");
			ft_close_window();
		}
	}
}

void	ft_exit_error(void)
{
	ft_printf("%s", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

int	ft_create_window(void)
{
	mlx_set_setting(MLX_MAXIMIZED, false);
	g_data.mlx = mlx_init(g_data.map.width * 64, g_data.map.height * 64,
			"Never Gonna Give You Up", true);
	if (!g_data.mlx)
		ft_exit_error();
	ft_gen_map();
	mlx_key_hook(g_data.mlx, ft_movement, g_data.mlx);
	mlx_loop_hook(g_data.mlx, ft_add_coll, g_data.character);
	mlx_loop_hook(g_data.mlx, ft_change_exit, g_data.character);
	mlx_loop(g_data.mlx);
	mlx_terminate(g_data.mlx);
	return (EXIT_SUCCESS);
}

void	ft_leaks(void)
{
	system("leaks -q so_long");
}

int	main(int argc, char *argv[])
{
	int		cnt;
	char	*file_read;

	if (argc == 2)
	{
		cnt = 0;
		atexit(ft_leaks);
		file_read = ft_read_file(argv[1]);
		ft_create_map(file_read);
		ft_create_window();
	}
}
