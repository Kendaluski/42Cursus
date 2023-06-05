/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_manage.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 19:48:12 by jjaen-mo          #+#    #+#             */
/*   Updated: 2023/06/05 15:04:54 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

t_data	ft_get_hw(char *map, t_data data)
{
	int	cnt;
	int	cnt2;

	cnt = 0;
	while (map[cnt] != '\n')
		cnt++;
	data.map.width = cnt;
	cnt = 0;
	cnt2 = 0;
	while (map[cnt] != '\0')
	{
		if (map[cnt] == '\n')
			cnt2++;
		cnt++;
	}
	cnt2++;
	data.map.height = cnt2;
	return (data);
}

void	ft_map_error(char type)
{
	if (type == 'n')
		ft_printf("Error: \n Mapa innacesible");
	exit(1);
}

char	*ft_read_file(char *file)
{
	int		fd;
	int		fsize;
	char	*buff;
	char	*file_read;

	fsize = 0;
	buff = malloc(sizeof(char) * 2);
	fd = open(file, O_RDONLY);
	while (read(fd, buff, 1) == 1)
		fsize++;
	free(buff);
	if (fsize == 0)
		ft_map_error('n');
	close(fd);
	fd = open(file, O_RDONLY);
	file_read = malloc(sizeof(char) * fsize + 1);
	read(fd, file_read, fsize);
	file_read[fsize] = '\0';
	close(fd);
	return (file_read);
}

char	**ft_create_map(char *map_arr, int height, int width)
{
	int		cnt;
	int		cnt2;
	int		cnt3;
	char	**matrix;

	cnt = 0;
	cnt3 = 0;
	matrix = malloc(sizeof(char *) * height + 1);
	while (cnt < height && map_arr[cnt3])
	{
		cnt2 = 0;
		matrix[cnt] = malloc(sizeof(char) * width + 1);
		while (map_arr[cnt3] != '\n' && map_arr[cnt3])
		{
			matrix[cnt][cnt2] = map_arr[cnt3];
			cnt2++;
			cnt3++;
		}
		cnt3++;
		matrix[cnt][cnt2] = '\0';
		cnt++;
	}
	matrix[cnt] = 0;
	free(map_arr);
	return (matrix);
}
