/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojaen-m <jojaen-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 11:01:20 by jojaen-m          #+#    #+#             */
/*   Updated: 2026/09/28 11:01:22 by jojaen-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
