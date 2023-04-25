/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 17:56:53 by jjaen-mo          #+#    #+#             */
/*   Updated: 2023/04/21 19:54:22 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(const char *str)
{
	int	cnt;

	cnt = 0;
	while (str[cnt] != 0)
		cnt++;
	return (cnt);
}
