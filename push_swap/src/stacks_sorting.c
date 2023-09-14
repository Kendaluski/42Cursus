/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_sorting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 15:31:14 by jjaen-mo          #+#    #+#             */
/*   Updated: 2023/09/14 12:40:04 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stacks	ft_move_up(t_stacks stacks, t_stack *cheapest)
{
	if (cheapest->cost_a == 0 && cheapest->cost_b == 0)
		stacks = ft_pa(stacks);
	else if (cheapest->cost_a < 0 && cheapest->cost_b < 0)
		stacks = ft_rrr(stacks);
	else if (cheapest->cost_a > 0 && cheapest->cost_b > 0)
		stacks = ft_rr(stacks);
	else if (cheapest->cost_a < 0)
		stacks.stack_a = ft_rra(stacks.stack_a, 1);
	else if (cheapest->cost_a > 0)
		stacks.stack_a = ft_ra(stacks.stack_a, 1);
	else if (cheapest->cost_b < 0)
		stacks.stack_b = ft_rrb(stacks.stack_b, 1);
	else if (cheapest->cost_b > 0)
		stacks.stack_b = ft_rb(stacks.stack_b, 1);
	return (stacks);
}

int	ft_get_pos(t_stack *stack_a, int num, int target, int maxint)
{
	t_stack	*tmp;

	tmp = stack_a;
	while (tmp)
	{
		if (num < tmp->content && tmp->content < maxint)
		{
			maxint = tmp->content;
			target = tmp->act_pos;
		}
		tmp = tmp->next;
	}
	if (maxint != 2147483647)
		return (target);
	tmp = stack_a;
	while (tmp)
	{
		if (tmp->content < maxint)
		{
			maxint = tmp->content;
			target = tmp->act_pos;
		}
		tmp = tmp->next;
	}
	return (target);
}

t_stacks	ft_set_target(t_stacks stacks)
{
	t_stack	*tmp;
	int		target;

	target = 0;
	tmp = stacks.stack_b;
	while (tmp)
	{
		target = ft_get_pos(stacks.stack_a, tmp->content, target, 2147483647);
		tmp->targ_pos = target;
		tmp = tmp->next;
	}
	return (stacks);
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
		stack_a = ft_sa(stack_a, 1);
	else if (n < m && m > l && n > l)
		stack_a = ft_rra(stack_a, 1);
	else if (n > m && m > l)
	{
		stack_a = ft_sa(stack_a, 1);
		stack_a = ft_rra(stack_a, 1);
	}
	else if (n > m && m < l && n > l)
		stack_a = ft_ra(stack_a, 1);
	else if (n < m && m > l && n < l)
	{
		stack_a = ft_rra(stack_a, 1);
		stack_a = ft_sa(stack_a, 1);
	}
	return (stack_a);
}

t_stacks	ft_sort(t_stacks stacks)
{
	ft_set_position(&stacks.stack_a);
	stacks.sizea = ft_get_size(stacks.stack_a);
	while (ft_get_size(stacks.stack_a) > 3)
		stacks = ft_pb(stacks);
	stacks.sizeb = ft_get_size(stacks.stack_b);
	if (ft_get_size(stacks.stack_a) == 2)
		return (ft_sort_two(stacks));
	stacks.stack_a = ft_sort_three(stacks.stack_a);
	while (stacks.stack_b)
	{
		stacks = ft_set_target(stacks);
		stacks = ft_calculate_cost(stacks);
		stacks = ft_move_up(stacks, ft_cheapest(stacks.stack_b));
	}
	while (!ft_is_sort(stacks.stack_a))
	{
		stacks.sizea = ft_get_size(stacks.stack_a);
		if (stacks.stack_a->act_pos > stacks.sizea / 2)
			stacks.stack_a = ft_rra(stacks.stack_a, 1);
		else
			stacks.stack_a = ft_ra(stacks.stack_a, 1);
	}
	return (stacks);
}
