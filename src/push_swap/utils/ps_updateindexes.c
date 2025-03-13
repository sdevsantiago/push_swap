/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_updateindexes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 21:42:09 by sede-san          #+#    #+#             */
/*   Updated: 2025/03/13 14:05:51 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/push_swap.h"

/**
 * @brief Updates the indexes in both stacks.
 * @param stack_a The `stack_a`
 * @param stack_b The `stack_b`
 */
void	ps_updateindexes(t_cdlist **stack_a, t_cdlist **stack_b)
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
		{
			ps_data(current_a)->index = i;
			current_a = current_a->next;
			if (current_a == *stack_a)
				current_a = NULL;
		}
		if (current_b)
		{
			ps_data(current_b)->index = i;
			current_b = current_b->next;
			if (current_b == *stack_b)
				current_b = NULL;
		}
		i++;
	}
}
