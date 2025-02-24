/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 18:03:11 by sede-san          #+#    #+#             */
/*   Updated: 2025/02/24 01:20:45 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/push_swap.h"
#include "../../../lib/ft_printf/ft_printf.h"

static void	_swap(t_cdlist **stack)
{
	t_cdlist	*first_node;
	t_cdlist	*second_node;

	first_node = *stack;
	second_node = (*stack)->next;
	ft_cdlstlast(*stack)->next = second_node;
	second_node->next->previous = first_node;
	ft_swap(first_node->next, second_node->next);
	ft_swap(first_node->previous, second_node->previous);
	*stack = second_node;
}

void	sa(t_cdlist *stack_a)
{
	_swap(&stack_a);
	ft_printf("sa\n");
}

void	sb(t_cdlist *stack_b)
{
	_swap(&stack_b);
	ft_printf("sb\n");
}

void	ss(t_cdlist *stack_a, t_cdlist *stack_b)
{
	_swap(&stack_a);
	_swap(&stack_b);
	ft_printf("ss\n");
}
