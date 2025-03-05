/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_foursort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 13:55:36 by sede-san          #+#    #+#             */
/*   Updated: 2025/03/05 20:14:03 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/push_swap.h"

static void		_updateindexes(t_cdlist **stack);
static t_cdlist	*_getlowest(t_cdlist **stack_a);

/**
 * @brief Sorts a four number stack following push_swap instructions
 * @param stack_a The stack where numbers are stored originally
 * @param stack_b The auxiliary stack
 * @details This algorithm moves the smallest number to the first position and
 * if it is not yet sorted, moves it to `stack_b`, sorts the rest of the numbers
 * using `ps_threesort` and moves the previously pushed number to `stack_a`
 * @see ps_threesort.c
 * @todo This algorithm can be improved, not priority
 */
void	ps_foursort(t_cdlist **stack_a, t_cdlist **stack_b)
{
	size_t	i_low;

	if (!stack_a || !*stack_a)
		return ;
	i_low = ps_data(_getlowest(stack_a))->index;
	if (i_low == 1)
		sa(stack_a);
	else if (i_low == 2)
	{
		rra(stack_a);
		rra(stack_a);
	}
	else if (i_low == 3)
		rra(stack_a);
	if (ps_issorted(stack_a) == ORDER_ASCENDING)
		return ;
	pb(stack_a, stack_b);
	_updateindexes(stack_a);
	ps_threesort(stack_a);
	pa(stack_b, stack_a);
}

/**
 * @brief Finds the node that contains the lowest number.
 * @param stack_a The stack where the numbers are stored originally.
 * @return Returns a pointer to the node containing the lowest.
 * value in `stack_a`.
 */
static t_cdlist	*_getlowest(t_cdlist **stack_a)
{
	t_cdlist	*current;
	t_cdlist	*lowest;

	if (!stack_a || !*stack_a)
		return (NULL);
	current = *stack_a;
	lowest = current;
	while (current)
	{
		if (ps_data(current)->num < ps_data(lowest)->num)
			lowest = current;
		current = current->next;
		if (current == *stack_a)
			break ;
	}
	return (lowest);
}

/**
 * @brief Updates the indexes of `stack`.
 * @param stack The stack to update
 */
static void	_updateindexes(t_cdlist	**stack)
{
	t_cdlist	*current;
	size_t		i;

	current = *stack;
	i = 0;
	while (current)
	{
		ps_data(current)->index = i++;
		current = current->next;
		if (current == *stack)
			break ;
	}
}
