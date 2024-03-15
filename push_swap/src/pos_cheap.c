/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pos_cheap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 10:23:26 by jjaen-mo          #+#    #+#             */
/*   Updated: 2024/03/16 00:13:36 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_list(t_stacks stacks)
{
	t_stack	*tmp;

	tmp = stacks.stack_a;
	printf("Stack A\n");
	while (tmp)
	{
		printf("Content: %ld ", tmp->content);
		printf("Act_pos: %d ", tmp->act_pos);
		printf("Targ_pos: %d ", tmp->targ_pos);
		printf("Cost_a: %d ", tmp->cost_a);
		printf("Cost_b: %d\n", tmp->cost_b);
		tmp = tmp->next;
	}
	tmp = stacks.stack_b;
	printf("Stack B\n");
	while (tmp)
	{
		printf("Content: %ld ", tmp->content);
		printf("Act_pos: %d ", tmp->act_pos);
		printf("Targ_pos: %d ", tmp->targ_pos);
		printf("Cost_a: %d ", tmp->cost_a);
		printf("Cost_b: %d\n", tmp->cost_b);
		tmp = tmp->next;
	}
}

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
	while (tmp)
	{
		if (ft_pos(tmp->cost_a) + ft_pos(tmp->cost_b) < ft_pos(cheapest->cost_a)
			+ ft_pos(cheapest->cost_b))
			cheapest = tmp;
		tmp = tmp->next;
	}
	return (cheapest);
}

int	ft_is_sort(t_stack *stack)
{
	t_stack	*tmp;

	tmp = stack;
	while (tmp)
	{
		if (tmp->next && tmp->content > tmp->next->content)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

t_stacks	ft_calculate_cost(t_stacks stacks)
{
	t_stack	*tmp;

	tmp = stacks.stack_b;
	while (tmp)
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
