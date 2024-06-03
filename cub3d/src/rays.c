/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 17:54:47 by jjaen-mo          #+#    #+#             */
/*   Updated: 2024/06/03 18:06:55 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void drawRays3D(t_data *data)
{
    int r,mx,my,mp,dof;
    double rx,ry,ra,xo,yo;

    ra = data->pangle;
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
            yo=64;
            xo=-yo*aTan;
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
            if(mp < data->mapx * data->mapy && data->map[mp][0] == '1')
            {
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