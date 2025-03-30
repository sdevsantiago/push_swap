/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_insertionsort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 19:23:05 by sede-san          #+#    #+#             */
/*   Updated: 2025/03/31 00:55:24 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/push_swap.h"

static void	_movetotop_both(t_cdlist **stack_a, t_cdlist **stack_b,
				t_cdlist *node_a);
static void	_movetotop(t_cdlist **stack_a, t_cdlist **stack_b, t_cdlist *node);
static void	_terminate(t_cdlist **stack_b, int order);

/**
 * @brief Sorts, in the `stack_b`, a run of numbers from `stack_a` using the
 * insertion sort algorithm.
 *
 * @param stack_a The stack to sort.
 * @param stack_b The stack to store the sorted numbers.
 * @param run The run number to sort.
 * @param order The order in which the numbers will be sorted.
 *
 * @details This algorithm stores each number directly in the correct position
 * in the `stack_b`. This is achieved by moving the entire stack to the correct
 * position in the `stack_b` before pushing the number. This is done by rotating
 * the `stack_b` until the target position is at the top. If the number to push
 * is the biggest or the lowest, the `stack_b` is rotated until the biggest
 * number is at the top.
 *
 * @warning This function does not sort the numbers in `stack_a`, it only moves
 * them to `stack_b` in the correct order.
 *
 * @note This function is part of the insertion sort algorithm.
 */
void	ps_insertionsort(t_cdlist **stack_a, t_cdlist **stack_b,
			size_t run, int order)
{
	t_cdlist	*cheapest;

	while (ps_runsize(stack_a, run))
	{
		if (ps_checkskips(stack_a))
			continue ;
		cheapest = ps_getcheapest(stack_a, stack_b, run, order);
		_movetotop_both(stack_a, stack_b, cheapest);
		_movetotop(stack_a, stack_b, cheapest);
		pb(stack_a, stack_b);
	}
	_terminate(stack_b, order);
}
/**
 * @brief Moves both `stack_a` and `stack_b` up to the point where `node_a` is
 * at the top of `stack_a` and `stack_b`'s head is `node_a`'s target.
 */
static void	_movetotop_both(t_cdlist **stack_a, t_cdlist **stack_b,
				t_cdlist *node_a)
{
	if (!*stack_b || !ps_data(node_a)->target)
		return ;
	if (ps_istophalf(node_a, (size_t)ft_cdlstsize(*stack_a)) &&
		ps_istophalf(ps_data(node_a)->target, (size_t)ft_cdlstsize(*stack_b)) &&
		(*stack_a != node_a && *stack_b != ps_data(node_a)->target))
		while (*stack_a != node_a || *stack_b != ps_data(node_a)->target)
			rr(stack_a, stack_b);
	else if (!ps_istophalf(node_a, (size_t)ft_cdlstsize(*stack_a)) &&
		!ps_istophalf(ps_data(node_a)->target, (size_t)ft_cdlstsize(*stack_b))
		&& (*stack_a != node_a && *stack_b != ps_data(node_a)->target))
		while (*stack_a != node_a || *stack_b != ps_data(node_a)->target)
			rrr(stack_a, stack_b);
}

static void	_movetotop(t_cdlist **stack_a, t_cdlist **stack_b, t_cdlist *node_a)
{
	if (!*stack_b || !ps_data(node_a)->target)
		return ;
	while (ps_istophalf(node_a, (size_t)ft_cdlstsize(*stack_a)) &&
		*stack_a != node_a)
		ra(stack_a);
	while (!ps_istophalf(node_a, (size_t)ft_cdlstsize(*stack_a)) &&
		*stack_a != node_a)
		rra(stack_a);
	while (ps_istophalf(ps_data(node_a)->target, (size_t)ft_cdlstsize(*stack_b))
		&& *stack_b != ps_data(node_a)->target)
		rb(stack_b);
	while (!ps_istophalf(ps_data(node_a)->target, (size_t)ft_cdlstsize(*stack_b))
		&& *stack_b != ps_data(node_a)->target)
		rrb(stack_b);
}

static void	_terminate(t_cdlist **stack_b, int order)
{
	t_cdlist	*stack_head;

	stack_head = *stack_b;
	if (order == ORDER_ASCENDING)
		while (!(ps_data(stack_head->previous)->num > ps_data(stack_head)->num
			&& ps_data(stack_head->next)->num > ps_data(stack_head)->num))
			stack_head = stack_head->next;
	else
		while (!(ps_data(stack_head->previous)->num < ps_data(stack_head)->num
			&& ps_data(stack_head->next)->num < ps_data(stack_head)->num))
			stack_head = stack_head->next;
	if (ps_data(stack_head)->index <= (size_t)ft_cdlstsize(*stack_b) / 2)
		while (*stack_b != stack_head)
			rb(stack_b);
	else
		while (*stack_b != stack_head)
			rrb(stack_b);
}
