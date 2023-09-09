/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_sorting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcarden <alcarden@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 15:31:14 by jjaen-mo          #+#    #+#             */
/*   Updated: 2023/09/09 09:06:01 by alcarden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_pos(int n)
{
	if (n < 0)
		return (n * -1);
	else
		return (n);
}

t_stack	*ft_cheapest(t_stack *stack_b)
{
	t_stack	*tmp;
	t_stack	*cheapest;

	tmp = stack_b;
	cheapest = tmp;
	while (tmp->next)
	{
		if (ft_pos(tmp->cost_a) + ft_pos(tmp->cost_b) < ft_pos(cheapest->cost_a)
			+ ft_pos(cheapest->cost_b))
			cheapest = tmp;
		tmp = tmp->next;
	}
	return (cheapest);
}

t_stacks	ft_move_up(t_stacks stacks, t_stack *cheapest)
{
	if (cheapest->cost_a == 0 && cheapest->cost_b == 0)
		stacks = ft_pa(stacks);
	else if (cheapest->cost_a < 0 && cheapest->cost_b < 0)
		stacks = ft_rrr(stacks);
	else if (cheapest->cost_a > 0 && cheapest->cost_b > 0)
		stacks = ft_rr(stacks);
	else if (cheapest->cost_a < 0)
		stacks.stack_a = ft_rra(stacks.stack_a);
	else if (cheapest->cost_a > 0)
		stacks.stack_a = ft_ra(stacks.stack_a);
	else if (cheapest->cost_b < 0)
		stacks.stack_b = ft_rrb(stacks.stack_b);
	else if (cheapest->cost_b > 0)
		stacks.stack_b = ft_rb(stacks.stack_b);
	return (stacks);
}

t_stacks	ft_calculate_cost(t_stacks stacks)
{
	t_stack	*tmp;

	tmp = stacks.stack_b;
	while (tmp->next)
	{
		tmp->cost_b = tmp->act_pos;
		if (tmp->act_pos > ft_get_size(stacks.stack_b) / 2)
			tmp->cost_b = (ft_get_size(stacks.stack_b) - tmp->act_pos) * -1;
		tmp->cost_a = tmp->targ_pos;
		if (tmp->targ_pos > ft_get_size(stacks.stack_a) / 2)
			tmp->cost_a = (ft_get_size(stacks.stack_a) - tmp->targ_pos) * -1;
		tmp = tmp->next;
	}
	return (stacks);
}
t_stack	*ft_calculate_cost2(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*first;

	first = stack_b;
	while (stack_b->next)
	{
		stack_b->cost_b = stack_b->act_pos;
		if (stack_b->act_pos > ft_get_size(stack_b) / 2)
			stack_b->cost_b = (ft_get_size(stack_b) - stack_b->act_pos) * -1;
		if (stack_b->targ_pos > ft_get_size(stack_a) / 2)
			stack_b->cost_a = (ft_get_size(stack_a) - stack_b->targ_pos) * -1;
		stack_b = stack_b->next;
	}
	return (first);
}

int	ft_get_pos(t_stack *stack_a, int num, int target, int maxint)
{
	t_stack	*tmp;

	tmp = stack_a;
	while (tmp->next)
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
	while(tmp->next)
	{
		if(tmp->content < maxint)
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

int ft_is_sort(t_stack *stack)
{
	t_stack *tmp;

	tmp = stack;
	while(tmp)
	{
		if(tmp->next && tmp->content > tmp->next->content)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

t_stacks	ft_sort(t_stacks stacks)
{
	ft_set_position(&stacks.stack_a);
	stacks.sizea = ft_get_size(stacks.stack_a);
	while (ft_get_size(stacks.stack_a) > 3)
		stacks = ft_pb(stacks);
	stacks.sizeb = ft_get_size(stacks.stack_b);
	stacks.stack_a = ft_sort_three(stacks.stack_a);
	while (stacks.stack_b->next)
	{
		stacks = ft_set_target(stacks);
		stacks = ft_calculate_cost(stacks);
		stacks = ft_move_up(stacks, ft_cheapest(stacks.stack_b));
	}
	stacks.sizea = ft_get_size(stacks.stack_a);
	while(!ft_is_sort(stacks.stack_a))
	{
		if(stacks.stack_a->content > stacks.sizea / 2)
			stacks.stack_a = ft_ra(stacks.stack_a);
		else
			stacks.stack_a = ft_rra(stacks.stack_a);
	}
	return (stacks);
}
