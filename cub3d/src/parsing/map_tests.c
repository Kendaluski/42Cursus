/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_tests.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 07:54:37 by jjaen-mo          #+#    #+#             */
/*   Updated: 2024/09/24 18:03:24 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	ft_surroundings(t_data *data, t_map *map, int i, int j)
{
	if (i == 0 || j == 0 || !map->map[i + 1][j + 1] || !map->map[i][j + 1]
		|| !map->map[i + 1][j] || i == map->height - 1 || j == map->width - 1)
	{
		printf("[ERROR] Invalid map\n");
		ft_clean_exit(data);
	}
	if ((map->map[i + 1][j] != '1' && map->map[i + 1][j] != '0' && map->map[i
			+ 1][j] != 'N' && map->map[i + 1][j] != 'S' && map->map[i
			+ 1][j] != 'E' && map->map[i + 1][j] != 'W') || (map->map[i
			- 1][j] != '1' && map->map[i - 1][j] != '0' && map->map[i
			- 1][j] != 'N' && map->map[i - 1][j] != 'S' && map->map[i
			- 1][j] != 'E' && map->map[i - 1][j] != 'W') || (map->map[i][j
			+ 1] != '1' && map->map[i][j + 1] != '0' && map->map[i][j
			+ 1] != 'N' && map->map[i][j + 1] != 'S' && map->map[i][j
			+ 1] != 'E' && map->map[i][j + 1] != 'W') || (map->map[i][j
			- 1] != '1' && map->map[i][j - 1] != '0' && map->map[i][j
			- 1] != 'N' && map->map[i][j - 1] != 'S' && map->map[i][j
			- 1] != 'E' && map->map[i][j - 1] != 'W'))
	{
		printf("[ERROR] Invalid map\n");
		ft_clean_exit(data);
	}
}

static void	ft_is_surrounded(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map->map[i])
	{
		j = 0;
		while (data->map->map[i][j])
		{
			if (data->map->map[i][j] == '0')
				ft_surroundings(data, data->map, i, j);
			j++;
		}
		i++;
	}
}

static void	ft_dup_chars(t_data *data, t_map *map)
{
	int	cnt;
	int	cnt2;
	int	c;

	cnt = 0;
	c = 0;
	while (map->map[cnt])
	{
		cnt2 = 0;
		while (map->map[cnt][cnt2])
		{
			if (map->map[cnt][cnt2] == 'N' || map->map[cnt][cnt2] == 'S'
				|| map->map[cnt][cnt2] == 'E' || map->map[cnt][cnt2] == 'W')
				c++;
			cnt2++;
		}
		cnt++;
	}
	if (c != 1)
	{
		printf("[ERROR] Invalid or missing player position\n");
		ft_clean_exit(data);
	}
	ft_is_surrounded(data);
}

void	ft_map_tests(t_data *data, t_map *map)
{
	if (!map->no || !map->so || !map->we || !map->ea || !map->f || !map->c
		|| !map->map)
	{
		printf("[ERROR] Missing information in map\n");
		ft_clean_exit(data);
	}
	if (map->height == 0 || map->width == 0)
	{
		printf("[ERROR] Invalid map size\n");
		ft_clean_exit(data);
	}
	if (map->no[0] == '\0' || map->so[0] == '\0' || map->we[0] == '\0'
		|| map->ea[0] == '\0' || map->f[0] == '\0' || map->c[0] == '\0')
	{
		printf("[ERROR] Invalid texture path\n");
		ft_clean_exit(data);
	}
	if (map->map[0] == NULL || map->map[0][0] == '\0')
	{
		printf("[ERROR] Invalid map\n");
		ft_clean_exit(data);
	}
	ft_dup_chars(data, map);
}
