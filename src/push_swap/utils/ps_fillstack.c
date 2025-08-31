/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_fillstack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 14:02:45 by sede-san          #+#    #+#             */
/*   Updated: 2025/08/30 20:10:53 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	isvalid(char *num);
static int	isunique(int num, t_cdlist *stack);
static int	isint(char *num);

/**
 * @brief Creates and fills a stack from command line arguments.
 *
 * @param argv Array of strings containing numbers to parse (argv from main).
 *
 * @return Pointer to the created stack, or NULL if parsing fails.
 *
 * @details
 * Parses command line arguments to create a circular doubly linked list:
 *
 * 1. Splits each argument string by spaces to handle multiple numbers per arg
 *
 * 2. Validates each number (valid format, integer range, uniqueness)
 *
 * 3. Creates nodes with ps_new() and adds them with proper indexing
 *
 * 4. Returns NULL and cleans up on any validation error
 *
 * Validation performed:
 * - Valid number format (digits, optional sign)
 * - Within INT_MIN to INT_MAX range
 * - No duplicate numbers in the final stack
 */
t_cdlist	*ps_fillstack(char const *argv[])
{
	t_cdlist	*stack;
	char		**num;
	int			n;
	size_t		i;

	stack = NULL;
	while (*++argv)
	{
		num = ft_split(*argv, ' ');
		i = 0;
		while (num[i])
		{
			n = ft_atoi(num[i]);
			if (!isvalid(num[i]) || !isint(num[i]) || !isunique(n, stack))
				return (ft_cdlstclear(&stack, free), ft_free_split(num), NULL);
			if (!stack)
				ft_cdlstadd_back(&stack, ft_cdlstnew((void *)ps_new(n, 0)));
			else
				ft_cdlstadd_back(&stack, ft_cdlstnew((void *)
						ps_new(n, ps_data(ft_cdlstlast(stack))->index + 1)));
			i++;
		}
		ft_free_split(num);
	}
	return (stack);
}

static int	isvalid(char *num)
{
	size_t	signs;

	signs = 0;
	while (*num)
	{
		if (ft_strchr("+-", *num))
		{
			if (!signs)
				signs++;
			else
				return (0);
		}
		else if (!ft_isdigit(*num))
			return (0);
		num++;
	}
	return (1);
}

static int	isint(char *num)
{
	long	value;

	value = ft_atol(num);
	return (value >= INT_MIN && value <= INT_MAX);
}

static int	isunique(int num, t_cdlist *stack)
{
	t_cdlist	*current;

	if (!stack)
		return (1);
	current = stack;
	while (current)
	{
		if (ps_data(current)->num == num)
			return (0);
		current = current->next;
		if (current == stack)
			break ;
	}
	return (1);
}
