/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 18:03:05 by sede-san          #+#    #+#             */
/*   Updated: 2025/03/12 21:41:16 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/push_swap.h"
#include "../../../lib/ft_printf/ft_printf.h"


/**
 * @brief Pushes the top element from source stack to destination stack.
 * @param stack_src The source stack
 * @param stack_dest The destination stack
 */
static void	_push(t_cdlist **stack_src, t_cdlist **stack_dest)
{
	t_cdlist	*first_node_src;
	t_cdlist	*second_node_src;
	t_cdlist	*last_node_src;

	if (!stack_src || !*stack_src)
		return ;
	first_node_src = *stack_src;
	second_node_src = first_node_src->next;
	if (second_node_src == first_node_src)
		*stack_src = NULL;
	else
	{
		last_node_src = ft_cdlstlast(*stack_src);
		second_node_src->previous = last_node_src;
		last_node_src->next = second_node_src;
		*stack_src = second_node_src;
	}
    ft_cdlstadd_front(stack_dest, first_node_src);
}

/**
 * @brief Pushes the top element from stack_b to stack_a.
 * @param stack_a The destination stack.
 * @param stack_b The source stack.
 */
void	pa(t_cdlist **stack_b, t_cdlist **stack_a)
{
    _push(stack_b, stack_a);
	ps_updateindexes(stack_a, stack_b);
    ft_printf("pa\n");
}

/**
 * @brief Pushes the top element from stack_a to stack_b.
 * @param stack_a The source stack.
 * @param stack_b The destination stack.
 */
void	pb(t_cdlist **stack_a, t_cdlist **stack_b)
{
    _push(stack_a, stack_b);
	ps_updateindexes(stack_a, stack_b);
    ft_printf("pb\n");
}
