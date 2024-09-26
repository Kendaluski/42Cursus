/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 18:44:52 by jjaen-mo          #+#    #+#             */
/*   Updated: 2024/09/24 18:49:01 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

char	**ft_free_dp(char **map)
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

static char	**ft_clear_map(char **map)
{
	int		cnt;
	int		size;
	char	**map_cpy;

	cnt = 0;
	while (map[cnt] && map[cnt][0] != '1')
	{
		if (map[cnt][0] == ' ')
			break ;
		cnt++;
	}
	size = cnt;
	while (map[cnt])
		cnt++;
	map_cpy = malloc(sizeof(char *) * (cnt - size + 1));
	cnt = 0;
	while (map[size])
	{
		map_cpy[cnt] = ft_strdup(map[size]);
		cnt++;
		size++;
	}
	ft_free_dp(map);
	map_cpy[cnt] = NULL;
	return (map_cpy);
}

void	ft_get_hw(t_map *map)
{
	int	cnt;
	int	cnt2;
	int	w;

	cnt = 0;
	while (map->map[cnt])
		cnt++;
	cnt = 0;
	w = 0;
	while (map->map[cnt])
	{
		cnt2 = 0;
		while (map->map[cnt][cnt2])
			cnt2++;
		if (cnt2 > w)
			w = cnt2;
		cnt++;
	}
	map->height = cnt;
	map->width = w;
}

void	ft_print_map(char **map)
{
	int	cnt;

	cnt = 0;
	while (map[cnt])
	{
		printf("%s\n", map[cnt]);
		cnt++;
	}
}

void	ft_read_map(char *file, t_data *data)
{
	int		fd;
	char	*line;
	char	*line2;

	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	line2 = ft_strdup("");
	while (line)
	{
		line2 = ft_strjoin_gnl(line2, line);
		line2 = ft_strjoin_gnl(line2, "\n");
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	data->map->map = ft_split(line2, '\n');
	data->map->map = ft_clear_map(data->map->map);
	free(line2);
	ft_get_hw(data->map);
}
