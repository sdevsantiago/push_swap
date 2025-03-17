/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_runsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 14:38:24 by sede-san          #+#    #+#             */
/*   Updated: 2025/03/14 14:54:48 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/push_swap.h"

size_t	ps_runsize(t_cdlist **stack, size_t run)
{
	size_t		size;
	t_cdlist	*current;

	size = 0;
	current = *stack;
	while (current)
	{
		if (ps_data(current)->run == run)
			size++;
		current = current->next;
		if (current == *stack)
			break ;
	}
	return (size);
}
