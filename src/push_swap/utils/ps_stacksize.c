/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stacksize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 19:42:40 by sede-san          #+#    #+#             */
/*   Updated: 2025/08/30 20:00:40 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Gets the total size of a stack.
 *
 * @param stack Pointer to the stack.
 *
 * @return Number of elements in the stack.
 *
 * @details
 * Uses the index of the last element + 1 to quickly determine stack size
 * without iteration. More efficient than counting nodes.
 */
inline size_t	ps_stacksize(
	t_cdlist **stack)
{
	return (ps_data(ft_cdlstlast(*stack))->index + 1);
}
