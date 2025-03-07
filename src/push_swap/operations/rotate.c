/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 18:03:09 by sede-san          #+#    #+#             */
/*   Updated: 2025/03/07 16:14:24 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/push_swap.h"
#include "../../../lib/ft_printf/ft_printf.h"

static void	_rotate(t_cdlist **stack)
{
	*stack = (*stack)->next;
}

void	ra(t_cdlist **stack_a)
{
	_rotate(stack_a);
	ft_printf("ra\n");
}

void	rb(t_cdlist **stack_b)
{
	_rotate(stack_b);
	ft_printf("rb\n");
}

void	rr(t_cdlist **stack_a, t_cdlist **stack_b)
{
	_rotate(stack_a);
	_rotate(stack_b);
	ft_printf("rr\n");
}
