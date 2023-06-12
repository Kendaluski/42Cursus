/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 18:27:17 by jjaen-mo          #+#    #+#             */
/*   Updated: 2023/06/12 19:40:23 by jjaen-mo         ###   ########.fr       */
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
	mlx_image_t	**enemies;
	t_map		map;
	int			coll_count;
	int			max_colls;
	int			enem_count;
	int			steps;
}				t_data;

t_data			ft_init_data(t_data data);

int				ft_create_window(t_data data);

char			*ft_read_file(char *file);

void			ft_map_error(char type);

t_data			ft_get_hw(char *map, t_data data);

char			**ft_create_map(char *map_arr, int height, int width);

void			ft_exit_error(void);

t_data			ft_gen_map(t_data data);

int				ft_get_max(char **map, char c);

t_data			ft_create_textures(t_data data);

t_data			ft_malloc_colls(t_data data);

void			ft_collectible(int height, int width, t_data data);

void			ft_exit_img(int height, int width, t_data data);

t_data			ft_gen_player(t_data data);

t_data			ft_player(int height, int width, t_data data);

void			ft_movement(mlx_key_data_t keydata, void *data);

int				ft_next_pos(int32_t height, int32_t width, char key,
					char **map);

void			ft_close_window(void *data);

void			ft_open_exit(t_data data);

void			ft_add_coll(void *data);

void			ft_change_exit(void *data);

char			**ft_free(char **map);

void			ft_leaks(void);

void			ft_parse_map(char *map);

void			ft_add_step(t_data *data, int32_t *posx, int32_t *posy,
					char key);

t_data			ft_enemy_texture(t_data data);

void			ft_enemies(t_data data, int width, int height);

void			ft_enemy_touch(t_data data);

void			ft_equal_width(t_data data, int width, int height);

mlx_image_t		*ft_put_steps(t_data *data, char *str, mlx_image_t *steps);

#endif