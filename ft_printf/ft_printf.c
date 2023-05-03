/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 13:39:24 by jjaen-mo          #+#    #+#             */
/*   Updated: 2023/05/03 15:56:52 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

int	ft_char(char argl);
int	ft_string(char *str);
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
		else if (str[cnt] == '%' && str[cnt + 1] == 'c')
		{
			chars = chars + ft_char(va_arg(lst, int));
			cnt++;
		}
		else if (str[cnt] == '%' && str[cnt + 1] == '%')
		{
			write(1, "%", 1);
			cnt++;
		}
		else if (str[cnt + 1] == 's')
		{
			chars = chars + ft_string(va_arg(lst, char *));
			cnt++;
		}
		else if (str[cnt + 1] == 'i')
		{
			//chars = chars + ft_int(str[cnt + 1], va_arg(lst, int));
		}
		cnt++;
	}
	chars = chars + cnt;
	return (chars);
}

int	main(void)
{
	int a;

	a = ft_printf("%s", "hola");
	printf("\n%i", a);
}