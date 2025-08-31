/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_new.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 01:26:02 by sede-san          #+#    #+#             */
/*   Updated: 2025/08/30 20:00:15 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Creates a new push_swap data structure.
 *
 * @param num The integer value to store.
 * @param index The position index in the stack (0-based).
 *
 * @return Pointer to the new t_push_swap structure, or NULL if allocation
 *         fails.
 *
 * @details
 * Allocates memory for a new t_push_swap structure and initializes:
 * - num: the integer value
 * - index: position in stack for quick reference
 * - target: initialized to NULL (used in sorting algorithms)
 * - run: initialized to 0 (used in timsort algorithm)
 */
t_push_swap	*ps_new(
	int num,
	size_t index)
{
	t_push_swap	*new_node;

	new_node = (t_push_swap *)ft_calloc(1, sizeof(t_push_swap));
	if (!new_node)
		return (NULL);
	new_node->num = num;
	new_node->index = index;
	return (new_node);
}
