/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_findtargets.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 21:16:02 by sede-san          #+#    #+#             */
/*   Updated: 2025/03/16 21:18:41 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../include/push_swap.h"

/**
 * @brief Finds the following/previous node in `stack_b` for the nodes in
 * `stack_a`.
 *
 * @note This function gives a value to the target data in `s_push_swap`.
 */
void	ps_findtargets(t_cdlist **stack_a, t_cdlist **stack_b, int order,
			size_t run)
{
	t_cdlist	*current_a;
	t_cdlist	*target_b;

	current_a = *stack_a;
	if (!*stack_b)
		return ;
	while (current_a)
	{
		target_b = *stack_b;
		if (ps_data(current_a)->run == run)
		{
			if (order == ORDER_DESCENDING)
				while (!(ps_data(target_b)->num < ps_data(current_a)->num &&
					ps_data(target_b->previous)->num > ps_data(current_a)->num))
					target_b = target_b->next;
			else
				while (!(ps_data(target_b)->num > ps_data(current_a)->num &&
					ps_data(target_b->previous)->num < ps_data(current_a)->num))
				target_b = target_b->next;
			ps_data(current_a)->target = target_b;
		}
		current_a = current_a->next;
		if (current_a == *stack_a)
			break ;
	}
}
