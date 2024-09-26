/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 13:01:32 by jjaen-mo          #+#    #+#             */
/*   Updated: 2024/09/25 19:04:22 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	ft_init_minimap(t_data *data)
{
	data->minimap = malloc(sizeof(t_minimap));
	data->minimap->px = data->player->posx * 16;
	data->minimap->py = data->player->posy * 16;
	data->minimap->texture = mlx_load_png("textures/m_player.png");
	if (!data->minimap->texture)
	{
		printf("[ERROR] Unable to load minimap player texture\n");
		ft_clean_exit(data);
	}
	data->minimap->player = mlx_texture_to_image(data->mlx,
			data->minimap->texture);
	mlx_delete_texture(data->minimap->texture);
	data->minimap->texture = mlx_load_png("textures/m_wall.png");
	if (!data->minimap->texture)
	{
		printf("[ERROR] Unable to load minimap wall texture\n");
		ft_clean_exit(data);
	}
	data->minimap->wall = mlx_texture_to_image(data->mlx,
			data->minimap->texture);
	mlx_delete_texture(data->minimap->texture);
	data->minimap->dir_line = mlx_new_image(data->mlx, 16, 16);
	ft_draw_minimap(data);
}

void	ft_init_data(t_data *data)
{
	data->player = malloc(sizeof(t_player));
	data->textures = malloc(sizeof(t_textures));
	ft_player_pos(data);
	data->mlx = mlx_init(WIDTH, HEIGHT, "Cub3D", false);
	if (!data->mlx)
	{
		printf("[ERROR] Unable to initialize mlx\n");
		return ;
	}
	ft_load_textures(data);
	data->screen = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	mlx_image_to_window(data->mlx, data->screen, 0, 0);
	ft_init_minimap(data);
	ft_raycasting(data);
	mlx_key_hook(data->mlx, ft_key_hook, data);
	mlx_loop_hook(data->mlx, ft_raycasting, data);
	mlx_loop(data->mlx);
	mlx_close_hook(data->mlx, ft_clean_exit, data);
}

void	ft_init_values(t_data *data)
{
	data->mlx = 0;
	data->screen = 0;
	data->minimap = 0;
	data->player = 0;
	data->c_color = 0;
	data->f_color = 0;
	data->map = 0;
	data->minimap = 0;
	data->textures = 0;
}

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc != 2)
	{
		printf("[ERROR] Wrong argument input\n");
		return (1);
	}
	if (argc == 2)
	{
		if (ft_strncmp(argv[1] + ft_strlen(argv[1]) - 4, ".cub", 4) != 0)
		{
			printf("[ERROR] Invalid file extension\n");
			return (1);
		}
	}
	data = malloc(sizeof(t_data));
	ft_init_values(data);
	if (!ft_parse(argv[1], data))
		return (1);
	printf("Parsing done!\n");
	ft_init_data(data);
	ft_clean_exit(data);
}
