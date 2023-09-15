/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_a_fts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 10:41:02 by jjaen-mo          #+#    #+#             */
/*   Updated: 2023/09/15 09:04:17 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_sa(t_stack *stack_a, int flag)
{
	int	tmp;

	if (!stack_a || !stack_a->next)
		return (stack_a);
	tmp = stack_a->content;
	stack_a->content = stack_a->next->content;
	stack_a->next->content = tmp;
	if (flag)
		ft_printf("sa\n");
	ft_set_position(&stack_a);
	return (stack_a);
}

t_stacks	ft_pa(t_stacks stacks)
{
	t_stack	*tmp;

	if (stacks.stack_b)
	{
		if (!stacks.stack_a)
		{
			stacks.stack_a = stacks.stack_b;
			stacks.stack_b = stacks.stack_b->next;
			stacks.stack_a->next = NULL;
		}
		else
		{
			tmp = stacks.stack_a;
			stacks.stack_a = stacks.stack_b;
			stacks.stack_b = stacks.stack_b->next;
			stacks.stack_a->next = tmp;
		}
	}
	ft_printf("pa\n");
	ft_set_position(&stacks.stack_a);
	ft_set_position(&stacks.stack_b);
	return (stacks);
}

t_stack	*ft_ra(t_stack *stack_a, int flag)
{
	int		tmp;
	t_stack	*first;

	if (!stack_a || !stack_a->next)
		return (stack_a);
	first = stack_a;
	stack_a = stack_a->next;
	while (stack_a->next)
	{
		tmp = stack_a->content;
		stack_a->content = stack_a->next->content;
		stack_a->next->content = tmp;
		stack_a = stack_a->next;
	}
	tmp = first->content;
	first->content = stack_a->content;
	stack_a->content = tmp;
	if (flag)
		ft_printf("ra\n");
	ft_set_position(&first);
	return (first);
}

t_stack	*ft_rra(t_stack *stack_a, int flag)
{
	t_stack	*last;
	t_stack	*first;

	if (!stack_a || !stack_a->next)
		return (stack_a);
	first = stack_a;
	while (stack_a->next->next)
		stack_a = stack_a->next;
	last = stack_a->next;
	stack_a->next = NULL;
	last->next = first;
	if (flag)
		ft_printf("rra\n");
	ft_set_position(&last);
	return (last);
}
