/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverserotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 18:03:07 by sede-san          #+#    #+#             */
/*   Updated: 2025/03/12 21:44:12 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/push_swap.h"
#include "../../../lib/ft_printf/ft_printf.h"

static void	_reverserotate(t_cdlist **stack)
{
	*stack = ft_cdlstlast(*stack);
}

void	rra(t_cdlist **stack_a)
{
	_reverserotate(stack_a);
	ps_updateindexes(stack_a, NULL);
	ft_printf("rra\n");
}

void	rrb(t_cdlist **stack_b)
{
	_reverserotate(stack_b);
	ps_updateindexes(NULL, stack_b);
	ft_printf("rrb\n");
}

void	rrr(t_cdlist **stack_a, t_cdlist **stack_b)
{
	_reverserotate(stack_a);
	_reverserotate(stack_b);
	ps_updateindexes(stack_a, stack_b);
	ft_printf("rrr\n");
}
