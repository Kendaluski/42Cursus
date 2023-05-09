/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 13:39:24 by jjaen-mo          #+#    #+#             */
/*   Updated: 2023/05/09 19:00:38 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
int	ft_format_number(char c, unsigned int a);

int ft_check_format(va_list params, char c)
{
	if(c == 'c')
		return(ft_putchar(va_arg(params,int)));
	if(c == 's')
		return(ft_putstr(va_arg(params,char *)));
	if(c == 'p')
		return(ft_putptr(va_arg(params,unsigned long int)));
	if(c == 'd' || c == 'i')
		return(ft_putnbr(va_arg(params, int)));
	if(c == 'u' || c == 'x' || c == 'X')
		return(ft_format_number(c,va_arg(params,unsigned int)));
	if(c == '%')
		return(ft_putchar('%'));
}

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
		{
			write(1, &str[cnt], 1);
			chars++;
		}
		else
		{
			chars = chars + ft_check_format(lst,str[cnt+1]);
			cnt++;
		}
		cnt++;
	}
	va_end(lst);
	return (chars);
}
int	main(void)
{
	int a = ft_printf(" %%%% ");
	ft_printf("\n%i\n", a);
	int b = printf(" %%%% ");
	printf("\n%i", b);
}