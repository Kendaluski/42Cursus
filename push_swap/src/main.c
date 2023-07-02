/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 18:49:03 by jjaen-mo          #+#    #+#             */
/*   Updated: 2023/07/02 11:11:08 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_list	*stack_a;

	if (argc > 1)
	{
		stack_a = NULL;
		stack_a = ft_init_a(argc, argv, stack_a);
		//stack_a = ft_ra(stack_a);
		while(stack_a)
		{
			printf("%i\n", stack_a->content);
			stack_a = stack_a->next;
		}
	}
}
