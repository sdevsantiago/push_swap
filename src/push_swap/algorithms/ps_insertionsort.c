/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_insertionsort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 19:23:05 by sede-san          #+#    #+#             */
/*   Updated: 2025/03/13 15:15:38 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/push_swap.h"

static int		_checkskip(t_cdlist **stack_a);
static t_cdlist	*_getcheapest(t_cdlist **stack_a, t_cdlist **stack_b,
		size_t run);

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
	//! Temporary code
	t_cdlist	*biggest;
	t_cdlist	*lowest;

	// pb(stack_a, stack_b);

	// //? Check if the run only has one number, in which case it is already sorted
	// if (ps_data(*stack_a)->run != run &&
	// 	ps_data(ft_cdlstlast(*stack_a))->run != run)
	// 	return ;

	// pb(stack_a, stack_b);
	while (1)
	{
		if (_checkskip(stack_a))
			continue ;
		else if (ps_data(ft_cdlstlast(*stack_a))->num <
			ps_data(ft_cdlstlast(*stack_a)->previous)->num &&
			ps_data(ft_cdlstlast(*stack_a))->num >
			ps_data(ft_cdlstlast(*stack_a)->previous->previous)->num)
		{
			rra(stack_a);
			rra(stack_a);
			sa(stack_a);
			ra(stack_a);
			ra(stack_a);
		}

		//* If this wasn't possible, we get the cheapest node to move
		// _getcheapest(stack_a, stack_b, run);

		//! Temporary code
		if (!*stack_b && ps_data(*stack_a)->run != SORTED_RUN)
		{
			biggest = *stack_a;
			pb(stack_a, stack_b);
			continue ;
		}
		else if (*stack_a && *stack_b && (*stack_b)->next == *stack_b &&
			ps_data(*stack_a)->run != SORTED_RUN)
		{
			if (ps_data(*stack_a)->num > ps_data(biggest)->num)
			{
				biggest = *stack_a;
				lowest = *stack_b;
			}
			else
				lowest = *stack_a;
			pb(stack_a, stack_b);
			continue ;
		}
		if (ps_data(*stack_a)->num == SORTED_RUN)
			rra(stack_a);
		if (ps_data(*stack_a)->num > ps_data(biggest)->num ||
			ps_data(*stack_a)->num < ps_data(lowest)->num)
		{
			if (order == ORDER_ASCENDING)
			{
				// here we can determine, based on the index (upper or lower
				// half), whether it's better to rb or rrb
				while (*stack_b != lowest)
					rb(stack_b);
				if (ps_data(*stack_a)->num > ps_data(biggest)->num)
					biggest = *stack_a;
				else
					lowest = *stack_a;
			}
			else if (order == ORDER_DESCENDING)
			{
				// here we can determine, based on the index (upper or lower
				// half), whether it's better to rb or rrb
				while (*stack_b != biggest)
					rb(stack_b);
				if (ps_data(*stack_a)->num > ps_data(biggest)->num)
					biggest = *stack_a;
				else
					lowest = *stack_a;
			}
		}
		else
		{
			if (order == ORDER_ASCENDING)
			{
				while (!(ps_data(*stack_b)->num > ps_data(*stack_a)->num &&
					ps_data(ft_cdlstlast(*stack_b))->num <
					ps_data(*stack_a)->num))
					rb(stack_b);
			}
			else if (order == ORDER_DESCENDING)
			{
				while (!(ps_data(*stack_b)->num < ps_data(*stack_a)->num &&
					ps_data(ft_cdlstlast(*stack_b))->num >
					ps_data(*stack_a)->num))
					rb(stack_b);
			}
		}
		pb(stack_a, stack_b);
		ps_data(*stack_b)->run = SORTED_RUN;
		if (!*stack_a || (ps_data(*stack_a)->run != run &&
			ps_data(ft_cdlstlast(*stack_a))->run != run))
			break ;
	}
	if (order == ORDER_ASCENDING)
	{
		if (ps_data(lowest)->index <= ft_cdlstsize(*stack_b)/2)
			while (*stack_b != lowest)
				rb(stack_b);
		else
			while (*stack_b != lowest)
				rrb(stack_b);
	}
	else if (order == ORDER_DESCENDING)
	{
		if (ps_data(biggest)->index <= ft_cdlstsize(*stack_b)/2)
			while (*stack_b != biggest)
				rb(stack_b);
		else
			while (*stack_b != biggest)
				rrb(stack_b);
	}
}

/**
 * @brief Checks if the number to sort in `stack_b` can be placed directly in
 * the sorted run, in which case it moves moves it.
 *
 * @param stack_a
 *
 * @return Returns `1` if the number has been sorted in the sorted run, else
 * returns `0`.
 *
 * @details This function first checks if the sorted run is either in the first
 * or the last position of the stack. If the sorted run is at the head of the
 * stack, the skip can be done by inserting a number lower than the first one of
 * the sorted run. On the other hand, if the sorted run is at the bottom of the
 * stack, the skip can be done by inserting a number higher than the last one of
 * the sorted run. If one of these cases can be achieved, the movement is done
 * and the skip is resolved, in which case 1 is returned.
 *
 * @note This is only valid if we don't have the run to sort in both the top and
 * the bottom of the stack.
 */
static int	_checkskip(t_cdlist **stack_a)
{
	if (ps_data(*stack_a)->run != SORTED_RUN &&
		ps_data(ft_cdlstlast(*stack_a))->run == SORTED_RUN &&
		ps_data(*stack_a)->num > ps_data(ft_cdlstlast(*stack_a))->num)
	{
		ps_data(*stack_a)->run = SORTED_RUN;
		ra(stack_a);
		return (1);
	}
	else if (ps_data(*stack_a)->run == SORTED_RUN &&
		ps_data(ft_cdlstlast(*stack_a))->run != SORTED_RUN &&
		ps_data(ft_cdlstlast(*stack_a))->num < ps_data(*stack_a)->num)
	{
		ps_data(ft_cdlstlast(*stack_a))->run = SORTED_RUN;
		rra(stack_a);
		return (1);
	}
	return (0);
}

/**
 * @brief
 * @return Returns the cheapest, movement wise, node to move
 */
// static t_cdlist	*_getcheapest(t_cdlist **stack_a, t_cdlist **stack_b,
// 	size_t run)
// {
// 	int			cost;
// 	t_cdlist	*cheapest;

// 	if (!stack_b || !*stack_b || (*stack_b)->next == *stack_b)
// 		return (*stack_a);
// 	cheapest = *stack_a;

// }

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
