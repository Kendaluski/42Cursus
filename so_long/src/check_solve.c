/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_solve.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 14:28:39 by jjaen-mo          #+#    #+#             */
/*   Updated: 2023/06/14 14:38:42 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void ft_file_extension(char *file)
{
	int cnt;

	cnt = ft_strlen(file) - 1;
	if(file[cnt] != 'r' || file[cnt - 1] != 'e' || file[cnt - 2] != 'b' || file[cnt - 3] != '.')
		ft_map_error('e');
}

void ft_check_solvable(t_data data)
{
	char **map;
	int cnt;
	int cnt2;
	
	map = data.map.matrix;
	cnt = 0;
	while(map[cnt])
	{
		cnt2 = 0;
		while(map[cnt2]) 
		{
			cnt2++;
		}
		cnt++;
	}
}