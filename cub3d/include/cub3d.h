/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 12:54:14 by jjaen-mo          #+#    #+#             */
/*   Updated: 2024/09/25 18:51:51 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "MLX42/include/MLX42/MLX42.h"
# include "libft/libft.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define WIDTH 1706
# define HEIGHT 960

typedef struct s_textures
{
	mlx_texture_t	*no;
	mlx_texture_t	*so;
	mlx_texture_t	*we;
	mlx_texture_t	*ea;
	mlx_texture_t	*use;
	double			wallx;
	int				texx;
	uint32_t		color;
}					t_textures;

typedef struct s_map
{
	char			*no;
	char			*so;
	char			*we;
	char			*ea;
	char			*f;
	uint32_t		f_color;
	char			*c;
	uint32_t		c_color;
	char			**map;
	int				height;
	int				width;
	char			p;
}					t_map;

typedef struct s_minimap
{
	int				width;
	int				height;
	double			px;
	double			py;
	mlx_image_t		*player;
	mlx_image_t		*wall;
	mlx_image_t		*dir_line;
	mlx_texture_t	*texture;
}					t_minimap;

typedef struct s_player
{
	double			posx;
	double			posy;
	double			dirx;
	double			diry;
	double			planex;
	double			planey;
	double			camerax;
	double			rdx;
	double			rdy;
	double			sidedistx;
	double			sidedisty;
	double			ddx;
	double			ddy;
	int				mapx;
	int				mapy;
	double			perpwalldist;
	int				stepx;
	int				stepy;
	int				hit;
	int				side;
	int				lineheight;
	int				drawstart;
	int				drawend;
	double			olddirx;
	double			oldplanex;
}					t_player;

typedef struct s_data
{
	mlx_t			*mlx;
	mlx_image_t		*screen;
	t_minimap		*minimap;
	t_player		*player;
	uint32_t		c_color;
	uint32_t		f_color;
	t_textures		*textures;
	t_map			*map;
}					t_data;

void				ft_read_map(char *file, t_data *data);
void				ft_print_map(char **map);
void				ft_get_hw(t_map *map);
int					ft_parse(char *argv, t_data *data);
void				ft_clean_map(t_map *map);
void				ft_map_info(char *argv, t_data *data);
char				**ft_free_dp(char **map);
void				ft_map_tests(t_data *data, t_map *map);
int					ft_check_dup(t_map *map, char c);
void				ft_player_pos(t_data *data);
void				ft_clean_exit(void *d);
void				ft_get_paths(t_data *data);
void				ft_clean_paths(t_data *data);
void				ft_to_rgb(t_data *data);
void				ft_print_info(t_map *map);
void				ft_key_hook(mlx_key_data_t key, void *d);
void				ft_raycasting(void *d);
uint32_t			ft_rgb_to_hex(char *str);
void				ft_draw_minimap(t_data *data);
void				ft_fill_canvas(t_data *data);
void				ft_gen_cealing(t_data *data);
void				ft_gen_floor(t_data *data);
void				ft_load_textures(t_data *data);
void				ft_leaks(void);
void				ft_up(t_data *data);
void				ft_down(t_data *data);
void				ft_left(t_data *data);
void				ft_right(t_data *data);
void				ft_next_pos2(t_data *data, char c, double *nextX,
						double *nextY);
void				ft_calculate_deltas(t_player *player);
void				ft_texture_calc(t_data *data, t_player *player,
						t_textures *textures, int x);
void				ft_clear_screen(mlx_image_t *screen);

#endif
