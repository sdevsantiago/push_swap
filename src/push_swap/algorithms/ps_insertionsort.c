/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_insertionsort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 19:23:05 by sede-san          #+#    #+#             */
/*   Updated: 2025/02/25 15:39:38 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/push_swap.h"

/**
 * @brief
 */
void	ps_insertionsort(t_cdlist **stack_a, t_cdlist **stack_b,
							unsigned char const run)
{
	t_cdlist	*biggest;
	t_cdlist	*lowest;

	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
	if (ps_data(*stack_b)->num > ps_data((*stack_b)->next)->num)
		biggest = *stack_b;
	else
		biggest = (*stack_b)->next;
	if (ps_data(*stack_b)->num < ps_data((*stack_b)->next)->num)
		lowest = *stack_b;
	else
		lowest = (*stack_b)->next;
	while (ps_data(*stack_a)->run == run)
	{
		if (ps_data(*stack_a)->num > ps_data(biggest)->num)
		{
			while ((*stack_b)->previous != lowest)
				rb(stack_b);
			biggest = *stack_a;
		}
		else if (ps_data(*stack_a)->num < ps_data(lowest)->num)
		{
			while ((*stack_b) != biggest)
				rb(stack_b);
			lowest = *stack_a;
		}
		else
			while (ps_data(*stack_b)->num > ps_data(*stack_a)->num)
				rb(stack_b);
		pb(stack_a, stack_b);
	}
	while ((*stack_b) != biggest)
		rb(stack_b);
}
