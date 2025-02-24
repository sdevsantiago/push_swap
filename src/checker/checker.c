/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 12:19:00 by sede-san          #+#    #+#             */
/*   Updated: 2025/02/12 19:06:47 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"
#include "../../lib/Libft/libft.h"
#include "../../lib/ft_printf/ft_printf.h"
#include "../../lib/get_next_line/get_next_line.h"

int	checker(t_cdlist *stack_a, t_cdlist *stack_b);
static void	_fillstack();
/**
 * TODO pending flags
 * -v, --visual
 */
static void	_checkflags(char const *argv[]);

int		main(int argc, char const *argv[])
{
	t_cdlist	*stack_a;
	t_cdlist	*stack_b;

	if (argc < 2)
		return (ft_printf(ERROR_MESSAGE), EXIT_FAILURE);
	if (!stack_a)
		return (ft_printf(ERROR_MESSAGE), EXIT_FAILURE);
	stack_b = NULL;
	if (checker(stack_a, stack_b))
		ft_printf("OK");
	else
		ft_printf("KO");
	return (EXIT_SUCCESS);
}
