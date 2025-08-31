/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_mergesort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 03:14:28 by sede-san          #+#    #+#             */
/*   Updated: 2025/08/30 19:23:33 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	merge_asc(t_cdlist **stack_a, t_cdlist **stack_b,
				size_t sorted_len);
static void	merge_des(t_cdlist **stack_a, t_cdlist **stack_b,
				size_t sorted_len);
static void	merge(t_cdlist **stack_b, t_cdlist **stack_a);

void	ps_mergesort(
	t_cdlist **stack_a,
	t_cdlist **stack_b,
	int order)
{
	size_t	sorted_len;

	if (ps_data(*stack_b)->run == 1)
	{
		while (*stack_b)
			merge(stack_b, stack_a);
		return ;
	}
	sorted_len = ps_runsize(stack_a, SORTED_RUN);
	if (order == ORDER_ASCENDING)
		merge_asc(stack_a, stack_b, sorted_len);
	else
		merge_des(stack_a, stack_b, sorted_len);
}

static void	merge_asc(
	t_cdlist **stack_a,
	t_cdlist **stack_b,
	size_t sorted_len)
{
	while (*stack_b && sorted_len)
	{
		if (ps_data(*stack_b)->num < ps_data(*stack_a)->num)
			merge(stack_b, stack_a);
		else
			sorted_len--;
		ra(stack_a, 1);
	}
	while (sorted_len--)
		ra(stack_a, 1);
	while (*stack_b)
	{
		merge(stack_b, stack_a);
		ra(stack_a, 1);
	}
}

static void	merge_des(t_cdlist **stack_a, t_cdlist **stack_b,
				size_t sorted_len)
{
	while (*stack_b && sorted_len)
	{
		if (ps_data(*stack_b)->num > ps_data(ft_cdlstlast(*stack_a))->num)
			merge(stack_b, stack_a);
		else
		{
			sorted_len--;
			rra(stack_a, 1);
		}
	}
	while (sorted_len--)
		rra(stack_a, 1);
	while (*stack_b)
		merge(stack_b, stack_a);
}

static void	merge(t_cdlist **stack_b, t_cdlist **stack_a)
{
	ps_data(*stack_b)->run = SORTED_RUN;
	ps_data(*stack_b)->target = NULL;
	pa(stack_b, stack_a, 1);
}
