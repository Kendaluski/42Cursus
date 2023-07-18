/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mid_point_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 20:18:36 by jjaen-mo          #+#    #+#             */
/*   Updated: 2023/07/18 16:40:58 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_get_max(t_stack *stack)
{
	int	max;

	max = stack->content;
	while (stack)
	{
		if (stack->content > max)
			max = stack->content;
		stack = stack->next;
	}
	return (max);
}

int	*ft_prep_mids(int *array, int cnt)
{
	int	cnt2;
	int	cnt3;
	int	*mids;

	cnt2 = 0;
	cnt3 = 0;
	while (cnt > -1)
	{
		while (array[cnt] == 0)
			cnt--;
		if (array[cnt] != 0)
			cnt2++;
		cnt--;
	}
	mids = malloc(sizeof(int) * cnt2 - 3);
	cnt++;
	while (cnt < cnt2 - 3)
	{
		while (array[cnt3] == 0)
			cnt3++;
		mids[cnt] = array[cnt3];
		cnt++;
		cnt3++;
	}
	return (free(array), mids);
}

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
	int	mid2;
	int	cnt;

	mid = ft_get_mid(stacks.stack_a);
	stacks.sizea = ft_get_size(stacks.stack_a);
	stacks.mids = (int *)malloc(sizeof(int) * (stacks.sizea));
	stacks.mids[0] = mid;
	cnt = 1;
	while (ft_get_size(stacks.stack_a) > 2)
	{
		stacks.sizea = ft_get_size(stacks.stack_a);
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
		mid = ft_get_mid(stacks.stack_a);
		stacks.mids[cnt] = mid;
		cnt++;
	}
	if (stacks.stack_a->content > stacks.stack_a->next->content)
		stacks.stack_a = ft_sa(stacks.stack_a);
	stacks.mids = ft_prep_mids(stacks.mids, cnt);
	ft_set_position(&stacks.stack_b);
	cnt = 0;
	while (stacks.mids[cnt] != 0)
		cnt++;
	cnt--;
	while (cnt > 0)
	{
		mid = stacks.mids[cnt];
		mid2 = stacks.mids[cnt - 1];
		while (mid >= mid2)
		{
			if (stacks.stack_b->content == mid)
			{
				stacks = ft_pa(stacks);
				mid--;
			}
			else if (stacks.stack_b->pos >= ft_get_size(stacks.stack_b) / 2)
				stacks.stack_b = ft_rrb(stacks.stack_b);
			else
				stacks.stack_b = ft_rb(stacks.stack_b);
		}
		cnt--;
	}
	while(stacks.stack_b && mid != 0)
	{
		mid = ft_get_max(stacks.stack_b);
		stacks.sizeb = ft_get_size(stacks.stack_b);
		if (stacks.stack_b->content == mid)
				stacks = ft_pa(stacks);
		else if (stacks.stack_b->pos >= stacks.sizeb / 2)
			stacks.stack_b = ft_rrb(stacks.stack_b);
		else
			stacks.stack_b = ft_rb(stacks.stack_b);
	}
	stacks.stack_a = stacks.stack_a->next;
	return (stacks);
}
