/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 12:47:02 by jjaen-mo          #+#    #+#             */
/*   Updated: 2023/06/06 19:26:51 by jjaen-mo         ###   ########.fr       */
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

void	ft_close_window(void *data)
{
	t_data	*ptr;

	ptr = data;
	free(ptr->colls);
	free(ptr->enemies);
	ptr->map.matrix = ft_free(ptr->map.matrix);
	mlx_close_window(ptr->mlx);
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
	data.mlx = mlx_init(data.map.width * 64, data.map.height * 64,
			"Never Gonna Give You Up", false);
	if (!data.mlx)
		ft_exit_error();
	data.max_colls = ft_get_max(data.map.matrix, 'C');
	data.enem_count = ft_get_max(data.map.matrix, 'B');
	data = ft_create_textures(data);
	data = ft_gen_map(data);
	mlx_close_hook(data.mlx, ft_close_window, ptr);
	mlx_key_hook(data.mlx, ft_movement, ptr);
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
		ft_parse_map(file_read);
		data = ft_get_hw(file_read, data);
		data.map.matrix = ft_create_map(file_read, data.map.height,
				data.map.width);
		ft_equal_width(data,data.map.width,data.map.height);
		ft_create_window(data);
	}
}
