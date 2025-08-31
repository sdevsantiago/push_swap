/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_istophalf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 19:43:41 by sede-san          #+#    #+#             */
/*   Updated: 2025/08/30 19:59:54 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Determines if a node is in the top half of the stack.
 *
 * @param node Pointer to the node to check.
 * @param stack Pointer to the stack containing the node.
 *
 * @return 1 if node is in top half, 0 if in bottom half.
 *
 * @details
 * Used to optimize rotation direction:
 * - Top half: use rotate (ra, rb)
 * - Bottom half: use reverse rotate (rra, rrb)
 * This minimizes the number of operations needed to bring an element to the top.
 */
inline int	ps_istophalf(
	t_cdlist *node,
	t_cdlist **stack)
{
	return (ps_data(node)->index <= ps_stacksize(stack) / 2);
}
