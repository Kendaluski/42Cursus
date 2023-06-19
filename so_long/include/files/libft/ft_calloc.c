/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 19:02:14 by jjaen-mo          #+#    #+#             */
/*   Updated: 2023/04/21 19:53:07 by jjaen-mo         ###   ########.fr       */
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
