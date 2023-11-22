/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 15:46:54 by jariza-o          #+#    #+#             */
/*   Updated: 2022/09/26 18:46:17 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	c;

	c = 0;
	if (n == 0)
		return (0);
	while (s1[c] == s2[c] && s1[c] != '\0' && s2[c] != '\0')
	{
		if (c < (n - 1))
			c++;
		else
			return (0);
	}
	return ((unsigned char)(s1[c]) - (unsigned char)(s2[c]));
}
