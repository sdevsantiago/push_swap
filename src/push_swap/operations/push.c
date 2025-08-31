/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 18:03:05 by sede-san          #+#    #+#             */
/*   Updated: 2025/08/30 20:01:30 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Pushes the top element from source stack to destination stack.
 *
 * @param stack_src Pointer to the source stack.
 * @param stack_dest Pointer to the destination stack.
 *
 * @details
 * Handles the complex pointer manipulation for moving a node between two
 * circular doubly linked lists. Properly updates all pointers to maintain
 * list integrity in both stacks.
 *
 * Special cases handled:
 * - Single element source stack: becomes NULL
 * - Empty destination stack: becomes single-element circular list
 * - Multiple elements: Complex pointer rearrangement
 */
static void	push(
	t_cdlist **stack_src,
	t_cdlist **stack_dest)
{
	t_cdlist	*first_node_src;
	t_cdlist	*second_node_src;
	t_cdlist	*last_node_src;

	if (!stack_src || !*stack_src)
		return ;
	first_node_src = *stack_src;
	second_node_src = first_node_src->next;
	if (second_node_src == first_node_src)
		*stack_src = NULL;
	else
	{
		last_node_src = ft_cdlstlast(*stack_src);
		second_node_src->previous = last_node_src;
		last_node_src->next = second_node_src;
		*stack_src = second_node_src;
	}
	ft_cdlstadd_front(stack_dest, first_node_src);
}

/**
 * @brief Push the top element from stack_b to stack_a.
 *
 * @param stack_b Pointer to the source stack (stack_b).
 * @param stack_a Pointer to the destination stack (stack_a).
 * @param print Whether to print the operation name (1) or not (0).
 *
 * @details
 * Performs the 'pa' operation: takes the top element of stack_b and puts it on
 * top of stack_a. If print is true, updates indexes and prints "pa".
 */
void	pa(
	t_cdlist **stack_b,
	t_cdlist **stack_a,
	int print)
{
	push(stack_b, stack_a);
	if (print)
	{
		ps_updateindexes(stack_a, stack_b);
		ft_putendl(PA);
	}
}

/**
 * @brief Push the top element from stack_a to stack_b.
 *
 * @param stack_a Pointer to the source stack (stack_a).
 * @param stack_b Pointer to the destination stack (stack_b).
 * @param print Whether to print the operation name (1) or not (0).
 *
 * @details
 * Performs the 'pb' operation: takes the top element of stack_a and puts it on
 * top of stack_b. If print is true, updates indexes and prints "pb".
 */
void	pb(
	t_cdlist **stack_a,
	t_cdlist **stack_b,
	int print)
{
	push(stack_a, stack_b);
	if (print)
	{
		ps_updateindexes(stack_a, stack_b);
		ft_putendl(PB);
	}
}
