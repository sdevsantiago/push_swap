/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_timsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 19:02:45 by sede-san          #+#    #+#             */
/*   Updated: 2025/08/30 19:52:49 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		assignruns(t_cdlist **stack);
static t_cdlist	*expandruns(t_cdlist **stack_a, t_cdlist *run_last,
					unsigned long run, int run_order);

/**
 * @brief Sorts large stacks using a Timsort-inspired algorithm.
 *
 * @param stack_a Pointer to the main stack to sort.
 * @param stack_b Pointer to the auxiliary stack.
 *
 * @details
 * Advanced sorting algorithm for stacks > 5 elements inspired by Timsort:
 *
 * 1. **Run Assignment**: Divides stack into runs of THRESHOLD size
 *                        (110 elements)
 * 2. **Run Expansion**: Extends runs by identifying natural
 *                       ascending/descending sequences
 * 3. **Iterative Processing**: Alternates between descending and ascending
 *                              order processing
 * 4. **Insertion Sort**: Uses insertion sort to move run elements to stack_b
 *                        in order
 * 5. **Merge Sort**: Merges sorted runs back to stack_a
 * 6. **Repeat**: Continues until entire stack is sorted in ascending order
 *
 * The alternating order ensures efficient merging and minimizes total
 * operations. This algorithm performs well on large datasets and takes
 * advantage of existing order.
 */
void	ps_timsort(
	t_cdlist **stack_a,
	t_cdlist **stack_b)
{
	size_t	run;
	int		order;

	assignruns(stack_a);
	order = ORDER_DESCENDING;
	while (ps_issorted(stack_a) != ORDER_ASCENDING)
	{
		if (ps_data(*stack_a)->run == SORTED_RUN)
			run = ps_data(ft_cdlstlast(*stack_a))->run;
		else
			run = ps_data(*stack_a)->run;
		ps_insertionsort(stack_a, stack_b, run, order);
		ps_mergesort(stack_a, stack_b, order);
		if (order == ORDER_DESCENDING)
			order = ORDER_ASCENDING;
		else
			order = ORDER_DESCENDING;
	}
}

static void	assignruns(
	t_cdlist **stack_a)
{
	t_cdlist	*current;
	t_cdlist	*run_start;
	size_t		run;
	size_t		i;
	int			order;

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
		order = ps_issorted_run(&run_start, run);
		current = expandruns(stack_a, current, run, order);
		if (current == *stack_a)
			return ;
		run++;
	}
}

static t_cdlist	*expandruns(
	t_cdlist **stack_a,
	t_cdlist *run_last,
	unsigned long run,
	int run_order)
{
	t_cdlist	*current;

	current = run_last;
	if (run_order == ORDER_ASCENDING)
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
	return (current);
}
