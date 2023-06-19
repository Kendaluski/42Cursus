/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 12:39:02 by jjaen-mo          #+#    #+#             */
/*   Updated: 2023/04/21 19:54:49 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	cnt;

	cnt = 0;
	while ((s1[cnt] != '\0' || s2[cnt] != '\0') && cnt < n)
	{
		if ((unsigned char)s1[cnt] > (unsigned char)s2[cnt])
			return (1);
		if ((unsigned char)s1[cnt] < (unsigned char)s2[cnt])
			return (-1);
		cnt++;
	}
	return (0);
}
