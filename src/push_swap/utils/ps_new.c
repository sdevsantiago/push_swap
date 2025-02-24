/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_new.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 01:26:02 by sede-san          #+#    #+#             */
/*   Updated: 2025/02/24 01:27:16 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/push_swap.h"

t_push_swap	*ps_new(int num, size_t index)
{
	t_push_swap	*new_node;

	new_node = (t_push_swap *)malloc(sizeof(t_push_swap));
	if (!new_node)
		return (NULL);
	new_node->num = num;
	new_node->index = index;
	new_node->run = 0;	//? Updated only in ps_timsort
	new_node->index_run = 0;
	new_node->moves_a = 0;
	new_node->moves_b = 0;
	return (new_node);
}