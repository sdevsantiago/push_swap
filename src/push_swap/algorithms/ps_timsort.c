/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_timsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 19:02:45 by sede-san          #+#    #+#             */
/*   Updated: 2025/03/13 14:40:13 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/push_swap.h"

static void	_assignruns(t_cdlist **stack);

void	ps_timsort(t_cdlist **stack_a, t_cdlist **stack_b)
{
	size_t	run;
	int		order;

	_assignruns(stack_a);
	order = ORDER_DESCENDING;
	while (ps_issorted(stack_a) != ORDER_ASCENDING)
	{
		//? Obtain the run we are going to sort
		if (ps_data(*stack_a)->run == SORTED_RUN)
			run = ps_data(ft_cdlstlast(*stack_a))->run;
		else
			run = ps_data(*stack_a)->run;

		//? Sort the run
		ps_insertionsort(stack_a, stack_b, run, order);
		ps_mergesort(stack_a, stack_b);

		//? Change the order for the next run
		if (order == ORDER_DESCENDING)
			order = ORDER_ASCENDING;
		else
			order = ORDER_DESCENDING;
	}
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

	current = *stack_a;
	run = 1;
	while (current)
	{
		run_start = current;
		i = 0;
		while (i++ < THRESHOLD)
		{
			ps_data(current)->run = run;
			current = current->next;
			if (current == *stack_a)
				return ;
		}
		run_order = ps_issorted_run(&run_start, run);
		if (run_order == ORDER_ASCENDING)
		{
			while (ps_data(current)->num > ps_data(current->previous)->num)
			{
				ps_data(current)->run = run;
				current = current->next;
				if (current == *stack_a)
					return ;
			}
		}
		else if (run_order == ORDER_DESCENDING)
		{
			while (ps_data(current)->num < ps_data(current->previous)->num)
			{
				ps_data(current)->run = run;
				current = current->next;
				if (current == *stack_a)
					return ;
			}
		}
		run++;
	}
}
