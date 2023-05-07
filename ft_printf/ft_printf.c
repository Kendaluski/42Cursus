/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 13:39:24 by jjaen-mo          #+#    #+#             */
/*   Updated: 2023/05/05 15:44:21 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

int	ft_putstr(char *str);
int	ft_check_format(char c, int a);
int	ft_countchars(const char *str);

int	ft_printf(char const *str, ...)
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
		else
		{
			chars = chars + ft_check_format(str[cnt + 1], va_arg(lst, int));
			cnt++;
		}
		cnt++;
	}
	chars = chars + ft_countchars(str);
	return (chars);
}

int	main(void)
{
	int a;
	char b;
	char *c;

	b = 'c';
	c = &b;
	a = ft_printf("%p", &b);
	printf("\n%i", a);
}