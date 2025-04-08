/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_mergesort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 03:14:28 by sede-san          #+#    #+#             */
/*   Updated: 2025/04/08 10:25:38 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/push_swap.h"
#include "../../../lib/ft_printf/ft_printf.h"

// static void _stackdump(t_cdlist **stack, char stack_letter)
// {
// 	t_cdlist	*current;

// 	ft_printf("stack_%c:", stack_letter);
// 	if (!*stack)
// 	{
// 		ft_printf("Empty\n");
// 		return ;
// 	}
// 	current = *stack;
// 	while (current)
// 	{
// 		ft_printf(" %d", ps_data(current)->num);
// 		current = current->next;
// 		if (current == *stack)
// 			break ;
// 	}
// 	ft_printf("\n");
// }

static void	_merge(t_cdlist **stack_b, t_cdlist **stack_a);

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
		while (*stack_b && sorted_len)
		{
			if (order == ORDER_ASCENDING)
			{
				if (ps_data(*stack_b)->num < ps_data(*stack_a)->num)
					_merge(stack_b, stack_a);
				else
					sorted_len--;
				ra(stack_a);
			}
			else
			{
				if (ps_data(*stack_b)->num > ps_data(ft_cdlstlast(*stack_a))->num)
					_merge(stack_b, stack_a);
				else
				{
					sorted_len--;
					rra(stack_a);
				}
			}
			// _stackdump(stack_a, 'a');
			// _stackdump(stack_b, 'b');
		}
		while (sorted_len--)
			if (order == ORDER_ASCENDING)
				ra(stack_a);
			else
				rra(stack_a);
		while (*stack_b)
		{
			if (order == ORDER_ASCENDING)
			{
				_merge(stack_b, stack_a);
				ra(stack_a);
			}
			else
				_merge(stack_b, stack_a);
		}
		// _stackdump(stack_a, 'a');
		// _stackdump(stack_b, 'b');
}

static void	_merge(t_cdlist **stack_b, t_cdlist **stack_a)
{
	ps_data(*stack_b)->run = SORTED_RUN;
	ps_data(*stack_b)->target = NULL;
	pa(stack_b, stack_a);
}
