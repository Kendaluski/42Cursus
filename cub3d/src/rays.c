/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 17:54:47 by jjaen-mo          #+#    #+#             */
/*   Updated: 2024/06/12 19:51:45 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void ft_print_line(int px, int py, int rx, int ry, t_data *data)
{
    int x;
    int y;
    int dx;
    int dy;

    x = px;
    y = py;
    dx = rx;
    dy = ry;
    // mlx_delete_image(data->mlx,data->full);
    // data->full = mlx_new_image(data->mlx, 2048, 1024);
    // mlx_image_to_window(data->mlx, data->full, 0, 0);
    while(x != dx && y != dy)
    {
        printf("x: %d y: %d dx: %d dy: %d\n", x / 128, y / 128, dx / 128, dy / 128);
        mlx_put_pixel(data->full, x, y, 0xfff4b2);
        if(x < dx)
            x += 1;
        else if(x > dx)
            x -= 1;
        if(y < dy)
            y += 1;
        else if(y > dy)
            y -= 1;
    }
}


void drawRays3D(void *tdata)
{
    int r,mx,my,mp,dof;
    double rx,ry,ra,xo,yo;
    t_data *data;

    data = tdata;
    ra = data->pangle;
    xo = 0;
    yo = 0;
    data->playerposx = data->character->instances[0].x;
    data->playerposy = data->character->instances[0].y;
    for(r = 0; r < 1; r++)
    {
        dof = 0;
        double aTan=-1/tan(ra);
        if(ra > PI)
        {
            ry = (((int)data->playerposy>>6)<<6) - 0.0001;
            rx = (data->playerposy - ry) * aTan + data->playerposx;
            yo=-64;
            xo=-yo*aTan;
        }
        if (ra < PI)
        {
            ry = (((int)data->playerposy>>6)<<6) + 64;
            rx = (data->playerposy - ry) * aTan + data->playerposx;
            yo= 64;
            xo= -yo*aTan;
        }
        if (ra == 0 || ra == PI)
        {
            rx = data->playerposx;
            ry = data->playerposy;
            dof = 8;
        }
        while(dof < 8)
        {
            mx = (int)(rx)>>6;
            my = (int)(ry)>>6;
            mp = my * data->mapx + mx;
            if(mp < data->mapx * data->mapy && data->map[my][mx] == '1')
            {
                //printf("mx: %d my: %d mp: %d\n", mx, my, mp);
                dof = 8;
            }
            else
            {
                rx += xo;
                ry += yo;
                dof += 1;
            }
        }
    }
}
