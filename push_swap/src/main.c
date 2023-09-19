/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 18:49:03 by jjaen-mo          #+#    #+#             */
/*   Updated: 2023/09/19 13:57:59 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_chars(char **argv)
{
	int	cnt;
	int	cnt2;

	cnt = 1;
	while (argv[cnt])
	{
		cnt2 = 0;
		while (argv[cnt][cnt2])
		{
			if (!ft_isdigit(argv[cnt][cnt2]))
			{
				if (argv[cnt][cnt2] != '-' || argv[cnt][cnt2] != '+')
				{
					if (argv[cnt][cnt2] != ' ')
					{
						ft_printf("[ERROR] Non numerical included\n");
						return (0);
					}
				}
			}
			cnt2++;
		}
		cnt++;
	}
	return (1);
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
		stacks.stack_a = NULL;
		stacks.stack_b = NULL;
		if (ft_check_chars(argv) == 0)
			return (1);
		stacks.stack_a = ft_init_a(argc, argv, stacks.stack_a);
		ft_set_position(&stacks.stack_a);
		if (ft_error(stacks.stack_a) == 0)
			return (1);
		stacks.sizea = argc - 1;
		if (ft_is_sort(stacks.stack_a))
		{
			stacks.stack_a = ft_clean_stack(stacks.stack_a);
			return (0);
		}
		if (stacks.sizea == 3)
			stacks.stack_a = ft_sort_three(stacks.stack_a);
		else
			stacks = ft_sort(stacks);
		stacks.stack_a = ft_clean_stack(stacks.stack_a);
		return (0);
	}
}
