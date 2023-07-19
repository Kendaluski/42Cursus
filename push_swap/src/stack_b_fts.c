/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_b_fts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 12:12:50 by jjaen-mo          #+#    #+#             */
/*   Updated: 2023/07/19 19:11:03 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_sb(t_stack *stack_b)
{
	int	tmp;

	if (!stack_b || !stack_b->next)
		return (stack_b);
	tmp = stack_b->content;
	stack_b->content = stack_b->next->content;
	stack_b->next->content = tmp;
	ft_printf("sb\n");
	return (stack_b);
}

t_stacks	ft_pb(t_stacks stacks)
{
	t_stack	*tmp;

	if (stacks.stack_a)
	{
		tmp = malloc(sizeof(t_stack));
		tmp->content = stacks.stack_a->content;
		tmp->next = stacks.stack_b;
		if (stacks.stack_a->next)
		{
			stacks.stack_a->pos = stacks.stack_a->next->pos;
			stacks.stack_a = stacks.stack_a->next;
		}
		else
			stacks.stack_a = NULL;
		stacks.stack_b = tmp;
		ft_printf("pb\n");
	}
	return (stacks);
}

t_stack	*ft_rb(t_stack *stack_b)
{
	int		tmp;
	t_stack	*first;

	if (!stack_b || !stack_b->next)
		return (stack_b);
	first = stack_b;
	stack_b = stack_b->next;
	while (stack_b->next)
	{
		tmp = stack_b->content;
		stack_b->content = stack_b->next->content;
		stack_b->next->content = tmp;
		stack_b = stack_b->next;
	}
	tmp = first->content;
	first->content = stack_b->content;
	stack_b->content = tmp;
	ft_printf("rb\n");
	return (first);
}

t_stack	*ft_rrb(t_stack *stack_b)
{
	t_stack	*last;
	t_stack	*first;

	if (!stack_b || !stack_b->next)
		return (stack_b);
	first = stack_b;
	while (stack_b->next->next)
		stack_b = stack_b->next;
	last = stack_b->next;
	stack_b->next = NULL;
	last->next = first;
	ft_printf("rrb\n");
	return (last);
}
