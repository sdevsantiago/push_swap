/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_isoRDER.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 19:09:16 by sede-san          #+#    #+#             */
/*   Updated: 2025/02/21 19:29:27 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/push_swap.h"

int	ps_issorted(t_cdlist **stack)
{
    int         order;
	t_cdlist    *current;

    current = *stack;
    order = ORDER_ASCENDING;
    while (current)
    {
        if (ps_data(current)->num > ps_data(current->next)->num)
        {
            if (order == ORDER_ASCENDING)
                order = ORDER_DESCENDING;
            else if (order == ORDER_DESCENDING)
                return (ORDER_MIXED);
        }
        else
            if (order == ORDER_DESCENDING)
                return (ORDER_MIXED);
        current = current->next;
		if (current == *stack)
			break ;
    }
    return (ORDER_ASCENDING);
}
