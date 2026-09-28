/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojaen-m <jojaen-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 11:01:55 by jojaen-m          #+#    #+#             */
/*   Updated: 2026/09/28 11:01:56 by jojaen-m         ###   ########.fr       */
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
