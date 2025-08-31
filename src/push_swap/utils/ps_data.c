/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_data.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 19:29:54 by sede-san          #+#    #+#             */
/*   Updated: 2025/08/30 19:58:46 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Extracts push_swap data from a list node.
 *
 * @param node Pointer to a circular doubly linked list node.
 *
 * @return Pointer to the t_push_swap structure stored in the node's content.
 *
 * @details
 * Inline function for quick access to node data. The compiler is suggested to
 * replace function calls with the actual code to avoid function call overhead
 * in performance-critical sections.
 *
 * @warning No null checks performed - assumes valid node pointer.
 */
inline t_push_swap	*ps_data(
	t_cdlist *node)
{
	return ((t_push_swap *)(node->content));
}
