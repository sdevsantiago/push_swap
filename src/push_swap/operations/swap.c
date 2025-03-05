/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 18:03:11 by sede-san          #+#    #+#             */
/*   Updated: 2025/03/05 18:13:50 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/push_swap.h"
#include "../../../lib/ft_printf/ft_printf.h"

static void	_swap(t_cdlist **stack)
{
	t_cdlist	*first_node;
	t_cdlist	*second_node;
	t_cdlist	*third_node;

	first_node = *stack;
	second_node = (*stack)->next;
	if (second_node->next != first_node)
	{
		third_node = second_node->next;
		if (third_node->next == first_node)
			third_node->next = second_node;
		third_node->previous = first_node;
		first_node->next = third_node;
		first_node->previous = second_node;
		second_node->next = first_node;
	}
	*stack = second_node;
}

void	sa(t_cdlist **stack_a)
{
	_swap(stack_a);
	ft_printf("sa\n");
}

void	sb(t_cdlist **stack_b)
{
	_swap(stack_b);
	ft_printf("sb\n");
}

void	ss(t_cdlist **stack_a, t_cdlist **stack_b)
{
	_swap(stack_a);
	_swap(stack_b);
	ft_printf("ss\n");
}
