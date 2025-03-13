/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 13:23:37 by sede-san          #+#    #+#             */
/*   Updated: 2025/03/12 21:48:47 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"
#include "../../lib/Libft/libft.h"
#include "../../lib/ft_printf/ft_printf.h"

void	push_swap(t_cdlist **stack_a, t_cdlist **stack_b);

int	main(int argc, char const *argv[])
{
	t_cdlist	*stack_a;
	t_cdlist	*stack_b;

	if (argc < 2)
		return (ft_printf(ERROR_MESSAGE), EXIT_FAILURE);
	stack_a = ps_fillstack(argv);
	if (!stack_a)
		return (ft_printf(ERROR_MESSAGE), EXIT_FAILURE);
	if (ps_issorted(&stack_a) == ORDER_ASCENDING)
		return (ft_cdlstclear(&stack_a, free), EXIT_SUCCESS);
	stack_b = NULL;
	push_swap(&stack_a, &stack_b);
	ft_cdlstclear(&stack_a, free);
	ft_cdlstclear(&stack_b, free);
	return (EXIT_SUCCESS);
}

/**
 * @brief Sorts a stack of numbers in ascending order.
 * @attention Numbers must be unique.
 */
void	push_swap(t_cdlist **stack_a, t_cdlist **stack_b)
{
	size_t	size_a;

	size_a = ps_data(ft_cdlstlast(*stack_a))->index + 1;
	if (size_a == 2)
		ps_twosort(stack_a);
	else if (size_a == 3)
		ps_threesort(stack_a);
	else if (size_a == 4)
		ps_foursort(stack_a, stack_b);
	else if (size_a == 5)
		ps_fivesort(stack_a, stack_b);
	else
		ps_timsort(stack_a, stack_b);
}
