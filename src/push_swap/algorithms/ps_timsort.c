/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_timsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 19:02:45 by sede-san          #+#    #+#             */
/*   Updated: 2025/02/25 15:40:44 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/push_swap.h"

static void	_assignruns(t_cdlist **stack);

void	ps_timsort(t_cdlist **stack_a, t_cdlist **stack_b, size_t size)
{
	_assignruns(stack_a);
	if (size)
		ps_insertionsort(stack_a, stack_b, 1);

	ps_insertionsort(stack_a, stack_b, ORDER_ASCENDING);
}

/**
 * @brief Assigns a run to each node in `stack_a`.
 * @param stack_a The initial stack before any modifications.
 * @details 
 * @note This function should be executed one time only.
 */
static void _assignruns(t_cdlist **stack_a)
{
	t_cdlist	*current;
	t_cdlist	*run_start;
	size_t		run;
	size_t		i;
	int			run_order;

	run_start = current = *stack_a;
	run = 1;
	while (current)
	{
		i = 0;
		while (i++ < THRESHOLD)
		{
			ps_data(current)->run = run;
			current = current->next;
			if (current == *stack_a)
				break ;
		}
		if ((run_order = ps_issorted_run(&run_start, run)) == ORDER_ASCENDING)
		{
			while (ps_data(current)->num > ps_data(current->previous)->num)
			{
				ps_data(current)->run = run;
				current = current->next;
				if (current == *stack_a)
					break ;
			}
		}
		else if (run_order == ORDER_DESCENDING)
		{
			while (ps_data(current)->num < ps_data(current->previous)->num)
			{
				ps_data(current)->run = run;
				current = current->next;
				if (current == *stack_a)
					break ;
			}
			
		}
	}
}
