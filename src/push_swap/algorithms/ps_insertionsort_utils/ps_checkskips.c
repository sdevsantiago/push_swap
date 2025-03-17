/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_checkskips.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 14:35:07 by sede-san          #+#    #+#             */
/*   Updated: 2025/03/14 14:38:11 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../include/push_swap.h"

static int	_checkbiggerlower(t_cdlist **stack_a);

int	ps_checkskips(t_cdlist **stack_a)
{
	if (_checkbiggerlower(stack_a))
		return (1);
	return (0);
}

/**
 * @brief Checks if the number to sort in `stack_b` can be placed directly in
 * the sorted run, in which case it moves moves it.
 *
 * @param stack_a
 *
 * @return Returns `1` if the number has been sorted in the sorted run, else
 * returns `0`.
 *
 * @details This function first checks if the sorted run is either in the first
 * or the last position of the stack. If the sorted run is at the head of the
 * stack, the skip can be done by inserting a number lower than the first one of
 * the sorted run. On the other hand, if the sorted run is at the bottom of the
 * stack, the skip can be done by inserting a number higher than the last one of
 * the sorted run. If one of these cases can be achieved, the movement is done
 * and the skip is resolved, in which case 1 is returned.
 *
 * @note This is only valid if we don't have the run to sort in both the top and
 * the bottom of the stack.
 */
static int	_checkbiggerlower(t_cdlist **stack_a)
{
	if (ps_data(*stack_a)->run != SORTED_RUN &&
		ps_data(ft_cdlstlast(*stack_a))->run == SORTED_RUN &&
		ps_data(*stack_a)->num > ps_data(ft_cdlstlast(*stack_a))->num)
	{
		ps_data(*stack_a)->run = SORTED_RUN;
		ra(stack_a);
		return (1);
	}
	else if (ps_data(*stack_a)->run == SORTED_RUN &&
		ps_data(ft_cdlstlast(*stack_a))->run != SORTED_RUN &&
		ps_data(ft_cdlstlast(*stack_a))->num < ps_data(*stack_a)->num)
	{
		ps_data(ft_cdlstlast(*stack_a))->run = SORTED_RUN;
		rra(stack_a);
		return (1);
	}
	return (0);
}
