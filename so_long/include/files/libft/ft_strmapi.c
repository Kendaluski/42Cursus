/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 19:52:32 by jjaen-mo          #+#    #+#             */
/*   Updated: 2023/04/21 20:34:30 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		cnt;
	char	*str;
	int		size;

	size = ft_strlen(s);
	str = malloc(size * sizeof(char) + 1);
	if (!str)
		return (0);
	cnt = 0;
	while (s[cnt])
	{
		str[cnt] = f(cnt, s[cnt]);
		cnt++;
	}
	str[cnt] = '\0';
	return (str);
}
