/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 18:49:03 by jjaen-mo          #+#    #+#             */
/*   Updated: 2023/07/05 21:38:42 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_sort_three(t_list *stack_a, t_list *stack_b)
{
	int	n;
	int	m;
	int	l;

	(void)stack_b;
	n = stack_a->content;
	m = stack_a->next->content;
	l = stack_a->next->next->content;
	if (n < m && m < l)
		return (stack_a);
	else if (n > m && m < l && n < l)
	{
		stack_a = ft_sa(stack_a);
		ft_printf("sa\n");
	}
	else if (n < m && m > l && n > l)
	{
		stack_a = ft_ra(stack_a);
		ft_printf("ra\n");
	}
	else if (n > m && m > l)
	{
		stack_a = ft_sa(stack_a);
		ft_printf("sa\n");
		stack_a = ft_rra(stack_a);
		ft_printf("rra\n");
	}
	return (stack_a);
}

int	main(int argc, char *argv[])
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		cnt;

	if (argc > 1)
	{
		cnt = 0;
		stack_a = NULL;
		stack_b = malloc(sizeof(t_list));
		if (!stack_b)
			return (0);
		stack_a = ft_init_a(argc, argv, stack_a);
		if (argc == 4)
			stack_a = ft_sort_three(stack_a, stack_b);
		while (stack_a)
		{
			ft_printf("%i\n", stack_a->content);
			stack_a = stack_a->next;
			cnt++;
		}
	}
}
