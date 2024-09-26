/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 05:42:32 by jjaen-mo          #+#    #+#             */
/*   Updated: 2024/09/24 20:30:13 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static char	*ft_remove_last(char *line)
{
	char	*dup;
	int		cnt;

	dup = malloc(sizeof(char) * (ft_strlen(line)));
	cnt = 0;
	while (line[cnt] && cnt < (int)ft_strlen(line) - 1)
	{
		dup[cnt] = line[cnt];
		cnt++;
	}
	dup[cnt] = '\0';
	return (dup);
}

void	ft_clean_paths(t_data *data)
{
	char	*line;

	line = ft_remove_last(data->map->no);
	free(data->map->no);
	data->map->no = ft_strdup(line);
	free(line);
	line = ft_remove_last(data->map->so);
	free(data->map->so);
	data->map->so = ft_strdup(line);
	free(line);
	line = ft_remove_last(data->map->we);
	free(data->map->we);
	data->map->we = ft_strdup(line);
	free(line);
	line = ft_remove_last(data->map->ea);
	free(data->map->ea);
	data->map->ea = ft_strdup(line);
	free(line);
}

static int	ft_check_chars(char **map)
{
	int	cnt;
	int	cnt2;

	cnt = 0;
	while (map[cnt])
	{
		cnt2 = 0;
		while (map[cnt][cnt2])
		{
			if (map[cnt][cnt2] != '1' && map[cnt][cnt2] != '0'
				&& map[cnt][cnt2] != 'N' && map[cnt][cnt2] != 'S'
				&& map[cnt][cnt2] != 'E' && map[cnt][cnt2] != 'W'
				&& map[cnt][cnt2] != ' ')
			{
				printf("[ERROR] Invalid character in map\n");
				return (0);
			}
			cnt2++;
		}
		cnt++;
	}
	return (1);
}

static void	ft_init_map_val(t_map *map)
{
	map->no = NULL;
	map->so = NULL;
	map->we = NULL;
	map->ea = NULL;
	map->f = NULL;
	map->c = NULL;
	map->map = NULL;
	map->height = 0;
	map->width = 0;
}

int	ft_parse(char *argv, t_data *data)
{
	data->map = malloc(sizeof(t_map));
	ft_init_map_val(data->map);
	ft_map_info(argv, data);
	if (!ft_check_chars(data->map->map))
	{
		ft_clean_exit(data);
		return (0);
	}
	ft_map_tests(data, data->map);
	return (1);
}
