/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 16:04:25 by jjaen-mo          #+#    #+#             */
/*   Updated: 2023/06/22 21:56:00 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	ft_equal_width(t_data data, int width, int height)
{
	int	cnt;
	int	cnt2;

	cnt = 0;
	while (cnt < height)
	{
		cnt2 = 0;
		while (data.map.matrix[cnt][cnt2])
			cnt2++;
		if (cnt2 != width)
		{
			ft_printf("Error: \n Mapa con anchos diferentes \n");
			data.map.matrix = ft_free(data.map.matrix);
			free(data.map.matrix);
			exit(1);
		}
		cnt++;
	}
}

int	ft_check_c(char *map)
{
	int	cnt;
	int	c;
	int	width;
	int	height;

	cnt = 0;
	c = 0;
	width = 0;
	height = 1;
	while (map[width] && map[width] != '\n')
		width++;
	while (map[cnt])
	{
		if (map[cnt] == 'C')
			c++;
		if (map[cnt] == '\n')
			height++;
		cnt++;
	}
	if (height == width)
		return (2);
	if (c == 0)
		return (0);
	return (1);
}

int	ft_good_chars(char *map)
{
	int	cnt;
	int	p;
	int	e;

	cnt = 0;
	p = 0;
	e = 0;
	while (map[cnt])
	{
		if (map[cnt] != '1' && map[cnt] != '0' && map[cnt] != 'C'
			&& map[cnt] != 'E' && map[cnt] != 'P' && map[cnt] != '\n')
			return (0);
		if (map[cnt] == 'P')
			p++;
		if (map[cnt] == 'E')
			e++;
		cnt++;
	}
	if (p != 1 || e != 1)
		return (2);
	return (1);
}

void	ft_parse_map(char *map)
{
	int	parsed;

	parsed = 1;
	parsed = ft_good_chars(map);
	if (parsed == 0)
		ft_map_error('c');
	if (parsed == 2)
		ft_map_error('p');
	parsed = ft_check_c(map);
	if (parsed == 0)
		ft_map_error('x');
	if (parsed == 2)
		ft_map_error('r');
}

void	ft_map_error(char type)
{
	if (type == 'n')
		ft_printf("Error: \n Mapa innacesible \n");
	if (type == 'e')
		ft_printf("Error: \n El archivo introducido no es .ber \n");
	if (type == 'c')
		ft_printf("Error: \n Caracteres no válidos \n");
	if (type == 'p')
		ft_printf("Error: \n Mapa sin jugador o sin salida \n");
	if (type == 'x')
		ft_printf("Error: \n Mapa sin coleccionables \n");
	if (type == 'r')
		ft_printf("Error: \n Mapa no rectangular \n");
	if (type == 'w')
		ft_printf("Error: \n Mapa no rodeado por muros \n");
	exit(1);
}
