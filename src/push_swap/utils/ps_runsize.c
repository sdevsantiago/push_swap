/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_runsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 14:38:24 by sede-san          #+#    #+#             */
/*   Updated: 2025/08/30 20:00:25 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Calculates the number of elements in a specific run.
 *
 * @param stack Pointer to the stack to analyze.
 * @param run The run identifier to count.
 *
 * @return Number of elements belonging to the specified run.
 *
 * @details
 * Iterates through the entire stack once and counts nodes that belong to the
 * specified run. Used in timsort algorithm to:
 * - Determine run sizes for processing order
 * - Calculate costs for insertion sort operations
 * - Validate run assignments
 */
size_t	ps_runsize(
	t_cdlist **stack,
	size_t run)
{
	size_t		size;
	t_cdlist	*current;

	size = 0;
	current = *stack;
	while (current)
	{
		if (ps_data(current)->run == run)
			size++;
		current = current->next;
		if (current == *stack)
			break ;
	}
	return (size);
}
