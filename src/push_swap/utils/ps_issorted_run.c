/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_issorted_run.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 19:09:16 by sede-san          #+#    #+#             */
/*   Updated: 2025/03/07 13:25:14 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/push_swap.h"

int	ps_issorted_run(t_cdlist **run_start, size_t run)
{
	int			order;
	t_cdlist	*current;

	current = (*run_start)->next;
	order = ORDER_ASCENDING;
	while (current && ps_data(current)->run == run)
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
		if (current == *run_start)
			break ;
	}
	return (order);
}
