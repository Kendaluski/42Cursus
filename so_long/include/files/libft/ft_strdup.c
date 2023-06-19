/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 19:26:36 by jjaen-mo          #+#    #+#             */
/*   Updated: 2023/04/21 19:54:04 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		cnt;
	int		size;
	char	*res;

	size = ft_strlen(s1);
	res = (char *)malloc(size * (sizeof(char)) + 1);
	if (!res)
		return (0);
	cnt = 0;
	while (cnt < size)
	{
		res[cnt] = s1[cnt];
		cnt++;
	}
	res[cnt] = '\0';
	return (res);
}
