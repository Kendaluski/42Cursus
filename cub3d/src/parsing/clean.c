/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 06:59:02 by jjaen-mo          #+#    #+#             */
/*   Updated: 2024/09/25 19:02:43 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	ft_clean_mlx(t_data *data)
{
	if (data->textures)
	{
		if (data->textures->no)
			mlx_delete_texture(data->textures->no);
		if (data->textures->so)
			mlx_delete_texture(data->textures->so);
		if (data->textures->we)
			mlx_delete_texture(data->textures->we);
		if (data->textures->ea)
			mlx_delete_texture(data->textures->ea);
		free(data->textures);
	}
	if (data->screen)
		mlx_delete_image(data->mlx, data->screen);
	if (data->player)
		free(data->player);
	if (data->mlx)
		free(data->mlx);
}

void	ft_clean_map(t_map *map)
{
	if (map->no)
		free(map->no);
	if (map->so)
		free(map->so);
	if (map->we)
		free(map->we);
	if (map->ea)
		free(map->ea);
	if (map->f)
		free(map->f);
	if (map->c)
		free(map->c);
	if (map->map)
		map->map = ft_free_dp(map->map);
	free(map);
}

void	ft_clean_exit(void *d)
{
	t_data	*data;

	data = d;
	ft_clean_map(data->map);
	if (data->minimap)
	{
		if (data->minimap->player)
			mlx_delete_image(data->mlx, data->minimap->player);
		if (data->minimap->wall)
			mlx_delete_image(data->mlx, data->minimap->wall);
		if (data->minimap->texture)
			mlx_delete_texture(data->minimap->texture);
		mlx_delete_image(data->mlx, data->minimap->dir_line);
		free(data->minimap);
	}
	ft_clean_mlx(data);
	if (data)
		free(data);
	exit(0);
}
