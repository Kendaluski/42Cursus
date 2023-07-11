/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_sorting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 15:31:14 by jjaen-mo          #+#    #+#             */
/*   Updated: 2023/07/11 19:28:21 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_get_min(t_list *stack)
{
	int min;

	min = stack->content;
	while(stack)
	{
		if(stack->content < min)
			min = stack->content;
		stack = stack->next;
	}
	return (min);
}

t_list	*ft_sort_three(t_list *stack_a)
{
	int	n;
	int	m;
	int	l;

	n = stack_a->content;
	m = stack_a->next->content;
	l = stack_a->next->next->content;
	if (n > m && m < l && n < l)
		stack_a = ft_sa(stack_a);
	else if (n < m && m > l && n > l)
		stack_a = ft_rra(stack_a);
	else if (n > m && m > l)
	{
		stack_a = ft_sa(stack_a);
		stack_a = ft_rra(stack_a);
	}
	else if (n > m && m < l && n > l)
		stack_a = ft_ra(stack_a);
	else if (n < m && m > l && n < l)
	{
		stack_a = ft_rra(stack_a);
		stack_a = ft_sa(stack_a);
	}
	return (stack_a);
}

t_stack	ft_sort(t_stack stacks)
{
	int n;

	n = ft_get_min(stacks.stack_a);
	while (stacks.stack_a->next)
	{
		if (stacks.stack_a->content <= n)
		{
			stacks = ft_pb(stacks);
			n = ft_get_min(stacks.stack_a);
		}
		else
			stacks.stack_a = ft_ra(stacks.stack_a);
	}
	while(stacks.stack_b->next)
	{
		stacks = ft_pa(stacks);
	}
	return (stacks);
}
