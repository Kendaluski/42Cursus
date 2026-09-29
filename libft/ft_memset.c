/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojaen-m <jojaen-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 11:02:25 by jojaen-m          #+#    #+#             */
/*   Updated: 2026/09/28 11:02:26 by jojaen-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, int n)
{
	int		cnt;
	char	*str2;

	str2 = str;
	cnt = 0;
	while (cnt < n)
	{
		str2[cnt] = c;
		cnt++;
	}
	return (str);
}
