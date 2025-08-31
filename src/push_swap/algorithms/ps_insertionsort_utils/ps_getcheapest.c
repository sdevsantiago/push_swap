/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cheapest.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 19:08:52 by sede-san          #+#    #+#             */
/*   Updated: 2025/08/30 19:19:36 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static unsigned long	calccost(t_cdlist **stack_a, t_cdlist **stack_b,
							t_cdlist *current_a);

/**
 * @brief Finds the cheapest element to move during insertion sort.
 *
 * @param stack_a Pointer to the source stack.
 * @param stack_b Pointer to the destination stack.
 * @param run The run identifier for elements to consider.
 * @param order The sorting order (ORDER_ASCENDING or ORDER_DESCENDING).
 *
 * @return Pointer to the node with the lowest movement cost.
 *
 * @details
 * Optimization function that minimizes total operations:
 *
 * 1. Cost Calculation: For each element in the specified run, calculates
 *    the total cost to move it to its target position in stack_b
 *
 * 2. Cost Components:
 *    - Rotations needed to bring element to top of stack_a
 *    - Rotations needed to bring target to top of stack_b
 *    - One push operation
 *
 * 3. Optimization: Considers combined rotations (rr, rrr) when both
 *    stacks need rotation in the same direction
 *
 * 4. Default Selection: If stack_b is empty, returns the first element
 *    or last element based on current run status
 *
 * This function is crucial for minimizing the total number of operations
 * in the insertion sort phase of the timsort algorithm.
 */
t_cdlist	*get_cheapest(
	t_cdlist **stack_a,
	t_cdlist **stack_b,
	size_t run,
	int order)
{
	t_cdlist		*cheapest;
	t_cdlist		*current_a;

	if (ps_data(*stack_a)->run != SORTED_RUN)
		cheapest = *stack_a;
	else
		cheapest = ft_cdlstlast(*stack_a);
	if (!*stack_b)
		return (cheapest);
	ps_findtargets(stack_a, stack_b, order, run);
	current_a = *stack_a;
	while (current_a)
	{
		if (ps_data(current_a)->run == run && ps_data(current_a)->target
			&& calccost(stack_a, stack_b, cheapest)
			> calccost(stack_a, stack_b, current_a))
			cheapest = current_a;
		current_a = current_a->next;
		if (current_a == *stack_a)
			break ;
	}
	return (cheapest);
}

static unsigned long	calccost(
	t_cdlist **stack_a,
	t_cdlist **stack_b,
	t_cdlist *current_a)
{
	t_cdlist	*target_b;
	int			moves_a;
	int			moves_b;

	target_b = ps_data(current_a)->target;
	if (!target_b)
		return (ULONG_MAX);
	if (ps_istophalf(current_a, stack_a))
		moves_a = ps_data(current_a)->index;
	else
		moves_a = ps_stacksize(stack_a) - ps_data(current_a)->index;
	if (!target_b)
		moves_b = 0;
	else if (ps_istophalf(target_b, stack_b))
		moves_b = ps_data(target_b)->index;
	else
		moves_b = ps_stacksize(stack_b) - ps_data(target_b)->index;
	return (moves_a + moves_b + 1);
}
