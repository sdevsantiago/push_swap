/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_updateindexes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 21:42:09 by sede-san          #+#    #+#             */
/*   Updated: 2025/08/30 19:41:55 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	update_a(t_cdlist **current_a, t_cdlist **stack_a, size_t index);
static void	update_b(t_cdlist **current_b, t_cdlist **stack_b, size_t index);

/**
 * @brief Updates the index field for all nodes in both stacks.
 *
 * @param stack_a Pointer to stack_a (can be NULL).
 * @param stack_b Pointer to stack_b (can be NULL).
 *
 * @details Recalculates position indexes for all elements in both stacks
 * after operations that change element positions. This is essential for:
 * - Determining optimal rotation direction (top half vs bottom half)
 * - Cost calculations in sorting algorithms
 * - Maintaining accurate position references
 *
 * The function safely handles NULL stacks and updates indexes starting from 0.
 */
void	ps_updateindexes(
	t_cdlist **stack_a,
	t_cdlist **stack_b)
{
	t_cdlist	*current_a;
	t_cdlist	*current_b;
	size_t		i;

	if (stack_a)
		current_a = *stack_a;
	else
		current_a = NULL;
	if (stack_b)
		current_b = *stack_b;
	else
		current_b = NULL;
	i = 0;
	while (current_a || current_b)
	{
		if (current_a)
			update_a(&current_a, stack_a, i);
		if (current_b)
			update_b(&current_b, stack_b, i);
		i++;
	}
}

static void	update_a(
	t_cdlist **current_a,
	t_cdlist **stack_a,
	size_t index)
{
	ps_data(*current_a)->index = index;
	*current_a = (*current_a)->next;
	if (*current_a == *stack_a)
		*current_a = NULL;
}

static void	update_b(
	t_cdlist **current_b,
	t_cdlist **stack_b,
	size_t index)
{
	ps_data(*current_b)->index = index;
	*current_b = (*current_b)->next;
	if (*current_b == *stack_b)
		*current_b = NULL;
}
