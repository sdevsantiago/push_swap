/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_findtargets.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 21:16:02 by sede-san          #+#    #+#             */
/*   Updated: 2025/03/27 20:27:20 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../include/push_swap.h"
#include "../../../../lib/ft_printf/ft_printf.h"

static void	_findtarget_des(t_cdlist *current_a, t_cdlist **stack_b,
	t_cdlist **biggest, t_cdlist **smallest);
// static void	_findtarget_asc(t_cdlist *current_a, t_cdlist **stack_b,
// 	t_cdlist **biggest, t_cdlist **smallest);

/**
 * @brief Finds the following/previous node in `stack_b` for the nodes in
 * `stack_a`.
 *
 * @note This function gives a value to the target data in `s_push_swap`.
 */
void	ps_findtargets(t_cdlist **stack_a, t_cdlist **stack_b, int order,
			size_t run)
{
	static t_cdlist	*biggest;
	static t_cdlist	*smallest;
	t_cdlist		*current_a;

	if (!*stack_b || ft_cdlstsize(*stack_b) == 1)
		return ;
	current_a = *stack_a;
	if (!biggest && !smallest)
		biggest = smallest = *stack_b;
	while (current_a)
	{
		if (ps_data(current_a)->run == run)
		{
			if (order == ORDER_DESCENDING)
				_findtarget_des(current_a, stack_b, &biggest, &smallest);
			// else
			// 	_findtarget_asc(current_a, stack_b, &biggest, &smallest);
		}
		ft_printf("Target for %d in stack_a is %d in stack_b\n", ps_data(current_a)->num, ps_data(ps_data(current_a)->target)->num);
		current_a = current_a->next;
		if (current_a == *stack_a)
			break ;
	}
}
/**
 * Comment
 */
static void	_findtarget_des(t_cdlist *current_a, t_cdlist **stack_b,
				t_cdlist **biggest, t_cdlist **smallest)
{
	if (ps_data(current_a)->num > ps_data(*biggest)->num)
	{
		ps_data(current_a)->target = *biggest;
		*biggest = current_a;
	}
	else if (ps_data(current_a)->num < ps_data(*smallest)->num)
	{
		ps_data(current_a)->target = *biggest;
		*smallest = current_a;
	}
	else
	{
		ps_data(current_a)->target = *stack_b;
		while (!(ps_data(ps_data(current_a)->target)->num <
			ps_data(ps_data(current_a)->target->previous)->num) &&
			ps_data(current_a)->num > ps_data(ps_data(current_a)->target)->num)
		{
			ps_data(current_a)->target = ps_data(current_a)->target->next;
			if (ps_data(current_a)->target == *stack_b)
				break ;
		}
	}
}

// static void	_findtarget_asc(t_cdlist *current_a, t_cdlist **stack_b,
// 				t_cdlist **biggest, t_cdlist **smallest)
// {
// 	if (ps_data(current_a)->num > ps_data(*biggest)->num)
// 	{
// 		ps_data(current_a)->target = *smallest;
// 		*biggest = current_a;
// 	}
// 	else if (ps_data(current_a)->num < ps_data(*smallest)->num)
// 	{
// 		ps_data(current_a)->target = *smallest;
// 		*smallest = current_a;
// 	}
// }
