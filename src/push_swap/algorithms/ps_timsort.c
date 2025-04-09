/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_timsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 19:02:45 by sede-san          #+#    #+#             */
/*   Updated: 2025/04/09 11:11:49 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/push_swap.h"
#include "../../../lib/ft_printf/ft_printf.h"

// static void _stackdump(t_cdlist **stack, char stack_letter)
// {
// 	t_cdlist	*current;

// 	ft_printf("stack_%c:", stack_letter);
// 	if (!*stack)
// 	{
// 		ft_printf("Empty\n");
// 		return ;
// 	}
// 	current = *stack;
// 	while (current)
// 	{
// 		ft_printf(" %d", ps_data(current)->num);
// 		current = current->next;
// 		if (current == *stack)
// 			break ;
// 	}
// 	ft_printf("\n");
// }

// static void	_rundump(t_cdlist **stack_a, size_t run)
// {
// 	t_cdlist	*current_a;

// 	current_a = *stack_a;
// 	while (current_a)
// 	{
// 		if (ps_data(current_a)->run == run)
// 			ft_printf("%d ",ps_data(current_a)->num);
// 		current_a = current_a->next;
// 		if (current_a == *stack_a)
// 			break ;
// 	}
// 	ft_putchar('\n');
// }

static void	_assignruns(t_cdlist **stack);
static void _terminate_insertionsort(t_cdlist **stack_a, t_cdlist **stack_b,
				int order);

void	ps_timsort(t_cdlist **stack_a, t_cdlist **stack_b)
{
	size_t	run;
	int		order;

	_assignruns(stack_a);
	order = ORDER_DESCENDING;
	while (ps_issorted(stack_a) != ORDER_ASCENDING)
	{
		if (ps_data(*stack_a)->run == SORTED_RUN)
			run = ps_data(ft_cdlstlast(*stack_a))->run;
		else
			run = ps_data(*stack_a)->run;
		// ft_printf("Sorting run %d of lenght %d\n", run, ps_runsize(stack_a, run));
		// _rundump(stack_a, run);
		ps_insertionsort(stack_a, stack_b, run, order);
		_terminate_insertionsort(stack_a, stack_b, order);
		// ft_printf("Merging...\n");
		ps_mergesort(stack_a, stack_b);
		// ft_printf("Run %d sorted and merged\n", run);
		if (order == ORDER_DESCENDING)
			order = ORDER_ASCENDING;
		// // else
		// // 	order = ORDER_DESCENDING;
		// _stackdump(stack_a, 'a');
		// _stackdump(stack_b, 'b');
	}
}

/**
 * @brief Assigns a run to each node in `stack_a`.
 * @param stack_a The initial stack before any modifications.
 * @details
 * @note This function should be executed one time only.
 */
static void _assignruns(t_cdlist **stack_a)
{
	t_cdlist	*current;
	t_cdlist	*run_start;
	size_t		run;
	size_t		i;
	int			run_order;

	current = *stack_a;
	run = 1;
	while (current)
	{
		run_start = current;
		i = 0;
		while (i++ < THRESHOLD)
		{
			ps_data(current)->run = run;
			current = current->next;
			if (current == *stack_a)
				return ;
		}
		run_order = ps_issorted_run(&run_start, run);
		if (run_order == ORDER_ASCENDING)
		{
			while (ps_data(current)->num > ps_data(current->previous)->num)
			{
				ps_data(current)->run = run;
				current = current->next;
				if (current == *stack_a)
					return ;
			}
		}
		else if (run_order == ORDER_DESCENDING)
		{
			while (ps_data(current)->num < ps_data(current->previous)->num)
			{
				ps_data(current)->run = run;
				current = current->next;
				if (current == *stack_a)
					return ;
			}
		}
		run++;
	}
}

static void	_terminate_insertionsort(t_cdlist **stack_a, t_cdlist **stack_b,
				int order)
{
	t_cdlist	*b_head;
	t_cdlist	*sorted_run;

	b_head = *stack_b;
	while (!(ps_data(b_head->previous)->num > ps_data(b_head)->num
		&& ps_data(b_head->next)->num > ps_data(b_head)->num))
	{
		b_head = b_head->next;
		if (b_head == *stack_b)
			break ;
	}
	if (order == ORDER_DESCENDING)
	{
		if (ps_istophalf(b_head, ps_stacksize(stack_b)))
			while (*stack_b != b_head)
				rb(stack_b);
		else
			while (*stack_b != b_head)
				rrb(stack_b);
		return ;
	}
	sorted_run = *stack_a;
	while (ps_data(sorted_run)->run != SORTED_RUN)
		sorted_run = sorted_run->next;
	if (ps_istophalf(sorted_run, ps_stacksize(stack_a)) &&
		ps_istophalf(b_head, ps_stacksize(stack_b)))
		while (*stack_a != sorted_run && *stack_b != b_head)
			rr(stack_a, stack_b);
	while (*stack_a != sorted_run)
			ra(stack_a);
	if (ps_istophalf(b_head, ps_stacksize(stack_b)))
		while (*stack_b != b_head)
			rb(stack_b);
	else
		while (*stack_b != b_head)
			rrb(stack_b);
}
