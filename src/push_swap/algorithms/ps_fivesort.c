/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_fivesort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 13:58:18 by sede-san          #+#    #+#             */
/*   Updated: 2025/08/30 19:51:57 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		updateindexes(t_cdlist **stack);
static t_cdlist	*getlowest(t_cdlist **stack_a);

/**
 * @brief Sorts a five-element stack optimally.
 *
 * @param stack_a Pointer to the main stack containing five elements.
 * @param stack_b Pointer to the auxiliary stack (initially empty).
 *
 * @details
 * Algorithm strategy:
 *
 * 1. Find the smallest element and move it to top using optimal rotations:
 *    - Position 1: sa (1 operation)
 *    - Position 2: ra ra (2 operations)
 *    - Position 3: rra rra (2 operations)
 *    - Position 4: rra (1 operation)
 *
 * 2. Check if already sorted after positioning
 *
 * 3. If not sorted: push smallest to stack_b
 *
 * 4. Update indexes and use 4-element sort on remaining elements
 *
 * 5. Push smallest back to top of sorted stack
 *
 * This reduces the problem to a 4-element sort while ensuring the
 * smallest element ends up in the correct position.
 */
void	ps_fivesort(
	t_cdlist **stack_a,
	t_cdlist **stack_b)
{
	size_t	i_big;

	if (!stack_a || !*stack_a)
		return ;
	i_big = ps_data(getlowest(stack_a))->index;
	if (i_big == 1)
		sa(stack_a, 1);
	else if (i_big == 2)
	{
		ra(stack_a, 1);
		ra(stack_a, 1);
	}
	else if (i_big == 3)
	{
		rra(stack_a, 1);
		rra(stack_a, 1);
	}
	else if (i_big == 4)
		rra(stack_a, 1);
	if (ps_issorted(stack_a) == ORDER_ASCENDING)
		return ;
	pb(stack_a, stack_b, 1);
	updateindexes(stack_a);
	ps_foursort(stack_a, stack_b);
	pa(stack_b, stack_a, 1);
}

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
