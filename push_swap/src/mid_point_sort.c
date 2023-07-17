/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mid_point_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 20:18:36 by jjaen-mo          #+#    #+#             */
/*   Updated: 2023/07/17 21:25:27 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sort_array(int *array)
{
	int	cnt;
	int	cnt2;
	int	tmp;

	cnt = 0;
	cnt2 = 0;
	tmp = 0;
	while (array[cnt])
	{
		cnt2 = cnt + 1;
		while (array[cnt2])
		{
			if (array[cnt] > array[cnt2])
			{
				tmp = array[cnt];
				array[cnt] = array[cnt2];
				array[cnt2] = tmp;
			}
			cnt2++;
		}
		cnt++;
	}
	tmp = array[cnt / 2];
	free(array);
	return (tmp);
}

int	ft_get_mid(t_stack *stack_a)
{
	int	cnt;
	int	*array;

	cnt = 0;
	array = malloc(sizeof(int) * ft_get_size(stack_a));
	while (stack_a)
	{
		array[cnt] = stack_a->content;
		stack_a = stack_a->next;
		cnt++;
	}
	return (ft_sort_array(array));
}

t_stacks	ft_mid_point_sort(t_stacks stacks)
{
	int	mid;

	while (ft_get_size(stacks.stack_a) > 2)
	{
		stacks.sizea = ft_get_size(stacks.stack_a);
		mid = ft_get_mid(stacks.stack_a);
		while (ft_get_size(stacks.stack_a) != stacks.sizea / 2
			&& ft_get_size(stacks.stack_a) > 2)
		{
			if (stacks.stack_a->content < mid)
				stacks = ft_pb(stacks);
			else if (stacks.stack_a->pos >= stacks.sizea / 2)
				stacks.stack_a = ft_rra(stacks.stack_a);
			else
				stacks.stack_a = ft_ra(stacks.stack_a);
		}
	}
	if (stacks.stack_a->content > stacks.stack_a->next->content)
		stacks.stack_a = ft_sa(stacks.stack_a);
	while (stacks.stack_b)
		stacks = ft_pa(stacks);
	return (stacks);
}
