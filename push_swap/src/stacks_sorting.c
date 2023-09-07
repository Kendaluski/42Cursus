/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_sorting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcarden <alcarden@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 15:31:14 by jjaen-mo          #+#    #+#             */
/*   Updated: 2023/09/07 06:09:33 by alcarden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stacks ft_move_up(t_stacks stacks, int nb)
{
	t_stack *tmp;

	tmp = stacks.stack_b;
	while(tmp && tmp->content != nb)
		tmp = tmp->next;
	while(stacks.stack_b->content != tmp->content)
	{
		if(tmp->act_pos <= ft_get_size(stacks.stack_b))
			ft_rrb(stacks.stack_b);
		else
			ft_rb(stacks.stack_b);
	}
	ft_printf("Bup: %i NB: %i\n", stacks.stack_b->content, nb);
	if(stacks.stack_b->content == nb)
		stacks = ft_pb(stacks);
	return (stacks);
}

int	ft_calculate_cost(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*tmp;
	int		cost_b;
	int		cost;

	cost_b = stack_b->act_pos;
	tmp = stack_a;
	if(stack_a->content > stack_b->content)
	{
		cost = cost_b;
		return (cost);
	}
	while (tmp->next)
	{
		if (stack_b->content > tmp->content
			&& stack_b->content < tmp->next->content)
			cost = cost_b + tmp->next->act_pos;
		tmp = tmp->next;
	}
	if (stack_b->content > tmp->content)
		cost = cost_b + tmp->act_pos;
	return (cost);
}

int	ft_get_pos(t_stack *stack_a, int num)
{
	t_stack	*tmp;

	tmp = stack_a;
	while (tmp->next)
	{
		if (num < tmp->content)
			return (tmp->act_pos);
		tmp = tmp->next;
	}
	if (tmp->content > num)
		return (tmp->act_pos);
	else
		return (tmp->act_pos + 1);
	return (-1);
}

t_stacks	ft_set_target(t_stacks stacks)
{
	t_stack	*tmp;
	int min_cost;
	int min_cont;

	tmp = stacks.stack_b;
	min_cost = ft_calculate_cost(stacks.stack_a, tmp);
	min_cont = tmp->content;
	while (tmp->next)
	{
		tmp->targ_pos = ft_get_pos(stacks.stack_a, tmp->content);
		if(min_cost > ft_calculate_cost(stacks.stack_a, tmp))
		{
			min_cost = ft_calculate_cost(stacks.stack_a, tmp);
			min_cont = tmp->content;
		}
		tmp = tmp->next;
	}
	stacks.min_cont = min_cont;
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

t_stacks	ft_sort(t_stacks stacks)
{
	ft_set_position(&stacks.stack_a);
	while (ft_get_size(stacks.stack_a) > 3)
		stacks = ft_pb(stacks);
	stacks.stack_a = ft_sort_three(stacks.stack_a);
	while(stacks.stack_b->next)
	{
		stacks = ft_set_target(stacks);
		stacks = ft_move_up(stacks, stacks.min_cont);
	}
	return (stacks);
}
