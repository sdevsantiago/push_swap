/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverserotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 18:03:07 by sede-san          #+#    #+#             */
/*   Updated: 2025/08/30 19:56:51 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Rotates all elements of a stack down by one position.
 *
 * @param stack Pointer to the stack to reverse rotate.
 *
 * @details
 * The last element becomes the first, and all other elements move down one
 * position. In a circular doubly linked list, this is simply moving the stack
 * pointer to the last element.
 */
static void	reverserotate(
	t_cdlist **stack)
{
	*stack = ft_cdlstlast(*stack);
}

/**
 * @brief Reverse rotate stack_a down by one position.
 *
 * @param stack_a Pointer to stack_a.
 * @param print Whether to print the operation name (1) or not (0).
 *
 * @details
 * Performs the 'rra' operation: the last element becomes the first. If print is
 * true, updates indexes and prints "rra".
 */
void	rra(
	t_cdlist **stack_a,
	int print)
{
	reverserotate(stack_a);
	if (print)
	{
		ps_updateindexes(stack_a, NULL);
		ft_putendl(RRA);
	}
}

/**
 * @brief Reverse rotate stack_b down by one position.
 *
 * @param stack_b Pointer to stack_b.
 * @param print Whether to print the operation name (1) or not (0).
 *
 * @details
 * Performs the 'rrb' operation: the last element becomes the first. If print is
 * true, updates indexes and prints "rrb".
 */
void	rrb(
	t_cdlist **stack_b,
	int print)
{
	reverserotate(stack_b);
	if (print)
	{
		ps_updateindexes(NULL, stack_b);
		ft_putendl(RRB);
	}
}

/**
 * @brief Reverse rotate both stack_a and stack_b down by one position
 *        simultaneously.
 *
 * @param stack_a Pointer to stack_a.
 * @param stack_b Pointer to stack_b.
 * @param print Whether to print the operation name (1) or not (0).
 *
 * @details
 * Performs the 'rrr' operation: equivalent to rra + rrb but counts as one
 * operation. If print is true, updates indexes and prints "rrr".
 */
void	rrr(
	t_cdlist **stack_a,
	t_cdlist **stack_b,
	int print)
{
	reverserotate(stack_a);
	reverserotate(stack_b);
	if (print)
	{
		ps_updateindexes(stack_a, stack_b);
		ft_putendl(RRR);
	}
}
