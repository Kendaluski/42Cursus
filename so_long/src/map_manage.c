/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_manage.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 19:48:12 by jjaen-mo          #+#    #+#             */
/*   Updated: 2023/05/31 20:42:42 by jjaen-mo         ###   ########.fr       */
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
	g_map.width = cnt;
	cnt = 0;
	cnt2 = 0;
	while (map[cnt] != '\0')
	{
		if (map[cnt] == '\n')
			cnt2++;
		cnt++;
	}
	cnt2++;
	g_map.height = cnt2;
}

void	ft_map_error(char *type)
{
	(void)type;
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
	if (fsize == 0)
		ft_map_error("null");
	close(fd);
	fd = open(file, O_RDONLY);
	file_read = malloc(sizeof(char) * fsize + 1);
	read(fd, file_read, fsize);
	file_read[fsize] = '\0';
	ft_get_hw(file_read);
	close(fd);
	return (file_read);
}

char	**ft_create_map(char *map_arr)
{
	char	**map;

	map = NULL;
	(void)map_arr;
	return (map);
}
