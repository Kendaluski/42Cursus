/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 17:54:47 by jjaen-mo          #+#    #+#             */
/*   Updated: 2024/06/11 11:13:53 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void drawRays3D(void *tdata)
{
    int r,mx,my,mp,dof;
    double rx,ry,ra,xo,yo;
    t_data *data;

    data = tdata;
    ra = data->pangle;
    xo = 0;
    yo = 0;
    printf("ra: %f\n", ra);
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
                printf("mx: %d my: %d mp: %d\n", mx, my, mp);
                dof = 8;
            }
            else
            {
                rx += xo;
                ry += yo;
                dof += 1;
            }
            printf("rx: %f ry: %f pangle: %f\n", rx, ry, data->pangle);
        }
    }
}
