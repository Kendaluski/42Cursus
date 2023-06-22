/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_solve.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 14:28:39 by jjaen-mo          #+#    #+#             */
/*   Updated: 2023/06/22 22:03:46 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	ft_file_extension(char *file)
{
	int	cnt;

	cnt = ft_strlen(file) - 1;
	if (file[cnt] != 'r' || file[cnt - 1] != 'e' || file[cnt - 2] != 'b'
		|| file[cnt - 3] != '.')
		ft_map_error('e');
}

int	ft_check_solvable(t_data *data, int x, int y, int *trues)
{
	char	pos;

	pos = data->map.matrix[y][x];
	if (pos != '1' && pos != 'T' && pos != 'B')
	{
		if (pos == 'E')
			*trues = 1;
		if (pos == 'C')
			data->coll_count++;
		data->map.matrix[y][x] = 'T';
		if (x + 1 < data->map.width)
			ft_check_solvable(data, x + 1, y, trues);
		if (x - 1 >= 0)
			ft_check_solvable(data, x - 1, y, trues);
		if (y + 1 < data->map.height)
			ft_check_solvable(data, x, y + 1, trues);
		if (y - 1 >= 0)
			ft_check_solvable(data, x, y - 1, trues);
	}
	return (*trues);
}

void	ft_check_walls(char **map, int width, int height)
{
	int	cnt;

	cnt = 0;
	while (cnt < width && map[0][cnt] == '1')
		cnt++;
	if (cnt != width)
		ft_map_error('w');
	cnt = 0;
	while (cnt < width && map[height - 1][cnt] == '1')
		cnt++;
	if (cnt != width)
		ft_map_error('w');
	cnt = 0;
	while (cnt < height && map[cnt][0] == '1')
		cnt++;
	if (cnt != height)
		ft_map_error('w');
	cnt = 0;
	while (cnt < height && map[cnt][width - 1] == '1')
		cnt++;
	if (cnt != height)
		ft_map_error('w');
}
