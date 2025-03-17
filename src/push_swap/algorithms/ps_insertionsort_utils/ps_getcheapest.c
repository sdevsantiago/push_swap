/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_getcheapest.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 19:08:52 by sede-san          #+#    #+#             */
/*   Updated: 2025/03/17 16:01:21 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../include/push_swap.h"

static unsigned long	_calccost(t_cdlist **stack_a, t_cdlist **stack_b,
							t_cdlist *current_a, t_cdlist *target_b);

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
	unsigned long	cost_cheapest;

	if (!*stack_b)
		return (*stack_a);
	ps_findtargets(stack_a, stack_b, order, run);
	current_a = cheapest = *stack_a;
	cost_cheapest = _calccost(stack_a, stack_b,
		cheapest, ps_data(cheapest)->target);
	while (current_a)
	{
		if (ps_data(current_a)->run == run && cost_cheapest >
			_calccost(stack_a, stack_b, current_a, ps_data(current_a)->target))
		{
			cost_cheapest =	_calccost(stack_a, stack_b,
				current_a, ps_data(current_a)->target);
			cheapest = current_a;
		}
		current_a = current_a->next;
		if (current_a == *stack_a)
			break ;
	}
	return (cheapest);
}

static unsigned long	_calccost(t_cdlist **stack_a, t_cdlist **stack_b,
							t_cdlist *current_a, t_cdlist *target_b)
{
	int	moves_a;
	int	moves_b;

	if (ps_data(current_a)->index <= (size_t)ft_cdlstsize(*stack_a) / 2)
		moves_a = ps_data(current_a)->index;
	else
		moves_a = (size_t)ft_cdlstsize(*stack_a) + ps_data(current_a)->index;
	if (ps_data(target_b)->index <= (size_t)ft_cdlstsize(*stack_b) / 2)
		moves_b = ps_data(target_b)->index;
	else
		moves_b = (size_t)ft_cdlstsize(*stack_b) - ps_data(target_b)->index;
	return (moves_a + moves_b + 1);
}
