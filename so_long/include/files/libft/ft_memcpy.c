/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 18:43:48 by jjaen-mo          #+#    #+#             */
/*   Updated: 2023/04/21 19:53:45 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memcpy(void *dst, const void *src, int size)
{
	int			cnt;
	char		*str;
	const char	*str2;

	cnt = 0;
	str = dst;
	str2 = src;
	if (!str && !str2)
		return (0);
	while (cnt < size)
	{
		str[cnt] = str2[cnt];
		cnt++;
	}
	return (dst);
}
