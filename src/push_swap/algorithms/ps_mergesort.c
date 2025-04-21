/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_mergesort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 03:14:28 by sede-san          #+#    #+#             */
/*   Updated: 2025/04/21 15:41:43 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/push_swap.h"
#include "../../../lib/ft_printf/ft_printf.h"

static void	_merge_ascending(t_cdlist **stack_a, t_cdlist **stack_b,
				size_t sorted_len);
static void	_merge_descending(t_cdlist **stack_a, t_cdlist **stack_b,
				size_t sorted_len);
static void	_merge(t_cdlist **stack_b, t_cdlist **stack_a);

/**
 * @brief Merges a newly sorted in `stack_b` run with the sorted run in
 * `stack_a`.
 *
 * @param stack_a The stack_a
 * @param stack_b The stack_b
 * @param order The order used to sort the run in `stack_b`
 */
void	ps_mergesort(t_cdlist **stack_a, t_cdlist **stack_b, int order)
{
	size_t	sorted_len;

	if (ps_data(*stack_b)->run == 1)
	{
		while (*stack_b)
			_merge(stack_b, stack_a);
		return ;
	}
	sorted_len = ps_runsize(stack_a, SORTED_RUN);
	if (order == ORDER_ASCENDING)
		_merge_ascending(stack_a, stack_b, sorted_len);
	else
		_merge_descending(stack_a, stack_b, sorted_len);
}

static void	_merge_ascending(t_cdlist **stack_a, t_cdlist **stack_b,
				size_t sorted_len)
{
	while (*stack_b && sorted_len)
	{
		if (ps_data(*stack_b)->num < ps_data(*stack_a)->num)
			_merge(stack_b, stack_a);
		else
			sorted_len--;
		ra(stack_a);
	}
	while (sorted_len--)
		ra(stack_a);
	while (*stack_b)
	{
		_merge(stack_b, stack_a);
		ra(stack_a);
	}
}

static void	_merge_descending(t_cdlist **stack_a, t_cdlist **stack_b,
				size_t sorted_len)
{
	while (*stack_b && sorted_len)
	{
		if (ps_data(*stack_b)->num > ps_data(ft_cdlstlast(*stack_a))->num)
			_merge(stack_b, stack_a);
		else
		{
			sorted_len--;
			rra(stack_a);
		}
	}
	while (sorted_len--)
		rra(stack_a);
	while (*stack_b)
		_merge(stack_b, stack_a);
}

/**
 * @brief Moves the head of `stack_b` to `stack_a`, asigning the node to the
 * sorted run.
 *
 * @param stack_b The stack_b
 * @param stack_a The stack_a
 *
 * @note If the sorted run is at the bottom of `stack_a`, an `ra` operation is
 * needed.
 */
static void	_merge(t_cdlist **stack_b, t_cdlist **stack_a)
{
	ps_data(*stack_b)->run = SORTED_RUN;
	ps_data(*stack_b)->target = NULL;
	pa(stack_b, stack_a);
}
