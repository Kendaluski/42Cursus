/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 19:13:36 by jariza-o          #+#    #+#             */
/*   Updated: 2023/06/18 18:17:35 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_readfile(int fd, char	*buf)
{
	char		*temp;
	int			c;

	temp = ft_calloc_gnl(BUFFER_SIZE + 1, sizeof(char));
	if (temp == NULL)
		return (NULL);
	c = 1;
	while (c > 0 && !ft_strchr_gnl(buf, '\n'))
	{
		c = read(fd, temp, BUFFER_SIZE);
		if (c == -1)
		{
			free(buf);
			free(temp);
			return (NULL);
		}
		if (c == 0)
			break ;
		temp[c] = '\0';
		buf = ft_strjoin_gnl(buf, temp);
	}
	free(temp);
	return (buf);
}

char	*ft_line(char *buf)
{
	int		i;
	char	*line;

	if (!buf || *buf == '\0')
		return (NULL);
	i = 0;
	while (buf[i] != '\n' && buf[i] != '\0')
		i++;
	line = ft_calloc_gnl(i + 2, sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (buf[i] != '\n' && buf[i])
	{
		line[i] = buf[i];
		i++;
	}
	if (buf[i] == '\n')
		line[i] = '\n';
	return (line);
}

char	*ft_removeline(char *buf)
{
	int		i;
	int		x;
	char	*temp;

	i = 0;
	x = 0;
	while (buf[i] != '\n' && buf[i])
		i++;
	if (!buf[i])
	{
		free(buf);
		return (NULL);
	}
	temp = ft_calloc_gnl(ft_strlen_gnl(buf) - i + 1, sizeof(char));
	if (temp == NULL)
		return (NULL);
	i++;
	while (buf[i] != '\0')
	{
		temp[x] = buf[i];
		x++;
		i++;
	}
	free(buf);
	return (temp);
}

char	*get_next_line(int fd)
{
	static char	*buf[1040];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf[fd] = ft_readfile(fd, buf[fd]);
	if (!buf[fd])
		return (NULL);
	line = ft_line(buf[fd]);
	buf[fd] = ft_removeline(buf[fd]);
	return (line);
}
