/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 12:19:00 by sede-san          #+#    #+#             */
/*   Updated: 2025/04/08 14:33:31 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"
#include "../../lib/ft_printf/ft_printf.h"
#include "../../lib/get_next_line/get_next_line.h"

#ifdef SILENT
# undef SILENT
#endif
/**
 * @brief Defines whether or not operations should print a message when
 * performed.
 *
 * @note This macro overrides the value in push_swap.h
 */
#define SILENT 1

int	checker(t_cdlist **stack_a, t_cdlist **stack_b);

int	main(int argc, char const *argv[])
{
	t_cdlist	*stack_a;
	t_cdlist	*stack_b;

	if (argc < 2)
		return (ft_printf(ERROR_MESSAGE), EXIT_FAILURE);
	stack_a = ps_fillstack(argv);
	if (!stack_a)
		return (ft_printf(ERROR_MESSAGE), EXIT_FAILURE);
	stack_b = NULL;
	if (checker(&stack_a, &stack_b))
		return (ft_cdlstclear(&stack_a, free), ft_printf("OK\n"), EXIT_SUCCESS);
	else
		return (ft_cdlstclear(&stack_a, free), ft_printf("KO\n"), EXIT_FAILURE);
}

int	checker(t_cdlist **stack_a, t_cdlist **stack_b)
{
	char		*operation;

	operation = get_next_line(STDIN_FILENO);
	while (operation)
	{
		if (ft_strncmp(operation, "pa\n", ft_strlen("pa\n")))
			pa(stack_b, stack_a);
		else if (ft_strncmp(operation, "pb\n", ft_strlen("pb\n")))
			pb(stack_a, stack_b);
		else if (ft_strncmp(operation, "rra\n", ft_strlen("rra\n")))
			rra(stack_a);
		else if (ft_strncmp(operation, "rrb\n", ft_strlen("rrb\n")))
			rrb(stack_b);
		else if (ft_strncmp(operation, "rrr\n", ft_strlen("rrr\n")))
			rrr(stack_a, stack_b);
		else if (ft_strncmp(operation, "ra\n", ft_strlen("ra\n")))
			ra(stack_a);
		else if (ft_strncmp(operation, "rb\n", ft_strlen("rb\n")))
			rb(stack_b);
		else if (ft_strncmp(operation, "rr\n", ft_strlen("rr\n")))
			rr(stack_a, stack_b);
		else if (ft_strncmp(operation, "sa\n", ft_strlen("sa\n")))
			sa(stack_a);
		else if (ft_strncmp(operation, "sb\n", ft_strlen("sb\n")))
			sb(stack_b);
		else if (ft_strncmp(operation, "ss\n", ft_strlen("ss\n")))
			ss(stack_a ,stack_b);
		else
			return (free(operation), EXIT_FAILURE);
		free(operation);
		operation = get_next_line(STDOUT_FILENO);
	}
	if (ps_issorted(stack_a) && !*stack_b)
		return (EXIT_SUCCESS);
	else
		return (EXIT_FAILURE);
}
