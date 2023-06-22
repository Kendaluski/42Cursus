/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 12:35:31 by jjaen-mo          #+#    #+#             */
/*   Updated: 2023/04/21 19:55:00 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
