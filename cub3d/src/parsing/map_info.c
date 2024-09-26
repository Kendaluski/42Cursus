/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 05:22:47 by jjaen-mo          #+#    #+#             */
/*   Updated: 2024/09/25 18:30:42 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	ft_full_info(t_data *data)
{
	if (!data->map->no || !data->map->so || !data->map->we || !data->map->ea
		|| !data->map->f || !data->map->c || !data->map->map)
	{
		printf("[ERROR] Missing information in map\n");
		ft_clean_exit(data);
	}
	ft_to_rgb(data);
}

static void	ft_rgb_info(char *line, t_map *map, char c)
{
	int	cnt;

	cnt = 0;
	while (line[cnt] == ' ')
		cnt++;
	while (line[cnt])
	{
		if (line[cnt] == 'F' || line[cnt] == 'C')
		{
			cnt++;
			while (line[cnt] == ' ' || line[cnt] == '\n' || line[cnt] == '\0')
				cnt++;
			break ;
		}
		cnt++;
	}
	if (line[cnt] == '\0' || line[cnt] == '\n')
		return ;
	else
	{
		if (c == 'F' && map->f == NULL)
			map->f = ft_strdup(line + cnt);
		else if (c == 'C' && map->c == NULL)
			map->c = ft_strdup(line + cnt);
	}
}

static void	ft_get_info(char *line, t_data *data, char c)
{
	int	cnt;

	cnt = 0;
	if (ft_check_dup(data->map, c))
	{
		printf("[ERROR] Duplicate texture info\n");
		ft_clean_exit(data);
	}
	if (c == 'F' || c == 'C')
		ft_rgb_info(line, data->map, c);
	while (line[cnt] && line[cnt] != ' ')
		cnt++;
	cnt++;
	while (line[cnt] && line[cnt] == ' ')
		cnt++;
	if (line[cnt] == '\0')
		return ;
	if (c == 'N')
		data->map->no = ft_strdup(line + (cnt));
	else if (c == 'S' && data->map->so == NULL)
		data->map->so = ft_strdup(line + (cnt));
	else if (c == 'W' && data->map->we == NULL)
		data->map->we = ft_strdup(line + (cnt));
	else if (c == 'E' && data->map->ea == NULL)
		data->map->ea = ft_strdup(line + (cnt));
}

static void	ft_extract_info(t_data *data, char *line)
{
	int	cnt;

	cnt = 0;
	while (line[cnt] == ' ')
		cnt++;
	if (line[cnt] == 'N' && !data->map->no)
		ft_get_info(line + cnt, data, 'N');
	else if (line[cnt] == 'S' && !data->map->so)
		ft_get_info(line + cnt, data, 'S');
	else if (line[cnt] == 'W' && !data->map->we)
		ft_get_info(line + cnt, data, 'W');
	else if (line[cnt] == 'E' && !data->map->ea)
		ft_get_info(line + cnt, data, 'E');
	else if (line[cnt] == 'F' && !data->map->f)
		ft_get_info(line + cnt, data, 'F');
	else if (line[cnt] == 'C' && !data->map->c)
		ft_get_info(line + cnt, data, 'C');
	else if (line[cnt] != '1' && line[cnt] != ' ' && line[cnt] != '\0'
		&& line[cnt] != '\n')
	{
		printf("[ERROR] Extra information in map\n");
		ft_clean_exit(data);
	}
}

void	ft_map_info(char *argv, t_data *data)
{
	int		fd;
	char	*line;

	fd = open(argv, O_RDONLY);
	if (fd == -1)
	{
		printf("[ERROR] File not found\n");
		return ;
	}
	line = get_next_line(fd);
	while (line)
	{
		ft_extract_info(data, line);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	ft_read_map(argv, data);
	ft_full_info(data);
	ft_get_paths(data);
}
