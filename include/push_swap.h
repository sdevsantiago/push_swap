/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 13:26:18 by sede-san          #+#    #+#             */
/*   Updated: 2025/08/30 20:10:18 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "ft_printf.h"

# define ERROR_MESSAGE "Error"

# define ORDER_ASCENDING 1
# define ORDER_DESCENDING -1
# define ORDER_MIXED 0

# ifndef THRESHOLD
#  define THRESHOLD 110
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

// ps_twosort.c

void		ps_twosort(t_cdlist **stack_a);

// ps_threesort.c

void		ps_threesort(t_cdlist **stack_a);

// ps_foursort.c

void		ps_foursort(t_cdlist **stack_a, t_cdlist **stack_b);

// ps_fivesort.c

void		ps_fivesort(t_cdlist **stack_a, t_cdlist **stack_b);

// ps_timsort.c

void		ps_timsort(t_cdlist **stack_a, t_cdlist **stack_b);

// ps_insertionsort.c

void		ps_insertionsort(t_cdlist **stack_a, t_cdlist **stack_b,
				size_t run, int order);

// ps_mergesort.c

void		ps_mergesort(t_cdlist **stack_a, t_cdlist **stack_b,
				int order);

// push.c

# define PA "pa"
# define PB "pb"

void		pa(t_cdlist **stack_b, t_cdlist **stack_a, int print);
void		pb(t_cdlist **stack_a, t_cdlist **stack_b, int print);

// reverserotate.c

# define RRA "rra"
# define RRB "rrb"
# define RRR "rrr"

void		rra(t_cdlist **stack_a, int print);
void		rrb(t_cdlist **stack_b, int print);
void		rrr(t_cdlist **stack_a, t_cdlist **stack_b, int print);

// rotate.c

# define RA "ra"
# define RB "rb"
# define RR "rr"

void		ra(t_cdlist **stack_a, int print);
void		rb(t_cdlist **stack_b, int print);
void		rr(t_cdlist **stack_a, t_cdlist **stack_b, int print);

// swap.c

# define SA "sa"
# define SB "sb"
# define SS "ss"

void		sa(t_cdlist **stack_a, int print);
void		sb(t_cdlist **stack_b, int print);
void		ss(t_cdlist **stack_a, t_cdlist **stack_b, int print);

/*********************************** Utils ************************************/

void		ps_updateindexes(t_cdlist	**stack_a, t_cdlist **stack_b);
int			ps_issorted(t_cdlist **stack);
int			ps_issorted_run(t_cdlist **run_start, size_t run);
size_t		ps_runsize(t_cdlist **stack, size_t run);
t_cdlist	*ps_fillstack(char const *argv[]);
t_push_swap	*ps_new(int num, size_t index);

/**************************** Insertion sort utils ****************************/

void		ps_findtargets(t_cdlist **stack_a, t_cdlist **stack_b,
				int order, size_t run);
t_cdlist	*get_cheapest(t_cdlist **stack_a, t_cdlist **stack_b,
				size_t run, int order);

/****************************** Inline functions ******************************/

t_push_swap	*ps_data(t_cdlist *node);
size_t		ps_stacksize(t_cdlist **stack);
int			ps_istophalf(t_cdlist *node, t_cdlist **stack);

#endif /* PUSH_SWAP_H */
