/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 16:34:51 by jjaen-mo          #+#    #+#             */
/*   Updated: 2023/05/30 19:11:32 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_get_line(char *stack)
{
	char	*line;
	int		cnt;

	if (!stack[0])
		return (NULL);
	cnt = 0;
	while (stack[cnt] && stack[cnt] != '\n')
		cnt++;
	line = malloc(sizeof(char) * (cnt + 2));
	if (!line)
		return (0);
	cnt = 0;
	while (stack[cnt] && stack[cnt] != '\n')
	{
		line[cnt] = stack[cnt];
		cnt++;
	}
	if (stack[cnt] == '\n')
	{
		line[cnt] = stack[cnt];
		cnt++;
	}
	line[cnt] = 0;
	return (line);
}

char	*ft_stack_refill(char *stack)
{
	int		cnt;
	int		cnt2;
	char	*new_stack;

	cnt = 0;
	cnt2 = 0;
	while (stack[cnt] && stack[cnt] != '\n')
		cnt++;
	if (!stack[cnt])
	{
		free(stack);
		return (0);
	}
	new_stack = malloc(ft_strlen(stack) - cnt + 1);
	if (!new_stack)
		return (NULL);
	cnt++;
	while (stack[cnt])
		new_stack[cnt2++] = stack[cnt++];
	new_stack[cnt2] = '\0';
	free(stack);
	return (new_stack);
}

char	*ft_read_file(char *stack, int fd)
{
	char	*buff;
	int		chars;

	buff = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buff)
		return (0);
	chars = 1;
	while (!ft_strchr(stack, '\n') && chars != 0)
	{
		chars = read(fd, buff, BUFFER_SIZE);
		if (chars == -1)
			return (free(buff), free(stack), NULL);
		buff[chars] = '\0';
		stack = ft_strjoin(buff, stack);
	}
	free(buff);
	return (stack);
}

char	*get_next_line(int fd)
{
	static char	*stack[FD_MAX];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	stack[fd] = ft_read_file(stack[fd], fd);
	if (!stack[fd])
		return (NULL);
	line = ft_get_line(stack[fd]);
	stack[fd] = ft_stack_refill(stack[fd]);
	return (line);
}
