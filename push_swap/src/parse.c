/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 19:27:13 by jjaen-mo          #+#    #+#             */
/*   Updated: 2023/09/15 20:11:29 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stacks	ft_sort_two(t_stacks stacks)
{
	if (stacks.stack_a->content > stacks.stack_a->next->content)
		stacks.stack_a = ft_sa(stacks.stack_a, 1);
	return (stacks);
}

int	ft_max_int(t_stack *stack)
{
	t_stack	*tmp;

	tmp = stack;
	while (tmp)
	{
		if (tmp->content > 2147483647 || tmp->content < -2147483648)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	ft_parse(t_stack *stack)
{
	t_stack	*tmp;
	t_stack	*tmp2;
	int		zero;

	tmp = stack;
	zero = 0;
	while (tmp)
	{
		tmp2 = stack->next;
		if (tmp->content == 0 || tmp->content == -0 || tmp->content == +0)
			zero++;
		while (tmp2)
		{
			if (tmp2->content == tmp->content && tmp2->act_pos != tmp->act_pos)
				return (0);
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
	if (zero > 1)
		return (0);
	return (1);
}

int	ft_error(t_stack *stack)
{
	if (ft_parse(stack) == 0)
	{
		ft_printf("[ERROR] Wrong numbers imput\n");
		stack = ft_clean_stack(stack);
		return (0);
	}
	if (ft_max_int(stack) == 0)
	{
		ft_printf("[ERROR] Higher or lower values than INT included \n");
		stack = ft_clean_stack(stack);
		return (0);
	}
	return (1);
}
