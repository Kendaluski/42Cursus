/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 12:47:02 by jjaen-mo          #+#    #+#             */
/*   Updated: 2023/06/05 15:06:53 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

char	**ft_free(char **map)
{
	int	cnt;

	cnt = 0;
	while (map[cnt])
	{
		free(map[cnt]);
		cnt++;
	}
	free(map);
	return (NULL);
}

void	ft_close_window(t_data data)
{
	free(data.colls);
	data.map.matrix = ft_free(data.map.matrix);
	mlx_close_window(data.mlx);
}

void	ft_exit_error(void)
{
	ft_printf("%s", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

int	ft_create_window(t_data data)
{
	t_data	*ptr;

	ptr = &data;
	mlx_set_setting(MLX_MAXIMIZED, false);
	data.mlx = mlx_init(data.map.width * 64, data.map.height * 64,
			"Never Gonna Give You Up", true);
	if (!data.mlx)
		ft_exit_error();
	data = ft_gen_map(data);
	mlx_key_hook(data.mlx, ft_movement, ptr);
	mlx_loop_hook(data.mlx, ft_add_coll, ptr);
	mlx_loop_hook(data.mlx, ft_change_exit, ptr);
	mlx_loop(data.mlx);
	mlx_terminate(data.mlx);
	return (EXIT_SUCCESS);
}

int	main(int argc, char *argv[])
{
	int		cnt;
	char	*file_read;
	t_data	data;

	if (argc == 2)
	{
		cnt = 0;
		atexit(ft_leaks);
		data.mlx = 0;
		data = ft_init_data(data);
		file_read = ft_read_file(argv[1]);
		data = ft_get_hw(file_read, data);
		data.map.matrix = ft_create_map(file_read, data.map.height,
				data.map.width);
		ft_create_window(data);
	}
}
