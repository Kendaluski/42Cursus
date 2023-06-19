/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 18:08:27 by jjaen-mo          #+#    #+#             */
/*   Updated: 2023/04/21 19:53:54 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
