/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 13:26:18 by sede-san          #+#    #+#             */
/*   Updated: 2025/03/07 16:56:53 by sede-san         ###   ########.fr       */
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
	push_swap data structure
	@param	num The value stored
	@param	index The index where the node is located
*/
typedef struct s_push_swap
{
	int				num;
	size_t			index;
	size_t			moves_a;
	size_t			moves_b;
	unsigned char	run;
	unsigned char	index_run;
}				t_push_swap;

/********************************* Algorithms *********************************/

void		ps_twosort(t_cdlist **stack_a);
void		ps_threesort(t_cdlist **stack_a);
void		ps_foursort(t_cdlist **stack_a, t_cdlist **stack_b);
void		ps_fivesort(t_cdlist **stack_a, t_cdlist **stack_b);
void		ps_timsort(t_cdlist **stack_a, t_cdlist **stack_b, size_t size);
void		ps_insertionsort(t_cdlist **stack_a, t_cdlist **stack_b,
				size_t run);

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

int			ps_issorted(t_cdlist **stack);
int			ps_issorted_run(t_cdlist **run_start, size_t run);
t_cdlist	*ps_fillstack(char const *argv[]);
t_push_swap	*ps_new(int num, size_t index);

/****************************** Inline functions ******************************/

static inline t_push_swap	*ps_data(t_cdlist *node)
{
	return ((t_push_swap *)(node->content));
}

#endif /* PUSH_SWAP_H */
