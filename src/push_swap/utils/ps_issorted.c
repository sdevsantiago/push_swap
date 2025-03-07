/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_issorted.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 19:09:16 by sede-san          #+#    #+#             */
/*   Updated: 2025/03/07 13:21:12 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/push_swap.h"

int	ps_issorted(t_cdlist **stack)
{
	int			order;
	t_cdlist	*current;

	current = (*stack)->next;
	order = ORDER_ASCENDING;
	while (current)
	{
		if (ps_data(current->previous)->num > ps_data(current)->num)
		{
			if (order == ORDER_ASCENDING)
				order = ORDER_DESCENDING;
		}
		else
		{
			if (order == ORDER_DESCENDING)
				return (ORDER_MIXED);
		}
		current = current->next;
		if (current == *stack)
			break ;
	}
	return (order);
}
