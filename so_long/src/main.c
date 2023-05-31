/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 12:47:02 by jjaen-mo          #+#    #+#             */
/*   Updated: 2023/05/31 13:54:25 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libs/libft.h"
#include "../MLX42/include/MLX42/MLX42.h"
#define WIDTH 256
#define HEIGHT 256

static void ft_exit_error(void)
{
	ft_printf("%s", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

static void ft_print_size(void *param)
{
	const mlx_t *mlx=param;
	ft_printf("WIDTH: %d | HEIGHT: %d\n", mlx->width, mlx->height);
}
int main(void)
{
	//define that window'll be maximized
	mlx_set_setting(MLX_MAXIMIZED, false);
	mlx_t *mlx = mlx_init(WIDTH,HEIGHT,"Test_Chema", true);
	if(!mlx)
		ft_exit_error();
	mlx_image_t *img = mlx_new_image(mlx,WIDTH,HEIGHT);
	if(!img || (mlx_image_to_window(mlx, img, 0, 0) < 0))
		ft_exit_error();
	mlx_loop_hook(mlx,ft_print_size, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}