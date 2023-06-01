/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 18:27:17 by jjaen-mo          #+#    #+#             */
/*   Updated: 2023/06/01 18:59:35 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H
# include "../MLX42/include/MLX42/MLX42.h"
# include "../include/libs/libft.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_map
{
	char		**matrix;
	int			width;
	int			height;
}				t_map;

typedef struct s_data
{
	mlx_t		*mlx;
	mlx_image_t	*character;
	mlx_image_t	*floor;
	mlx_image_t	*wall;
	mlx_image_t	*coll;
	mlx_image_t	*exit;
	t_map		map;
}				t_data;

t_data			g_data;

void			ft_movement(mlx_key_data_t keydata, void *window);
char			*ft_read_file(char *file);
void			ft_create_map(char *map_arr);
void			ft_exit_error(void);
void			ft_create_textures(void);
void			ft_gen_map(void);
void			ft_wall(int width, int height);
void			ft_floor(int width, int height);
void			ft_player(int width, int height);
void			ft_collectible(int width, int height);
void			ft_exit_img(int width, int height);
#endif