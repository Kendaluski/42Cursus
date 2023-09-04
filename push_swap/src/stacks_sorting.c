/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_sorting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 15:31:14 by jjaen-mo          #+#    #+#             */
/*   Updated: 2023/09/04 19:10:45 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_get_pos(t_stack *stack_a, int num)
{
	t_stack *tmp;
	
	tmp = stack_a;
	while(tmp->next)
	{
		ft_printf("tmp: %i\n", tmp->content);
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

t_stacks ft_set_target(t_stacks stacks)
{
	t_stack *tmp;
	
	tmp = stacks.stack_b;
	while(tmp->next)
	{
		tmp->targ_pos = ft_get_pos(stacks.stack_a, tmp->content);
		ft_printf("num: %i, targ_pos: %i\n", tmp->content, tmp->targ_pos);
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

t_stacks	ft_sort(t_stacks stacks)
{
	ft_set_position(&stacks.stack_a);
	while(ft_get_size(stacks.stack_a) > 3)
		stacks = ft_pb(stacks);
	stacks.stack_a = ft_sort_three(stacks.stack_a);
	stacks = ft_set_target(stacks);
	return (stacks);
}
