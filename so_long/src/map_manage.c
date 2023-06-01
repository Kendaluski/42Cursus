/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_manage.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 19:48:12 by jjaen-mo          #+#    #+#             */
/*   Updated: 2023/06/01 13:43:50 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	ft_get_hw(char *map)
{
	int	cnt;
	int	cnt2;

	cnt = 0;
	while (map[cnt] != '\n')
		cnt++;
	g_data.map.width = cnt;
	cnt = 0;
	cnt2 = 0;
	while (map[cnt] != '\0')
	{
		if (map[cnt] == '\n')
			cnt2++;
		cnt++;
	}
	cnt2++;
	g_data.map.height = cnt2;
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
	ft_get_hw(file_read);
	close(fd);
	return (file_read);
}

void	ft_create_map(char *map_arr)
{
	int	cnt;
	int	cnt2;
	int	cnt3;

	cnt = 0;
	cnt2 = 0;
	cnt3 = 0;
	g_data.map.matrix = malloc(sizeof(char *) * g_data.map.height + 1);
	while (cnt < g_data.map.height && map_arr[cnt3])
	{
		cnt2 = 0;
		g_data.map.matrix[cnt] = malloc(sizeof(char) * g_data.map.width + 1);
		while (map_arr[cnt3] != '\n' && map_arr[cnt3])
		{
			g_data.map.matrix[cnt][cnt2] = map_arr[cnt3];
			cnt2++;
			cnt3++;
		}
		cnt3++;
		g_data.map.matrix[cnt][cnt2] = '\0';
		cnt++;
	}
	g_data.map.matrix[cnt] = 0;
	free(map_arr);
}
