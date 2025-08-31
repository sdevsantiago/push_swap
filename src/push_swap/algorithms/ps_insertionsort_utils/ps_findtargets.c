/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_findtargets.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 21:16:02 by sede-san          #+#    #+#             */
/*   Updated: 2025/08/30 20:01:15 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_cdlist	*findbiggest(t_cdlist **stack_b, size_t run);
static void		findtarget_des(t_cdlist *current_a, t_cdlist **stack_b,
					t_cdlist *biggest, t_cdlist *smallest);
static void		findtarget_asc(t_cdlist *current_a, t_cdlist **stack_b,
					t_cdlist *biggest, t_cdlist *smallest);

/**
 * @brief Finds optimal target positions for elements during insertion sort.
 *
 * @param stack_a Pointer to the source stack containing elements to move.
 * @param stack_b Pointer to the destination stack where elements will be
 *                inserted.
 * @param order The sorting order (ORDER_ASCENDING or ORDER_DESCENDING).
 * @param run The run identifier for elements to process.
 *
 * @details
 * Critical function for efficient insertion sort in large stacks:
 *
 * 1. **Target Finding**: For each element in the specified run, finds the
 *    optimal insertion position in stack_b to maintain sorted order
 *
 * 2. **Order-Specific Logic**:
 *    - Descending: Finds position where element fits in descending sequence
 *    - Ascending: Finds position where element fits in ascending sequence
 *
 * 3. **Optimization**: Uses biggest/smallest elements as reference points
 *    to minimize search time and operation count
 *
 * The target information is stored in each node's target field for later
 * use in cost calculation and movement optimization.
 */
void	ps_findtargets(
	t_cdlist **stack_a,
	t_cdlist **stack_b,
	int order,
	size_t run)
{
	t_cdlist	*current_a;
	t_cdlist	*biggest;
	t_cdlist	*smallest;

	if (!*stack_b || ft_cdlstsize(*stack_b) == 1)
		return ;
	current_a = *stack_a;
	biggest = findbiggest(stack_b, run);
	if (order == ORDER_DESCENDING)
		smallest = biggest->previous;
	else
		smallest = biggest->next;
	while (current_a)
	{
		if (ps_data(current_a)->run == run)
		{
			if (order == ORDER_DESCENDING)
				findtarget_des(current_a, stack_b, biggest, smallest);
			else
				findtarget_asc(current_a, stack_b, biggest, smallest);
		}
		current_a = current_a->next;
		if (current_a == *stack_a)
			break ;
	}
}

static t_cdlist	*findbiggest(
	t_cdlist **stack_b,
	size_t run)
{
	t_cdlist	*biggest;
	t_cdlist	*current_b;

	biggest = *stack_b;
	current_b = (*stack_b)->next;
	while (current_b != *stack_b)
	{
		if (ps_data(current_b)->run == run
			&& ps_data(current_b)->num > ps_data(biggest)->num)
			biggest = current_b;
		current_b = current_b->next;
	}
	return (biggest);
}

static void	findtarget_des(
	t_cdlist *current_a,
	t_cdlist **stack_b,
	t_cdlist *biggest,
	t_cdlist *smallest)
{
	if (ps_data(current_a)->num > ps_data(biggest)->num
		|| ps_data(current_a)->num < ps_data(smallest)->num)
		ps_data(current_a)->target = biggest;
	else
	{
		ps_data(current_a)->target = *stack_b;
		while (!(ps_data(ps_data(current_a)->target)->num
				< ps_data(current_a)->num && ps_data(current_a)->num
				< ps_data(ps_data(current_a)->target->previous)->num))
		{
			ps_data(current_a)->target = ps_data(current_a)->target->next;
			if (ps_data(current_a)->target == *stack_b)
				break ;
		}
	}
}

static void	findtarget_asc(
	t_cdlist *current_a,
	t_cdlist **stack_b,
	t_cdlist *biggest,
	t_cdlist *smallest)
{
	if (ps_data(current_a)->num > ps_data(biggest)->num
		|| ps_data(current_a)->num < ps_data(smallest)->num)
		ps_data(current_a)->target = smallest;
	else
	{
		ps_data(current_a)->target = *stack_b;
		while (!(ps_data(ps_data(current_a)->target)->num
				> ps_data(current_a)->num && ps_data(current_a)->num
				> ps_data(ps_data(current_a)->target->previous)->num))
		{
			ps_data(current_a)->target = ps_data(current_a)->target->next;
			if (ps_data(current_a)->target == *stack_b)
				break ;
		}
	}
}
