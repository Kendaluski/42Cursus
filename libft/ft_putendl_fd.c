/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 21:09:34 by jjaen-mo          #+#    #+#             */
/*   Updated: 2023/04/21 21:11:33 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	int	cnt;

	cnt = 0;
	while (s[cnt] != '\0')
	{
		write(fd, &s[cnt], 1);
		cnt++;
	}
	write(fd, "\n", 1);
}
