/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_fivesort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 13:58:18 by sede-san          #+#    #+#             */
/*   Updated: 2025/03/06 02:15:58 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/push_swap.h"

static void		_updateindexes(t_cdlist **stack);
static t_cdlist	*_getlowest(t_cdlist **stack_a);

/**
 * @brief Sorts a five number stack following push_swap instructions.
 * @param stack_a The stack where the numbers are stored originally
 * @param stack_b The auxiliary stack
 * @details This algorithm moves the biggest number to the first position and
 * if it is not yet sorted, moves it to `stack_b`, sorts the rest of the numbers
 * using `ps_foursort` and moves the number back to `stack_a`.
 * @see ps_foursort.c
 * @todo This algorithm can be improved, not priority
 */
void	ps_fivesort(t_cdlist **stack_a, t_cdlist **stack_b)
{
	size_t	i_big;

	if (!stack_a || !*stack_a)
		return ;
	i_big = ps_data(_getlowest(stack_a))->index;
	if (i_big == 1)
		sa(stack_a);
	else if (i_big == 2)
	{
		ra(stack_a);
		ra(stack_a);
	}
	else if (i_big == 3)
	{
		rra(stack_a);
		rra(stack_a);
	}
	else if (i_big == 4)
		rra(stack_a);
	if (ps_issorted(stack_a) == ORDER_ASCENDING)
		return ;
	pb(stack_a, stack_b);
	_updateindexes(stack_a);
	ps_foursort(stack_a, stack_b);
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
