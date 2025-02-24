/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 22:18:31 by sede-san          #+#    #+#             */
/*   Updated: 2025/02/05 22:22:56 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/push_swap.h"

t_push_swap	*ps_data(t_cdlist *stack)
{
	if (!stack)
		return (NULL);
	return ((t_push_swap *)(stack->content));
}