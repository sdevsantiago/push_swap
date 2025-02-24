/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverserotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 18:03:07 by sede-san          #+#    #+#             */
/*   Updated: 2025/02/23 19:45:16 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/push_swap.h"
#include "../../../lib/ft_printf/ft_printf.h"

static void	_reverserotate(t_cdlist **stack)
{
	*stack = (*stack)->previous;
}

void	rra(t_cdlist *stack_a)
{
	_reverserotate(&stack_a);
	ft_printf("ra\n");
}

void	rrb(t_cdlist *stack_b)
{
	_reverserotate(&stack_b);
	ft_printf("rb\n");
}

void	rrr(t_cdlist *stack_a, t_cdlist *stack_b)
{
	_reverserotate(&stack_a);
	_reverserotate(&stack_b);
	ft_printf("rr\n");
}