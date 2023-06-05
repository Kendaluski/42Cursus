/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 18:27:17 by jjaen-mo          #+#    #+#             */
/*   Updated: 2023/06/05 15:11:00 by jjaen-mo         ###   ########.fr       */
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
	mlx_image_t	**colls;
	mlx_image_t	*exit;
	t_map		map;
	int			coll_count;
	int			max_colls;
}				t_data;

t_data			ft_init_data(t_data data);

int				ft_create_window(t_data data);

char			*ft_read_file(char *file);

void			ft_map_error(char type);

t_data			ft_get_hw(char *map, t_data data);

char			**ft_create_map(char *map_arr, int height, int width);

void			ft_exit_error(void);

t_data			ft_gen_map(t_data data);

int				ft_get_max_colls(char **map);

t_data			ft_create_textures(t_data data);

t_data			ft_malloc_colls(t_data data);

void			ft_collectible(int height, int width, t_data data);

void			ft_exit_img(int height, int width, t_data data);

t_data			ft_gen_player(t_data data);

t_data			ft_player(int height, int width, t_data data);

void			ft_movement(mlx_key_data_t keydata, void *data);

int				ft_next_pos(int32_t height, int32_t width, char key,
					char **map);

void			ft_close_window(t_data data);

void			ft_open_exit(t_data data);

void			ft_add_coll(void *data);

void			ft_change_exit(void *data);

char			**ft_free(char **map);

void			ft_leaks(void);
#endif