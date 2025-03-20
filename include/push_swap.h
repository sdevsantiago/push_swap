/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 13:26:18 by sede-san          #+#    #+#             */
/*   Updated: 2025/03/20 13:50:27 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../lib/Libft/libft.h"

# define ERROR_MESSAGE "Error\n"

# define ORDER_ASCENDING 1
# define ORDER_DESCENDING -1
# define ORDER_MIXED 0

# ifndef THRESHOLD
#  define THRESHOLD 32
# endif

# define SORTED_RUN 0

/**
	@param num The value stored
	@param index The index where the node is located
	@param target The following/previous node once the run is ordered
	@param run The run that number belongs to. This is only used if timsort is
	used
*/
typedef struct s_push_swap
{
	int				num;
	size_t			index;
	t_cdlist		*target;
	unsigned long	run;
}				t_push_swap;

/********************************* Algorithms *********************************/

void		ps_twosort(t_cdlist **stack_a);
void		ps_threesort(t_cdlist **stack_a);
void		ps_foursort(t_cdlist **stack_a, t_cdlist **stack_b);
void		ps_fivesort(t_cdlist **stack_a, t_cdlist **stack_b);
void		ps_timsort(t_cdlist **stack_a, t_cdlist **stack_b);
void		ps_insertionsort(t_cdlist **stack_a, t_cdlist **stack_b,
				size_t run, int order);
void		ps_mergesort(t_cdlist **stack_a, t_cdlist **stack_b);

/********************************* Operations *********************************/

void		pa(t_cdlist **stack_b, t_cdlist **stack_a);
void		pb(t_cdlist **stack_a, t_cdlist **stack_b);
void		rra(t_cdlist **stack_a);
void		rrb(t_cdlist **stack_b);
void		rrr(t_cdlist **stack_a, t_cdlist **stack_b);
void		ra(t_cdlist **stack_a);
void		rb(t_cdlist **stack_b);
void		rr(t_cdlist **stack_a, t_cdlist **stack_b);
void		sa(t_cdlist **stack_a);
void		sb(t_cdlist **stack_b);
void		ss(t_cdlist **stack_a, t_cdlist **stack_b);

/*********************************** Utils ************************************/

void		ps_updateindexes(t_cdlist	**stack_a, t_cdlist **stack_b);
int			ps_issorted(t_cdlist **stack);
int			ps_issorted_run(t_cdlist **run_start, size_t run);
size_t		ps_runsize(t_cdlist **stack, size_t run);
t_cdlist	*ps_fillstack(char const *argv[]);
t_push_swap	*ps_new(int num, size_t index);

/**************************** Insertion sort utils ****************************/

void		ps_findtargets(t_cdlist **stack_a, t_cdlist **stack_b, int order,
				size_t run);
int			ps_checkskips(t_cdlist **stack_a);
t_cdlist	*ps_getcheapest(t_cdlist **stack_a, t_cdlist **stack_b,
				size_t run, int order);

/****************************** Inline functions ******************************/

/**
 * @brief Converts a doubly linked list node into a pointer to `t_push_swap`.
 *
 * @param node Pointer to a doubly linked list node (`t_cdlist`).
 *
 * @return A pointer to `t_push_swap` stored in the node's content field.
 *
 * @warning It is assumed that the `content` field of the node contains a pointer
 * to a t_push_swap structure. No safety checks are performed (e.g., if node is
 * `NULL`).
 *
 * @note The sole purpose of this function (and inline functions in general) is
 * to suggest the compiler that should replace whatever is inside this function
 * whenever it's called. This is done to avoid function call overhead, which can
 * be caused if many functions are called consecutively (e.g. repeatedly
 * recursion). Type checks are still performed. This means that, in the case of
 * passing a value of different type that the one requested, the compiler will
 * throw an error.
 */
static inline t_push_swap	*ps_data(t_cdlist *node)
{
	return ((t_push_swap *)(node->content));
}

static inline int	ps_istophalf(t_cdlist *node, size_t stack_size)
{
	return (ps_data(node)->index <= (size_t)(stack_size / 2));
}

#endif /* PUSH_SWAP_H */
