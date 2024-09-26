/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 18:37:04 by jariza-o          #+#    #+#             */
/*   Updated: 2022/10/03 23:24:58 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		count;

	count = 0;
	while (s[count] != '\0')
		count++;
	while (count > 0)
	{
		if (s[count] == (char)c)
			return ((char *)&s[count]);
		count--;
	}
	if ((char)c == s[count])
		return ((char *)&s[count]);
	return (NULL);
}
