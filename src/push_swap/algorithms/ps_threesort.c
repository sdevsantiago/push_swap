/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_threesort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 13:33:14 by sede-san          #+#    #+#             */
/*   Updated: 2025/02/24 01:19:38 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/push_swap.h"

static t_cdlist	*_getbiggest(t_cdlist *stack_a);

/**
 * @brief Sorts a three number stack following push_swap instructions.
 * @param stack_a The stack where numbers are stored originally
 * @details This algorithm performs a movement, needing an extra if it is not
 * yet sorted. The movements are the following:
 * 1 2 3 -> sorted
 * 1 3 2 -> rra -> 2 1 3 -> sa -> sorted
 * 2 1 3 -> sa -> sorted
 * 2 3 1 -> rra -> sorted
 * 3 1 2 -> ra -> sorted
 * 3 2 1 -> ra -> 2 1 3 -> sa -> sorted
 * This algorithm ensures 0 movements if the stack is already sorted, 1 movement
 * in 3/6 cases and 2 movements in the rest of the cases.
 */
void	ps_threesort(t_cdlist *stack_a)
{
	size_t	i_big;

	if (ps_issorted(&stack_a))
		return ;
	i_big = ps_data(_getbiggest(stack_a))->index;
	if (i_big == 0)
		ra(stack_a);
	else if (i_big == 1)
		rra(stack_a);
	else
		return (sa(stack_a));
	if (!ps_issorted(&stack_a))
		sa(stack_a);
}

/**
 * @brief Finds the node that contains the biggest number.
 * @param stack_a The stack where the numbers are stored originally.
 * @return Returns a pointer to the node containing the biggest
 * value in `stack_a`.
 */
static t_cdlist	*_getbiggest(t_cdlist *stack_a)
{
	t_cdlist	*current;
	t_cdlist	*biggest;

	if (!stack_a)
		return (NULL);
	current = stack_a;
	biggest = current;
	while (current)
	{
		if (ps_data(current)->num > ps_data(biggest)->num)
			biggest = current;
		current = current->next;
		if (current == stack_a)
			break ;
	}
	return (biggest);
}
