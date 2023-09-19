/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leaks_fix.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 08:16:47 by jjaen-mo          #+#    #+#             */
/*   Updated: 2023/09/19 14:00:27 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**ft_free_str(char **str)
{
	int	cnt;

	cnt = 0;
	while (str[cnt])
	{
		free(str[cnt]);
		cnt++;
	}
	free(str);
	return (NULL);
}

int	ft_split_size(char **str)
{
	int	cnt;

	cnt = 0;
	while (str[cnt])
		cnt++;
	return (cnt);
}

t_stack	*ft_init_a2(char **numbers, t_stack *stack_a)
{
	int		cnt;
	int		size;
	t_stack	*first;

	cnt = 0;
	size = ft_split_size(numbers);
	first = malloc(sizeof(t_stack));
	first->content = ft_atol(numbers[cnt]);
	first->act_pos = 0;
	first->next = malloc(sizeof(t_stack));
	stack_a = first->next;
	cnt++;
	if (size == 1)
		return (ft_clean(first, numbers));
	while (cnt < size - 1)
	{
		stack_a->content = ft_atol(numbers[cnt]);
		stack_a->next = malloc(sizeof(t_stack));
		stack_a = stack_a->next;
		cnt++;
	}
	stack_a->content = ft_atol(numbers[cnt]);
	stack_a->next = NULL;
	ft_free_str(numbers);
	return (first);
}

t_stack	*ft_clean(t_stack *stack, char **nums)
{
	free(stack->next);
	stack->next = NULL;
	free(stack);
	stack = NULL;
	ft_free_str(nums);
	return (stack);
}

t_stack	*ft_clean_stack(t_stack *stack)
{
	t_stack	*tmp;

	while (stack && stack->next)
	{
		tmp = stack;
		stack = stack->next;
		free(tmp);
	}
	return (NULL);
}
