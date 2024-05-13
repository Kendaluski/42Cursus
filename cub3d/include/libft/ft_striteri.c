/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 13:15:42 by jariza-o          #+#    #+#             */
/*   Updated: 2023/11/15 15:53:28 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	n;

	n = 0;
	if (!(s == NULL && f == NULL))
	{
		while (s[n] != '\0')
		{
			f(n, &s[n]);
			n++;
		}
	}
}
