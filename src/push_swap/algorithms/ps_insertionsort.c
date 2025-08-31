/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_insertionsort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 19:23:05 by sede-san          #+#    #+#             */
/*   Updated: 2025/08/30 19:23:18 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		movetotop_both(t_cdlist **stack_a, t_cdlist **stack_b,
					t_cdlist *node_a);
static void		movetotop(t_cdlist **stack_a, t_cdlist **stack_b,
					t_cdlist *node);
static void		terminate(t_cdlist **stack_b, int order);
static t_cdlist	*findhead(t_cdlist **stack_b, int order);

void	ps_insertionsort(
	t_cdlist **stack_a,
	t_cdlist **stack_b,
	size_t run,
	int order)
{
	t_cdlist	*cheapest;

	while (ps_runsize(stack_a, run))
	{
		cheapest = get_cheapest(stack_a, stack_b, run, order);
		movetotop_both(stack_a, stack_b, cheapest);
		movetotop(stack_a, stack_b, cheapest);
		pb(stack_a, stack_b, 1);
	}
	terminate(stack_b, order);
}

static void	movetotop_both(t_cdlist **stack_a, t_cdlist **stack_b,
				t_cdlist *node_a)
{
	if (!*stack_b || !ps_data(node_a)->target)
		return ;
	if (*stack_a == node_a || *stack_b == ps_data(node_a)->target)
		return ;
	if (ps_istophalf(node_a, stack_a)
		&& ps_istophalf(ps_data(node_a)->target, stack_b))
		while (*stack_a != node_a && *stack_b != ps_data(node_a)->target)
			rr(stack_a, stack_b, 1);
	else if (!ps_istophalf(node_a, stack_a)
		&& !ps_istophalf(ps_data(node_a)->target, stack_b))
		while (*stack_a != node_a && *stack_b != ps_data(node_a)->target)
			rrr(stack_a, stack_b, 1);
}

static void	movetotop(t_cdlist **stack_a, t_cdlist **stack_b, t_cdlist *node_a)
{
	if ((!*stack_b || !ps_data(node_a)->target)
		&& ps_data(*stack_a)->run != SORTED_RUN)
		return ;
	while (*stack_a != node_a && ps_istophalf(node_a, stack_a))
	{
		if ((*stack_a)->next == node_a)
			sa(stack_a, 1);
		else
			ra(stack_a, 1);
	}
	while (*stack_a != node_a && !ps_istophalf(node_a, stack_a))
		rra(stack_a, 1);
	if (!ps_data(node_a)->target)
		return ;
	while (*stack_b != ps_data(node_a)->target
		&& ps_istophalf(ps_data(node_a)->target, stack_b))
		rb(stack_b, 1);
	while (*stack_b != ps_data(node_a)->target
		&& !ps_istophalf(ps_data(node_a)->target, stack_b))
		rrb(stack_b, 1);
}

static void	terminate(t_cdlist **stack_b, int order)
{
	t_cdlist	*stack_head;

	stack_head = findhead(stack_b, order);
	if (ps_istophalf(stack_head, stack_b))
		while (*stack_b != stack_head)
			rb(stack_b, 1);
	else
		while (*stack_b != stack_head)
			rrb(stack_b, 1);
}

static t_cdlist	*findhead(t_cdlist **stack_b, int order)
{
	t_cdlist	*stack_head;

	stack_head = *stack_b;
	if (order == ORDER_ASCENDING)
	{
		while (!(ps_data(stack_head->previous)->num > ps_data(stack_head)->num
				&& ps_data(stack_head->next)->num > ps_data(stack_head)->num))
		{
			stack_head = stack_head->next;
			if (*stack_b == stack_head)
				break ;
		}
	}
	else
	{
		while (!(ps_data(stack_head->previous)->num < ps_data(stack_head)->num
				&& ps_data(stack_head->next)->num < ps_data(stack_head)->num))
		{
			stack_head = stack_head->next;
			if (*stack_b == stack_head)
				break ;
		}
	}
	return (stack_head);
}
