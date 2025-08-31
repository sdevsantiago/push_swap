/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 18:03:11 by sede-san          #+#    #+#             */
/*   Updated: 2025/08/31 01:25:49 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Swaps the first two elements of a stack.
 *
 * @param stack Pointer to the stack to modify.
 *
 * @details
 * Handles the complex pointer manipulation required for swapping the first two
 * nodes in a circular doubly linked list. Updates all necessary next/previous
 * pointers to maintain list integrity.
 *
 * Special cases handled:
 * - 2-element stack: Simple pointer swap
 * - 3+ element stack: Complex pointer rearrangement
 */
static void	swap(
	t_cdlist **stack)
{
	t_cdlist	*first_node;
	t_cdlist	*second_node;
	t_cdlist	*third_node;
	t_cdlist	*last_node;

	first_node = *stack;
	second_node = first_node->next;
	if (second_node->next != first_node)
	{
		last_node = ft_cdlstlast(*stack);
		third_node = second_node->next;
		if (third_node->next == first_node)
			third_node->next = second_node;
		third_node->previous = first_node;
		first_node->next = third_node;
		first_node->previous = second_node;
		second_node->next = first_node;
		second_node->previous = last_node;
		last_node->next = second_node;
	}
	*stack = second_node;
}

/**
 * @brief Swap the first two elements of stack_a.
 *
 * @param stack_a Pointer to stack_a.
 * @param print   Whether to print the operation name (1) or not (0).
 *
 * @details
 * Performs the 'sa' operation: swaps the top two elements of stack_a. If print
 * is true, updates indexes and prints "sa".
 */
void	sa(
	t_cdlist **stack_a,
	int print)
{
	swap(stack_a);
	if (print)
	{
		ps_updateindexes(stack_a, NULL);
		ft_putendl(SA);
	}
}

/**
 * @brief Swap the first two elements of stack_b.
 *
 * @param stack_b Pointer to stack_b.
 * @param print   Whether to print the operation name (1) or not (0).
 *
 * @details
 * Performs the 'sb' operation: swaps the top two elements of stack_b. If print
 * is true, updates indexes and prints "sb".
 */
void	sb(
	t_cdlist **stack_b,
	int print)
{
	swap(stack_b);
	if (print)
	{
		ps_updateindexes(NULL, stack_b);
		ft_putendl(SB);
	}
}

/**
 * @brief Swap the first two elements of both stack_a and stack_b simultaneously.
 *
 * @param stack_a Pointer to stack_a.
 * @param stack_b Pointer to stack_b.
 * @param print Whether to print the operation name (1) or not (0).
 *
 * @details Performs the 'ss' operation: equivalent to sa + sb but counts as
 * one operation. If print is true, updates indexes and prints "ss".
 */
void	ss(
	t_cdlist **stack_a,
	t_cdlist **stack_b,
	int print)
{
	swap(stack_a);
	swap(stack_b);
	if (print)
	{
		ps_updateindexes(stack_a, stack_b);
		ft_putendl(SS);
	}
}
