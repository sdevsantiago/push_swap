/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_foursort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 13:55:36 by sede-san          #+#    #+#             */
/*   Updated: 2025/08/30 19:52:13 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		updateindexes(t_cdlist **stack);
static t_cdlist	*getlowest(t_cdlist **stack_a);

/**
 * @brief Sorts a four-element stack optimally.
 *
 * @param stack_a Pointer to the main stack containing four elements.
 * @param stack_b Pointer to the auxiliary stack (initially empty).
 *
 * @details
 * Algorithm strategy:
 *
 * 1. Find the smallest element in the stack
 *
 * 2. Move smallest to top using optimal rotations:
 *    - Position 1: sa (1 operation)
 *    - Position 2: rra rra (2 operations)
 *    - Position 3: rra (1 operation)
 *
 * 3. Check if already sorted after positioning
 *
 * 4. If not sorted: push smallest to stack_b
 *
 * 5. Update indexes and sort remaining 3 elements
 *
 * 6. Push smallest back to top of sorted stack
 *
 * This ensures the smallest element is in correct position and reduces
 * the problem to a 3-element sort.
 */
void	ps_foursort(
	t_cdlist **stack_a,
	t_cdlist **stack_b)
{
	size_t	i_low;

	if (!stack_a || !*stack_a)
		return ;
	i_low = ps_data(getlowest(stack_a))->index;
	if (i_low == 1)
		sa(stack_a, 1);
	else if (i_low == 2)
	{
		rra(stack_a, 1);
		rra(stack_a, 1);
	}
	else if (i_low == 3)
		rra(stack_a, 1);
	if (ps_issorted(stack_a) == ORDER_ASCENDING)
		return ;
	pb(stack_a, stack_b, 1);
	updateindexes(stack_a);
	ps_threesort(stack_a);
	pa(stack_b, stack_a, 1);
}

/**
 * @brief Finds the node containing the smallest number in the stack.
 *
 * @param stack_a Pointer to the stack to search.
 *
 * @return Pointer to the node containing the smallest number, or NULL if stack
 *         is empty.
 *
 * @details
 * Iterates through the circular doubly linked list once to find the node with
 * the minimum value.
 */
static t_cdlist	*getlowest(
	t_cdlist **stack_a)
{
	t_cdlist	*current;
	t_cdlist	*lowest;

	if (!stack_a || !*stack_a)
		return (NULL);
	current = *stack_a;
	lowest = current;
	while (current)
	{
		if (ps_data(current)->num < ps_data(lowest)->num)
			lowest = current;
		current = current->next;
		if (current == *stack_a)
			break ;
	}
	return (lowest);
}

static void	updateindexes(
	t_cdlist	**stack)
{
	t_cdlist	*current;
	size_t		i;

	current = *stack;
	i = 0;
	while (current)
	{
		ps_data(current)->index = i++;
		current = current->next;
		if (current == *stack)
			break ;
	}
}
