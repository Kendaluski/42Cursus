/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcarden <alcarden@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 18:49:03 by jjaen-mo          #+#    #+#             */
/*   Updated: 2023/09/07 06:02:20 by alcarden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_arg_str(char *str)
{
	int		cnt;
	char	**numbers;
	t_stack	*stack_a;
	t_stack *first;

	cnt = 1;
	numbers = ft_split(str, ' ');
	stack_a = malloc(sizeof(t_stack));
	first = malloc(sizeof(t_stack));
	first = stack_a;
	stack_a->content = ft_atoi(numbers[0]);
	stack_a->next = malloc(sizeof(t_stack));
	stack_a = stack_a->next;
	while (numbers[cnt + 1])
	{
		stack_a->content = ft_atoi(numbers[cnt]);
		stack_a->next = malloc(sizeof(t_stack));
		stack_a = stack_a->next;
		cnt++;
	}
	stack_a->content = ft_atoi(numbers[cnt]);
	return (first);
}

void	ft_set_position(t_stack **stack)
{
	int		cnt;
	t_stack	*tmp;

	cnt = 1;
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
		stacks.stack_b = malloc(sizeof(t_stack));
		if (!stacks.stack_b)
			return (0);
		stacks.stack_a = ft_init_a(argc, argv, stacks.stack_a);
		ft_set_position(&stacks.stack_a);
		stacks.sizea = argc - 1;
		if (stacks.sizea == 3)
			stacks.stack_a = ft_sort_three(stacks.stack_a);
		else
			stacks = ft_sort(stacks);
		ft_set_position(&stacks.stack_a);
		while (stacks.stack_a)
		{
			ft_printf("Content: %i Position: %i \n", stacks.stack_a->content,
					stacks.stack_a->act_pos);
			stacks.stack_a = stacks.stack_a->next;
		}
	}
}
