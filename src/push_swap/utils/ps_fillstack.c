/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_fillstack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 14:02:45 by sede-san          #+#    #+#             */
/*   Updated: 2025/04/21 18:51:11 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/push_swap.h"

static int	_isvalid(char *num);
static int	_isunique(int num, t_cdlist *stack);
static int	_isint(char *num);
static void	_free_split(char **matrix);

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
			if (!_isvalid(num[i]) || !_isint(num[i]) || !_isunique(n, stack))
				return (ft_cdlstclear(&stack, free), _free_split(num), NULL);
			if (!stack)
				ft_cdlstadd_back(&stack, ft_cdlstnew((void *)ps_new(n, 0)));
			else
				ft_cdlstadd_back(&stack, ft_cdlstnew((void *)
						ps_new(n, ps_data(ft_cdlstlast(stack))->index + 1)));
			i++;
		}
		_free_split(num);
	}
	return (stack);
}

static int	_isvalid(char *num)
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

static int	_isint(char *num)
{
	long	value;

	value = ft_atol(num);
	return (value >= INT_MIN && value <= INT_MAX);
}

static int	_isunique(int num, t_cdlist *stack)
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

static void	_free_split(char **matrix)
{
	size_t	i;

	if (!matrix)
		return ;
	i = 0;
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}
