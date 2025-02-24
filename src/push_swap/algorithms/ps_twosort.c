/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_twosort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 13:30:16 by sede-san          #+#    #+#             */
/*   Updated: 2025/02/21 13:53:53 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../../include/push_swap.h"

/**
 * @brief Sorts a two number stack following push_swap instructions.
 * @param stack_a The stack where the numbers are stored originally.
 * @details Compares both numbers, if the first one is bigger than the second,
 * swaps them.
 */
void	ps_twosort(t_cdlist *stack_a)
{
	if (ps_data(stack_a)->num > ps_data(stack_a->next)->num)
		sa(stack_a);
}