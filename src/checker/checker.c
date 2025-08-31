/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 15:35:14 by sede-san          #+#    #+#             */
/*   Updated: 2025/08/31 01:57:31 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "get_next_line.h"

static int	checker(t_cdlist *stack_a, t_cdlist *stack_b);
static int	do_op(char const *operation, t_cdlist **stack_a,
				t_cdlist **stack_b);

int	main(
	int argc,
	char const *argv[])
{
	t_cdlist	*stack_a;
	t_cdlist	*stack_b;
	int			error;

	if (argc < 2)
		return (EXIT_FAILURE);
	stack_a = ps_fillstack(argv);
	if (!stack_a)
	{
		ft_eputendl(RED_TEXT"Detected illegal or duplicated values"RESET);
		return (EXIT_FAILURE);
	}
	stack_b = NULL;
	error = checker(stack_a, stack_b);
	ft_cdlstclear(&stack_a, free);
	ft_cdlstclear(&stack_b, free);
	if (error)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static int	checker(t_cdlist *stack_a, t_cdlist *stack_b)
{
	char		*operation;
	int			error;

	error = 0;
	operation = get_next_line(STDIN_FILENO);
	while (operation != NULL && !error)
	{
		error = do_op(operation, &stack_a, &stack_b);
		ft_free((void **)&operation);
		if (!error)
			operation = get_next_line(STDIN_FILENO);
	}
	if (error)
		ft_eputendl(RED_TEXT"Invalid operation"RESET);
	else if (!ps_issorted(&stack_a) || stack_b)
		ft_putendl("KO");
	else
		ft_putendl("OK");
	return (error);
}

static int	do_op(
	char const *operation,
	t_cdlist **stack_a,
	t_cdlist **stack_b)
{
	if (ft_strncmp(operation, PA"\n", ft_strlen(PA) + 1) == 0)
		pa(stack_b, stack_a, 0);
	else if (ft_strncmp(operation, PB"\n", ft_strlen(PB) + 1) == 0)
		pb(stack_a, stack_b, 0);
	else if (ft_strncmp(operation, SA"\n", ft_strlen(SA) + 1) == 0)
		sa(stack_a, 0);
	else if (ft_strncmp(operation, SB"\n", ft_strlen(SB) + 1) == 0)
		sb(stack_b, 0);
	else if (ft_strncmp(operation, SS"\n", ft_strlen(SS) + 1) == 0)
		ss(stack_a, stack_b, 0);
	else if (ft_strncmp(operation, RRA"\n", ft_strlen(RRA) + 1) == 0)
		rra(stack_a, 0);
	else if (ft_strncmp(operation, RRB"\n", ft_strlen(RRB) + 1) == 0)
		rrb(stack_b, 0);
	else if (ft_strncmp(operation, RRR"\n", ft_strlen(RRR) + 1) == 0)
		rrr(stack_a, stack_b, 0);
	else if (ft_strncmp(operation, RA"\n", ft_strlen(RA) + 1) == 0)
		ra(stack_a, 0);
	else if (ft_strncmp(operation, RB"\n", ft_strlen(RB) + 1) == 0)
		rb(stack_b, 0);
	else if (ft_strncmp(operation, RR"\n", ft_strlen(RR) + 1) == 0)
		rr(stack_b, stack_a, 0);
	else
		return (1);
	return (0);
}
