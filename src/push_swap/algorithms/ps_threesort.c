/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_threesort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 13:33:14 by sede-san          #+#    #+#             */
/*   Updated: 2025/08/30 19:52:40 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Finds the node containing the biggest number in the stack.
 *
 * @param stack_a Pointer to the stack to search.
 *
 * @return Pointer to the node containing the biggest number, or NULL if stack
 *         is empty.
 *
 * @details
 * Iterates through the circular doubly linked list once to find the node with
 * the maximum value.
 */
static t_cdlist	*getbiggest(t_cdlist **stack_a);

/**
 * @brief Sorts a three-element stack optimally.
 *
 * @param stack_a Pointer to the stack containing three elements.
 *
 * @details
 * Optimized algorithm for 3 elements that requires at most 2
 * operations:
 * - Position 0 (biggest at top): ra -> check if sorted -> sa if needed
 * - Position 1 (biggest in middle): rra -> check if sorted -> sa if needed
 * - Position 2 (biggest at bottom): sa only
 *
 * This ensures:
 * - 0 operations if already sorted
 * - 1 operation in 3/6 cases
 * - 2 operations in remaining cases
 *
 * The strategy is to move the biggest element out of the way first,
 * then fix the remaining two if needed.
 */
void	ps_threesort(
	t_cdlist **stack_a)
{
	size_t	i_big;

	i_big = ps_data(getbiggest(stack_a))->index;
	if (i_big == 0)
		ra(stack_a, 1);
	else if (i_big == 1)
		rra(stack_a, 1);
	else
		return (sa(stack_a, 1));
	if (ps_issorted(stack_a) != ORDER_ASCENDING)
		sa(stack_a, 1);
}

static t_cdlist	*getbiggest(
	t_cdlist **stack_a)
{
	t_cdlist	*current;
	t_cdlist	*biggest;

	if (!stack_a || !*stack_a)
		return (NULL);
	current = *stack_a;
	biggest = current;
	while (current)
	{
		if (ps_data(current)->num > ps_data(biggest)->num)
			biggest = current;
		current = current->next;
		if (current == *stack_a)
			break ;
	}
	return (biggest);
}
