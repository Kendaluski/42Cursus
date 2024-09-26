/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 13:53:53 by jjaen-mo          #+#    #+#             */
/*   Updated: 2024/09/25 18:30:25 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	ft_valid_rgb(int n1, int n2, int n3, t_data *data)
{
	if (n1 < 0 || n1 > 255)
	{
		printf("[ERROR] Invalid RGB values\n");
		ft_clean_exit(data);
	}
	if (n2 < 0 || n2 > 255)
	{
		printf("[ERROR] Invalid RGB values\n");
		ft_clean_exit(data);
	}
	if (n3 < 0 || n3 > 255)
	{
		printf("[ERROR] Invalid RGB values\n");
		ft_clean_exit(data);
	}
}

static int	ft_check_empty(char *rgb)
{
	int	i;

	i = 0;
	while (rgb[i] && rgb[i] != '\n')
		i++;
	if (i == 0)
		return (1);
	else if (!ft_isdigit(rgb[i - 1]))
		return (1);
	return (0);
}

static void	ft_check_rgb(char **rgb, t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (rgb[i])
	{
		j = 0;
		if (ft_check_empty(rgb[i]))
		{
			printf("[ERROR] Invalid RGB values\n");
			ft_clean_exit(data);
		}
		while (rgb[i][j])
		{
			if (!ft_isdigit(rgb[i][j]) && rgb[i][j] != '\n')
			{
				printf("[ERROR] Invalid RGB values\n");
				ft_clean_exit(data);
			}
			j++;
		}
		i++;
	}
	ft_valid_rgb(ft_atoi(rgb[0]), ft_atoi(rgb[1]), ft_atoi(rgb[2]), data);
}

static void	ft_check_missing(t_data *data, char **rgb)
{
	if (!rgb[0])
	{
		printf("[ERROR] Missing red color\n");
		ft_clean_exit(data);
	}
	else if (!rgb[1])
	{
		printf("[ERROR] Missing green color\n");
		ft_clean_exit(data);
	}
	else if (!rgb[2])
	{
		printf("[ERROR] Missing blue color\n");
		ft_clean_exit(data);
	}
}

void	ft_to_rgb(t_data *data)
{
	char	**rgb;

	rgb = ft_split(data->map->f, ',');
	if (!rgb)
	{
		printf("[ERROR] Invalid floor color\n");
		ft_free_dp(rgb);
		ft_clean_exit(data);
	}
	ft_check_missing(data, rgb);
	ft_check_rgb(rgb, data);
	data->f_color = ft_rgb_to_hex(data->map->f);
	ft_free_dp(rgb);
	rgb = ft_split(data->map->c, ',');
	if (!rgb)
	{
		printf("[ERROR] Invalid ceiling color\n");
		ft_free_dp(rgb);
		ft_clean_exit(data);
	}
	ft_check_missing(data, rgb);
	data->c_color = ft_rgb_to_hex(data->map->c);
	ft_check_rgb(rgb, data);
	ft_free_dp(rgb);
}
