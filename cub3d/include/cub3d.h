/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 12:54:14 by jjaen-mo          #+#    #+#             */
/*   Updated: 2024/06/11 10:04:23 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft/libft.h"
# include "MLX42/include/MLX42/MLX42.h"
# include <fcntl.h>
# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

# define PI 3.14159265358979323846
# define WIDTH 800
# define HEIGHT 600

typedef struct s_line
{
	int x0;
	int y0;
	int x1;
	int y1;
}		t_line;

typedef struct s_windows
{
	void *mlx;
	void *win;
	void *img;
	int *data;
	int bpp;
	int size_l;
	int endian;
}	t_windows;

typedef struct s_map
{
	int map_high;
	int map_wide;
	int img_high;
	int img_wide;
	int dx;
	int dy;
}	t_map;

typedef struct s_data
{
	mlx_t	*mlx;
	mlx_image_t	*character;
	mlx_image_t	*wall;
	mlx_image_t *floor;
	mlx_image_t *full;
	double		playerposx;
	double		playerposy;
	double		deltax;
	double		deltay;
	double		pangle;
	char	**map;
	int		mapx;
	int		mapy;
}			t_data;

void		ft_read_map(char *file, t_data *data);
void		ft_print_map(char **map);
void	ft_gen_map(t_data *data);
void	draw_ray_minimap_y(t_data *data);
void ft_get_hw(t_data *data);
void drawRays3D(void *tdata);

#endif
