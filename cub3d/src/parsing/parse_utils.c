/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 13:54:10 by jjaen-mo          #+#    #+#             */
/*   Updated: 2024/09/25 18:36:09 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	ft_load_textures(t_data *data)
{
	data->textures->no = mlx_load_png(data->map->no);
	data->textures->so = mlx_load_png(data->map->so);
	data->textures->we = mlx_load_png(data->map->we);
	data->textures->ea = mlx_load_png(data->map->ea);
	data->textures->wallx = 0;
	data->textures->texx = 0;
	data->textures->color = 0;
}

void	ft_print_info(t_map *map)
{
	printf("NO: %s\n", map->no);
	printf("SO: %s\n", map->so);
	printf("WE: %s\n", map->we);
	printf("EA: %s\n", map->ea);
	printf("F: %d\n", map->f_color);
	printf("C: %d\n", map->c_color);
	printf("Height: %d\n", map->height);
	printf("Width: %d\n", map->width);
	ft_print_map(map->map);
}

static void	ft_path_error(t_data *data)
{
	printf("[ERROR] Invalid texture path\n");
	ft_clean_exit(data);
}

void	ft_get_paths(t_data *data)
{
	int	fd;

	ft_clean_paths(data);
	fd = open(data->map->no, O_RDONLY);
	if (fd == -1)
		ft_path_error(data);
	close(fd);
	fd = open(data->map->so, O_RDONLY);
	if (fd == -1)
		ft_path_error(data);
	close(fd);
	fd = open(data->map->we, O_RDONLY);
	if (fd == -1)
		ft_path_error(data);
	close(fd);
	fd = open(data->map->ea, O_RDONLY);
	if (fd == -1)
		ft_path_error(data);
	close(fd);
}

int	ft_check_dup(t_map *map, char c)
{
	if (c == 'N' && map->no != NULL)
		return (1);
	else if (c == 'S' && map->so != NULL)
		return (1);
	else if (c == 'W' && map->we != NULL)
		return (1);
	else if (c == 'E' && map->ea != NULL)
		return (1);
	else if (c == 'F' && map->f != NULL)
		return (1);
	else if (c == 'C' && map->c != NULL)
		return (1);
	return (0);
}
