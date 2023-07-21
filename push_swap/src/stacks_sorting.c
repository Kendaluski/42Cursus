/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_sorting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 15:31:14 by jjaen-mo          #+#    #+#             */
/*   Updated: 2023/07/21 14:24:24 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_get_min(t_stack *stack)
{
	int	min;

	min = stack->content;
	while (stack)
	{
		if (stack->content < min)
			min = stack->content;
		stack = stack->next;
	}
	return (min);
}

int	ft_get_min_pos(t_stack *stack, int min)
{
	while (stack)
	{
		if (stack->content == min)
			return (stack->indx);
		stack = stack->next;
	}
	return (stack->indx);
}

t_stack	*ft_sort_three(t_stack *stack_a)
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

t_stacks	ft_sort(t_stacks stacks)
{
	int	n;
	int	n_pos;
	int	cnt;

	cnt = 1;
	n = ft_get_min(stacks.stack_a);
	n_pos = ft_get_min_pos(stacks.stack_a, n);
	while (cnt != stacks.sizea - 2)
	{
		if (stacks.stack_a->content <= n)
		{
			stacks = ft_pb(stacks);
			n = ft_get_min(stacks.stack_a);
			n_pos = ft_get_min_pos(stacks.stack_a, n);
			cnt++;
		}
		else
		{
			if (n_pos >= stacks.sizea / 2)
				stacks.stack_a = ft_rra(stacks.stack_a);
			else
				stacks.stack_a = ft_ra(stacks.stack_a);
		}
	}
	ft_sort_three(stacks.stack_a);
	while (stacks.stack_b->next)
		stacks = ft_pa(stacks);
	return (stacks);
}
