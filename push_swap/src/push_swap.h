/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 18:19:56 by jjaen-mo          #+#    #+#             */
/*   Updated: 2023/09/11 16:09:44 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../include/libs/libft.h"

typedef struct s_stack
{
	int				content;
	int				act_pos;
	int				targ_pos;
	int				cost_a;
	int				cost_b;
	struct s_stack	*next;
}					t_stack;

typedef struct s_stacks
{
	t_stack			*stack_a;
	t_stack			*stack_b;
	int				sizea;
	int				sizeb;
}					t_stacks;

/**
 * @brief Initializes stack a
 *
 * @param size The count of numbers (argc)
 * @param numbers The numbers (argv)
 * @param stack_a The stack a
 * @return t_stack* The stack a with the numbers and indexes
 */
t_stack				*ft_init_a(int size, char **numbers, t_stack *stack_a);
/**
 * @brief Indexes the stack passed as parameter
 *
 * @param stack The stack to index
 */
void				ft_set_position(t_stack **stack);
/**
 * @brief Switches the first two elements of stack a
 *
 * @param stack_a The stack a
 * @return t_stack* The stack a with the first two elements switched
 */
t_stack				*ft_sa(t_stack *stack_a);
/**
 * @brief Pushes the first element of a to the top of b
 *
 * @param stacks The structure with the two stacks
 * @return t_stacks The structure with the two stacks
 */
t_stacks			ft_pa(t_stacks stacks);
/**
 * @brief Rotates the stack a
 *
 * @param stack_a The stack a
 * @return t_stack* The stack a rotated
 */
t_stack				*ft_ra(t_stack *stack_a);
/**
 * @brief Rotates a inversely
 *
 * @param stack_a The stack a
 * @return t_stack* The stack a inversely rotated
 */
t_stack				*ft_rra(t_stack *stack_a);
/**
 * @brief Switches the two first elements of b
 *
 * @param stack_b The stack b
 * @return t_stack* The stack b with the first two elements switched
 */
t_stack				*ft_sb(t_stack *stack_b);
/**
 * @brief Pushes the first element of b to the top of a
 *
 * @param stacks The structure with the two stacks
 * @return t_stacks The structure with the two stacks
 */
t_stacks			ft_pb(t_stacks stacks);
/**
 * @brief Rotates the stack b
 *
 * @param stack_b The stack b
 * @return t_stack* The stack b rotated
 */
t_stack				*ft_rb(t_stack *stack_b);
/**
 * @brief Rotates b inversely
 *
 * @param stack_b The stack b
 * @return t_stack* The stack b inversely rotated
 */
t_stack				*ft_rrb(t_stack *stack_b);
/**
 * @brief Switches the first two elements of a and b
 *
 * @param stacks The structure with the two stacks
 * @return t_stacks The structure with the two stacks
 */
t_stacks			ft_ss(t_stacks stacks);
/**
 * @brief Rotates a and b stacks
 *
 * @param stacks The structure with the two stacks
 * @return t_stacks The structure with the two stacks rotated
 */
t_stacks			ft_rr(t_stacks stacks);
/**
 * @brief Rotates a and b inversely
 *
 * @param stacks The structures with the two stacks
 * @return t_stacks The structure with the two stacks inversely rotated
 */
t_stacks			ft_rrr(t_stacks stacks);
/**
 * @brief Sorts the stack a with three numbers
 *
 * @param stack_a The stack a
 * @return t_stack* The stack a sorted
 */
t_stack				*ft_sort_three(t_stack *stack_a);
/**
 * @brief Sorts the stack with more than three numbers
 *
 * @param stacks The structure with the two stacks
 * @return t_stacks The structure with the two stacks sorted
 */
t_stacks			ft_sort(t_stacks stacks);
/**
 * @brief Gets the stack size
 *
 * @param stack The stack
 * @return int The size of the stack
 */
int					ft_get_size(t_stack *stack);
/**
 * @brief Sets the target position for each element of stack b
 *
 * @param stacks The stacks structure
 * @return t_stacks The stacks structure with the target positions set
 */
t_stacks			ft_set_target(t_stacks stacks);

/**

 * @brief Calculate what it takes for stack_b's content to reach its desired
 position
 *
 * @param stack_a
 * @param stack_b
 * @return int
 */
t_stacks			ft_calculate_cost(t_stacks stacks);

/**
 * @brief Decides what move is needed to send the cheapest node of b to a
 *
 * @param stacks The stacks structure
 * @param cheapest The node with the lower cost in b
 * @return t_stacks
 */
t_stacks			ft_move_up(t_stacks stacks, t_stack *cheapest);

/**
 * @brief Returns the node with the lower cost in b
 *
 * @param stack_b The stack b
 * @return t_stack* The node with the lower cost
 */
t_stack				*ft_cheapest(t_stack *stack_b);

/**
 * @brief Changes N to positive. This ft is needed for comparing costs
 *
 * @param n The number (cost)
 * @return int The number (cost) positive
 */
int					ft_pos(int n);

/**
 * @brief Checks if the stack is sorted
 *
 * @param stack The stack to check
 * @return int A boolean value
 */
int					ft_is_sort(t_stack *stack);

void ft_print_list(t_stack *stack);

#endif