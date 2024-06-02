/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 12:54:14 by jjaen-mo          #+#    #+#             */
/*   Updated: 2024/06/02 23:25:45 by jjaen-mo         ###   ########.fr       */
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

typedef struct s_data
{
	mlx_t	*mlx;
	mlx_image_t	*character;
	mlx_image_t	*wall;
	mlx_image_t *floor;
	int		playerposx;
	int		playerposy;
	int		steps;
	char	**map;

}			t_data;

void		ft_read_map(char *file, t_data *data);
void		ft_print_map(char **map);
void	ft_gen_map(t_data *data);
void	ft_movement(mlx_key_data_t keydata, void *data);
void	ft_add_step(t_data *data, int32_t *posx, int32_t *posy, char key);

#endif
