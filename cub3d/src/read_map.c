/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 18:44:52 by jjaen-mo          #+#    #+#             */
/*   Updated: 2024/06/11 10:55:16 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void ft_get_hw(t_data *data)
{
    int cnt;
    int cnt2;

    cnt = 0;
    while(data->map[cnt])
        cnt++;
    cnt2 = 0;
    while(data->map[0][cnt2])
        cnt2++;
    data->mapx = cnt2 - 1;
    data->mapy = cnt - 1;
}

int ft_get_size(char *file)
{
    int fd;
    int size;
    char *c;

    size = 0;
    c = malloc(sizeof(char) * 1);
    fd = open(file, O_RDONLY);
    if(fd == -1)
    {
        printf("[ERROR] File not found\n");
        return (0);
    }
    while(read(fd, c, 1))
        size++;
    close(fd);
    free(c);
    return (size);
}

void ft_print_map(char **map)
{
    int cnt;

    cnt = 0;
    while(map[cnt])
    {
        printf("%s", map[cnt]);
        cnt++;
    }
}

void ft_read_map(char *file, t_data *data)
{
    int fd;
    int cnt;
    char *line;
    int size;

    size = ft_get_size(file);
    cnt = 0;
    fd = open(file, O_RDONLY);
    if (fd == -1)
    {
        printf("[ERROR] File not found\n");
        return ;
    }
    data->map = malloc(sizeof(char *) * size);
    while(line != NULL)
    {
        line = get_next_line(fd);
        data->map[cnt] = ft_strdup(line);
        free(line);
        cnt++;
    }
    data->map[cnt] = NULL;
    free(line);
    close(fd);
}
