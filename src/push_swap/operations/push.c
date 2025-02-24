/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 18:03:05 by sede-san          #+#    #+#             */
/*   Updated: 2025/02/24 01:24:52 by sede-san         ###   ########.fr       */
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
	t_cdlist	*move;

	if (!stack_src || !*stack_src)
		return ;
	move = *stack_src;
	if ((*stack_src)->next == move)
		*stack_src = NULL;
	else
	{
		(*stack_src)->next->previous = ft_cdlstlast(*stack_src);
		ft_cdlstlast(*stack_src)->next = move->next;
		*stack_src = (*stack_src)->next;
	}
    ft_cdlstadd_front(stack_dest, move);
}

/**
 * @brief Pushes the top element from stack_b to stack_a.
 * @param stack_a The destination stack.
 * @param stack_b The source stack.
 */
void	pa(t_cdlist *stack_b, t_cdlist *stack_a)
{
    _push(&stack_b, &stack_a);
    ft_printf("pa\n");
}

/**
 * @brief Pushes the top element from stack_a to stack_b.
 * @param stack_a The source stack.
 * @param stack_b The destination stack.
 */
void	pb(t_cdlist *stack_a, t_cdlist *stack_b)
{
    _push(&stack_a, &stack_b);
    ft_printf("pb\n");
}
