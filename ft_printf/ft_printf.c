/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 13:39:24 by jjaen-mo          #+#    #+#             */
/*   Updated: 2023/05/09 16:44:14 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_printf(const char *str, ...)
{
	va_list	lst;
	int		cnt;
	int		chars;

	cnt = 0;
	chars = 0;
	va_start(lst, str);
	while (str[cnt])
	{
		if (str[cnt] != '%')
			write(1, &str[cnt], 1);
		else if (str[cnt + 1] == 's')
		{
			chars = chars + ft_putstr(va_arg(lst, char *));
			cnt++;
		}
		else if (str[cnt + 1] == 'p')
		{
			chars = chars + ft_putptr(va_arg(lst, unsigned long int));
			cnt++;
		}
		else if (str[cnt + 1] == 'x' || str[cnt + 1] == 'X')
		{
			chars = chars + ft_puthex(str[cnt + 1], va_arg(lst, unsigned int));
			cnt++;
		}
		else if (str[cnt + 1] == 'u')
		{
			chars = chars + ft_putud(va_arg(lst, unsigned int));
			cnt++;
		}
		else
		{
			chars = chars + ft_check_format(str[cnt + 1], va_arg(lst, int));
			cnt++;
		}
		cnt++;
	}
	chars = chars + ft_countchars(str);
	va_end(lst);
	return (chars);
}
int	main(void)
{
	int a = ft_printf(" %%%% ");
	ft_printf("\n%i\n", a);
	int b = printf(" %% ");
	printf("\n%i", b);
}