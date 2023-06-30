/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 17:35:02 by jjaen-mo          #+#    #+#             */
/*   Updated: 2023/04/21 19:53:36 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t		cnt;
	const char	*str;

	str = s;
	cnt = 0;
	while (cnt < n)
	{
		if ((unsigned char)str[cnt] == (unsigned char)c)
			return ((void *)&str[cnt]);
		cnt++;
	}
	return (0);
}
