/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 02:55:04 by sede-san          #+#    #+#             */
/*   Updated: 2025/08/30 19:57:40 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Rotates all elements of a stack up by one position.
 *
 * @param stack Pointer to the stack to rotate.
 *
 * @details
 * The first element becomes the last, and all other elements move up one
 * position. In a circular doubly linked list, this is simply moving the stack
 * pointer to the next element.
 */
static void	rotate(
	t_cdlist **stack)
{
	*stack = (*stack)->next;
}

/**
 * @brief Rotate stack_a up by one position.
 *
 * @param stack_a Pointer to stack_a.
 * @param print Whether to print the operation name (1) or not (0).
 *
 * @details
 * Performs the 'ra' operation: the first element becomes the last. If print is
 * true, updates indexes and prints "ra".
 */
void	ra(
	t_cdlist **stack_a,
	int print)
{
	rotate(stack_a);
	if (print)
	{
		ps_updateindexes(stack_a, NULL);
		ft_putendl(RA);
	}
}

/**
 * @brief Rotate stack_b up by one position.
 *
 * @param stack_b Pointer to stack_b.
 * @param print Whether to print the operation name (1) or not (0).
 *
 * @details
 * Performs the 'rb' operation: the first element becomes the last. If print is
 * true, updates indexes and prints "rb".
 */
void	rb(
	t_cdlist **stack_b,
	int print)
{
	rotate(stack_b);
	if (print)
	{
		ps_updateindexes(NULL, stack_b);
		ft_putendl(RB);
	}
}

/**
 * @brief Rotate both stack_a and stack_b up by one position simultaneously.
 *
 * @param stack_a Pointer to stack_a.
 * @param stack_b Pointer to stack_b.
 * @param print Whether to print the operation name (1) or not (0).
 *
 * @details Performs the 'rr' operation: equivalent to ra + rb but counts as
 * one operation. If print is true, updates indexes and prints "rr".
 */
void	rr(
	t_cdlist **stack_a,
	t_cdlist **stack_b,
	int print)
{
	rotate(stack_a);
	rotate(stack_b);
	if (print)
	{
		ps_updateindexes(stack_a, stack_b);
		ft_putendl(RR);
	}
}
