/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_mergesort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 03:14:28 by sede-san          #+#    #+#             */
/*   Updated: 2025/03/09 05:40:32 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/push_swap.h"

void	ps_mergesort(t_cdlist **stack_a, t_cdlist **stack_b)
{
	size_t	run;

	run = ps_data(*stack_b)->run;
	if (run <= 1)
	{
		while (!(ps_data((*stack_b))->num >
			ps_data((*stack_b)->previous)->num))
			rb(stack_b);
		while (*stack_b)
		{
			pa(stack_b, stack_a);
			ps_data(*stack_a)->run = SORTED_RUN;
		}
		return ;
	}
	while (!(ps_data((*stack_b))->num >
		ps_data((*stack_b)->previous)->num))
		rb(stack_b);
	if (ps_data(*stack_a)->run == SORTED_RUN)	//? sorted run is at the top
	{
		while (*stack_b)
		{
			if (ps_data(ft_cdlstlast(*stack_b))->num < ps_data(*stack_a)->num)
			{
				rrb(stack_b);
				pa(stack_b, stack_a);
				ps_data(*stack_a)->run = SORTED_RUN;
			}
			ra(stack_a);
		}
		ra(stack_a);
	}
	else										//? sorted run is at the bottom
	{
		while (*stack_b)
		{
			if (ps_data(*stack_b)->num > ps_data(*stack_a)->num)
			{
				pa(stack_b, stack_a);
				ps_data(*stack_a)->run = SORTED_RUN;
			}
		}
		ra(stack_a);
	}
}
