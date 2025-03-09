/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_insertionsort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 19:23:05 by sede-san          #+#    #+#             */
/*   Updated: 2025/03/09 02:00:46 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/push_swap.h"

/**
 * @brief
 */
void	ps_insertionsort(t_cdlist **stack_a, t_cdlist **stack_b,
			size_t run)
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
	while (*stack_a && ps_data(*stack_a)->run == run)
	{
		/*
		TODO Analise which number is cheaper to move based on it's index in
		TODO the stack_a and it's target index in the stack_b, maybe store it's
		TODO cost in the structure
		*/
		//? prepare stack_b
		if (ps_data(*stack_a)->num > ps_data(biggest)->num ||
			ps_data(*stack_a)->num < ps_data(lowest)->num)
		{
			while (*stack_b != biggest)
				rb(stack_b);
			if (ps_data(*stack_a)->num > ps_data(biggest)->num)
				biggest = *stack_a;
			else
				lowest = *stack_a;
		}
		else
		{
			// TODO Make function of this
			t_cdlist	*target_next;	//? This node must be at the top,
										//? it will be the inmediate one
										//? after we push from stack_a

			target_next = *stack_b;
			while (!(ps_data(target_next)->num < ps_data(*stack_a)->num &&
				ps_data(target_next->previous)->num > ps_data(*stack_a)->num))
				target_next = target_next->next;
			while (*stack_b != target_next)
				rb(stack_b);
		}
		//? move to stack_b in order
		pb(stack_a, stack_b);
	}
}
