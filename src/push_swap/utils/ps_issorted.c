/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_issorted.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 19:09:16 by sede-san          #+#    #+#             */
/*   Updated: 2025/08/30 19:59:45 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Checks if a stack is sorted and determines the sorting order.
 *
 * @param stack Pointer to the stack to check.
 *
 * @return ORDER_ASCENDING (1) if sorted in ascending order,
 *         ORDER_DESCENDING (-1) if sorted in descending order,
 *         ORDER_MIXED (0) if not sorted or mixed order.
 *
 * @details
 * Analyzes the entire stack to determine sorting state:
 * - Starts assuming ascending order
 * - If a descending pair is found, switches to expecting descending
 * - If both ascending and descending pairs exist, returns mixed
 * - A fully ascending or descending stack returns the appropriate order
 *
 * This function is crucial for:
 * - Early termination when stack is already sorted
 * - Algorithm selection based on current order
 * - Validation of sorting correctness
 */
int	ps_issorted(
	t_cdlist **stack)
{
	int			order;
	t_cdlist	*current;

	current = (*stack)->next;
	order = ORDER_ASCENDING;
	while (current)
	{
		if (ps_data(current->previous)->num > ps_data(current)->num)
		{
			if (order == ORDER_ASCENDING)
				order = ORDER_DESCENDING;
		}
		else
		{
			if (order == ORDER_DESCENDING)
				return (ORDER_MIXED);
		}
		current = current->next;
		if (current == *stack)
			break ;
	}
	return (order);
}
