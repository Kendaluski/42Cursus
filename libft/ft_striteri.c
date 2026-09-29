/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojaen-m <jojaen-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 11:01:51 by jojaen-m          #+#    #+#             */
/*   Updated: 2026/09/29 19:38:38 by jojaen-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int	cnt;

	cnt = 0;
	if (!f || !s)
		return ;
	while (s[cnt])
	{
		f(cnt, &s[cnt]);
		cnt++;
	}
}
