/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_insertionsort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 19:23:05 by sede-san          #+#    #+#             */
/*   Updated: 2025/03/26 08:54:16 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/push_swap.h"
#include "../../../lib/ft_printf/ft_printf.h"

static void	_movetotop(t_cdlist **stack_a, t_cdlist **stack_b, t_cdlist *node);
static void	_terminate(t_cdlist **stack_b, int order);

static void _stackdump(t_cdlist **stack, char stack_letter)
{
	t_cdlist	*current;

	ft_printf("stack_%c:", stack_letter);
	if (!*stack)
	{
		ft_printf("\n");
		return ;
	}
	current = *stack;
	while (current)
	{
		ft_printf(" %d", ps_data(current)->num);
		current = current->next;
		if (current == *stack)
			break ;
	}
	ft_printf("\n");
}

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
 *
 * @todo Develop a function to optimize movements based on the index of the
 * number in `stack_a` and the target index in `stack_b`.
 * @todo If the number to push is bigger or lower than the biggest or lowest in
 * the stack_a, place that number directly in the stack_a.
 *
 * @todo Figure a way to also sort the numbers in ascending order. -> Mark as
 * head of the stack the biggest or the lowest number, depending on the order.
 */
void	ps_insertionsort(t_cdlist **stack_a, t_cdlist **stack_b,
			size_t run, int order)
{
	// t_cdlist	*biggest;
	// t_cdlist	*lowest;
	t_cdlist	*cheapest;

	_stackdump(stack_a, 'a');
	_stackdump(stack_b, 'b');
	while (ps_runsize(stack_a, run))
	{
		if (ps_checkskips(stack_a))
			continue ;
		cheapest = ps_getcheapest(stack_a, stack_b, run, order);
		ft_printf("Cheapest is %d\n", ps_data(cheapest)->num);
		_movetotop(stack_a, stack_b, cheapest);
		pb(stack_a, stack_b);
		ps_data(*stack_b)->run = SORTED_RUN;
	}
	_terminate(stack_b, order);
	_stackdump(stack_a, 'a');
	_stackdump(stack_b, 'b');
}

/**
 * @brief Moves both `stack_a` and `stack_b` up to the point where `node_a` is
 * at the top of `stack_a` and `stack_b`'s head is `node_a`'s target.
 */
static void	_movetotop(t_cdlist **stack_a, t_cdlist **stack_b, t_cdlist *node_a)
{
	if (!*stack_b || !ps_data(node_a)->target)
		return ;
	if (ps_istophalf(node_a, (size_t)ft_cdlstsize(*stack_a)) &&
		ps_istophalf(ps_data(node_a)->target, (size_t)ft_cdlstsize(*stack_b)))
		while (*stack_a != node_a && *stack_b  != ps_data(node_a)->target)
			rr(stack_a, stack_b);
	else if (!ps_istophalf(node_a, (size_t)ft_cdlstsize(*stack_a)) &&
		!ps_istophalf(ps_data(node_a)->target, (size_t)ft_cdlstsize(*stack_b)))
		while (*stack_a != node_a && *stack_b  != ps_data(node_a)->target)
			rrr(stack_a, stack_b);
	while (ps_istophalf(node_a, (size_t)ft_cdlstsize(*stack_a)) &&
		*stack_a != node_a)
			ra(stack_a);
	while (!ps_istophalf(node_a, (size_t)ft_cdlstsize(*stack_a)) &&
		*stack_a != node_a)
			rra(stack_a);
	while (ps_istophalf(ps_data(node_a)->target, (size_t)ft_cdlstsize(*stack_b))
		&& *stack_b != ps_data(node_a)->target)
			rb(stack_a);
	while (!ps_istophalf(ps_data(node_a)->target, (size_t)ft_cdlstsize(*stack_b))
		&& *stack_b != ps_data(node_a)->target)
			rrb(stack_a);
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

/*
void	ps_insertionsort(tcdlist **stack_a, tcdlist **stack_b, size_t run)
{
	TODO Figure a way to also sort the numbers in ascending order
	t_cdlist	*biggest;
	t_cdlist	*lowest;

	pb(stack_a, stack_b);
	if (ps_data(*stack_a)->run != run)
		return ;
	pb(stack_a, stack_b);
	if (ps_data(*stack_b)->num > ps_data((*stack_b)->next)->num)
		biggest = *stack_b;
	else
		biggest = (*stack_b)->next;
	if (ps_data(*stack_b)->num < ps_data((*stack_b)->next)->num)
		lowest = *stack_b;
	else
		lowest = (*stack_b)->next;
	while (*stack_a && ps_data(*stack_a)->run == run)
	{

		TODO Analise which number is cheaper to move based on it's index in
		TODO the stack_a and it's target index in the stack_b, maybe store it's
		TODO cost in the structure

		//? prepare stack_b
		if (ps_data(*stack_a)->num > ps_data(biggest)->num ||
			ps_data(*stack_a)->num < ps_data(lowest)->num)
		{
			while (*stack_b != biggest)
				rb(stack_b);
			if (ps_data(*stack_a)->num > ps_data(biggest)->num)
				biggest = *stack_a;
			else
				lowest = *stack_a;
		}
		else
		{
			// TODO Make function of this
			t_cdlist	*target_next;	//? This node must be at the top,
										//? it will be the inmediate one
										//? after we push from stack_a

			target_next = *stack_b;
			while (!(ps_data(target_next)->num < ps_data(*stack_a)->num &&
				ps_data(target_next->previous)->num > ps_data(*stack_a)->num))
				target_next = target_next->next;
			while (*stack_b != target_next)
				rb(stack_b);
		}
		//? move to stack_b in order
		pb(stack_a, stack_b);
	}
}
*/
