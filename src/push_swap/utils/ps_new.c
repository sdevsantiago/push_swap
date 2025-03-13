/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_new.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 01:26:02 by sede-san          #+#    #+#             */
/*   Updated: 2025/03/12 21:25:26 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/push_swap.h"

t_push_swap	*ps_new(int num, size_t index)
{
	t_push_swap	*new_node;

	new_node = (t_push_swap *)ft_calloc(1, sizeof(t_push_swap));
	if (!new_node)
		return (NULL);
	new_node->num = num;
	new_node->index = index;
	return (new_node);
}
