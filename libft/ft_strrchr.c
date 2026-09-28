/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojaen-m <jojaen-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 11:01:08 by jojaen-m          #+#    #+#             */
/*   Updated: 2026/09/28 11:01:09 by jojaen-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int	cnt;

	cnt = 0;
	while (str[cnt] != '\0')
		cnt++;
	while (cnt > 0 && str[cnt] != (char)c)
		cnt--;
	if (str[cnt] == (char)c)
		return ((char *)&str[cnt]);
	return (0);
}
