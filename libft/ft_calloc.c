/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojaen-m <jojaen-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 11:04:13 by jojaen-m          #+#    #+#             */
/*   Updated: 2026/09/28 11:04:14 by jojaen-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*ptr;
	size_t	cnt;

	ptr = malloc(count * size);
	if (ptr)
	{
		cnt = 0;
		while (cnt < count * size)
		{
			ptr[cnt] = 0;
			cnt++;
		}
	}
	return (ptr);
}
