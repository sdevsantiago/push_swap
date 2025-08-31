/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 13:23:37 by sede-san          #+#    #+#             */
/*   Updated: 2025/08/31 01:28:16 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_swap(t_cdlist **stack_a, t_cdlist **stack_b);

/**
 * @brief Main function that initializes and sorts the stack.
 *
 * @param argc Argument count from command line.
 * @param argv Array of strings containing the numbers to sort.
 *
 * @return EXIT_SUCCESS if sorting completed successfully, EXIT_FAILURE on
 *         error.
 *
 * @details This function:
 * 1. Validates arguments (exits if no arguments provided)
 * 2. Fills stack_a with parsed and validated numbers
 * 3. Checks if already sorted (returns early if sorted)
 * 4. Calls push_swap algorithm to sort the stack
 * 5. Cleans up allocated memory before exiting
 */
int	main(
	int argc,
	char const *argv[])
{
	t_cdlist	*stack_a;
	t_cdlist	*stack_b;

	if (argc < 2)
		return (EXIT_FAILURE);
	stack_a = ps_fillstack(argv);
	if (!stack_a)
		return (ft_eputendl(ERROR_MESSAGE), EXIT_FAILURE);
	if (ps_issorted(&stack_a) == ORDER_ASCENDING)
		return (ft_cdlstclear(&stack_a, free), EXIT_SUCCESS);
	stack_b = NULL;
	push_swap(&stack_a, &stack_b);
	ft_cdlstclear(&stack_a, free);
	ft_cdlstclear(&stack_b, free);
	return (EXIT_SUCCESS);
}

/**
 * @brief Sorts a stack of numbers in ascending order using the optimal
 *        algorithm.
 *
 * @param stack_a Pointer to the main stack containing numbers to sort.
 * @param stack_b Pointer to the auxiliary stack (initially empty).
 *
 * @details Selects the appropriate sorting algorithm based on stack size:
 * - 2 elements: Simple swap if needed
 * - 3 elements: Optimized 3-element sort (max 2 operations)
 * - 4 elements: Move smallest to top, then 3-sort
 * - 5 elements: Move 2 smallest to stack_b, then 3-sort and merge
 * - >5 elements: Timsort-inspired algorithm with runs and merging
 *
 * @attention Numbers must be unique integers within INT_MIN to INT_MAX range.
 */
static void	push_swap(
	t_cdlist **stack_a,
	t_cdlist **stack_b)
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
