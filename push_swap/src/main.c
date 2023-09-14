/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 18:49:03 by jjaen-mo          #+#    #+#             */
/*   Updated: 2023/09/14 12:38:33 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_arg_str(char *str)
{
	int		cnt;
	char	**numbers;
	t_stack	*stack_a;
	t_stack	*first;

	cnt = 1;
	numbers = ft_split(str, ' ');
	stack_a = malloc(sizeof(t_stack));
	first = malloc(sizeof(t_stack));
	first = stack_a;
	stack_a->content = ft_atol(numbers[0]);
	stack_a->next = malloc(sizeof(t_stack));
	stack_a = stack_a->next;
	while (numbers[cnt + 1])
	{
		stack_a->content = ft_atol(numbers[cnt]);
		stack_a->next = malloc(sizeof(t_stack));
		stack_a = stack_a->next;
		cnt++;
	}
	stack_a->content = ft_atol(numbers[cnt]);
	return (first);
}

void	ft_set_position(t_stack **stack)
{
	int		cnt;
	t_stack	*tmp;

	cnt = 0;
	tmp = *stack;
	while (tmp)
	{
		tmp->act_pos = cnt;
		cnt++;
		tmp = tmp->next;
	}
}

int	main(int argc, char *argv[])
{
	t_stacks	stacks;

	if (argc > 1)
	{
		stacks.stack_a = malloc(sizeof(t_stack));
		stacks.stack_b = NULL;
		if (!stacks.stack_a)
			return (0);
		stacks.stack_a = ft_init_a(argc, argv, stacks.stack_a);
		ft_set_position(&stacks.stack_a);
		if (ft_error(stacks.stack_a) == 0)
			return (1);
		stacks.sizea = argc - 1;
		if (ft_is_sort(stacks.stack_a))
			return (0);
		if (stacks.sizea == 3)
			stacks.stack_a = ft_sort_three(stacks.stack_a);
		else
			stacks = ft_sort(stacks);
		return (0);
	}
	else
		ft_printf("[ERROR]: No aguments included \n");
	return (1);
}
