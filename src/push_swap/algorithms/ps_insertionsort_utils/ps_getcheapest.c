/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_getcheapest.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 19:08:52 by sede-san          #+#    #+#             */
/*   Updated: 2025/04/21 18:38:20 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../include/push_swap.h"

static unsigned long	_calccost(t_cdlist **stack_a, t_cdlist **stack_b,
							t_cdlist *current_a);

/**
 * @brief
 *
 * @return Returns the cheapest, movement wise, node to move
 *
 * @details The cost is calculated with the following formula:
 * 	1 -> cost to push to b
 *	index_a -> where the number is located in the stack_a
 *	index_b -> where the number following to the current in stack_a is in the
 *				stack_b
 */
t_cdlist	*ps_getcheapest(t_cdlist **stack_a, t_cdlist **stack_b,
				size_t run, int order)
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
			&& _calccost(stack_a, stack_b, cheapest)
			> _calccost(stack_a, stack_b, current_a))
			cheapest = current_a;
		current_a = current_a->next;
		if (current_a == *stack_a)
			break ;
	}
	return (cheapest);
}

static unsigned long	_calccost(t_cdlist **stack_a, t_cdlist **stack_b,
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
