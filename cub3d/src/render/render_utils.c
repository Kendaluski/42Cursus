/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 19:17:52 by jjaen-mo          #+#    #+#             */
/*   Updated: 2024/09/24 17:21:26 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

uint32_t	ft_rgb_to_hex(char *str)
{
	int	rgb[3];
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (!ft_isdigit(str[i]))
		i++;
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]))
		{
			rgb[j] = ft_atoi(&str[i]);
			j++;
			while (ft_isdigit(str[i]))
				i++;
		}
		else
			i++;
	}
	return (rgb[0] << 24 | rgb[1] << 16 | rgb[2] << 8 | 0x000000FF);
}
