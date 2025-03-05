/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_timsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 19:02:45 by sede-san          #+#    #+#             */
/*   Updated: 2025/02/25 15:40:44 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/push_swap.h"

void	ps_timsort(t_cdlist **stack_a, t_cdlist **stack_b, size_t size)
{
	if (size)
		ps_insertionsort(stack_a, stack_b, ORDER_DESCENDING);						// Done once only

	ps_insertionsort(stack_a, stack_b, ORDER_ASCENDING);
}
