/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 12:20:31 by sede-san          #+#    #+#             */
/*   Updated: 2025/02/18 16:27:33 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/Libft/libft.h"

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define ERROR_MESSAGE "Error\n"

# ifndef THRESHOLD
#  define THRESHOLD 32
# endif
# if THRESHOLD < 32 || THRESHOLD > 64
#  warning "THRESHOLD should be between 32 and 64"
# endif

# define SORTED_DESCENDING -1
# define SORTED_MIXED 0
# define SORTED_ASCENDING 1

/**
	push_swap data structure
	@param	num The value stored
	@param	index The index where the node is located
*/
typedef struct	s_push_swap
{
	int				num;
	size_t			index;
	unsigned char	run;
	unsigned char	index_run;
}				t_push_swap;

/********************************* Movements **********************************/

void		pa(t_cdlist *stack_a, t_cdlist *stack_b);
void		pb(t_cdlist *stack_a, t_cdlist *stack_b);

void		sa(t_cdlist *stack_a);
void		sb(t_cdlist *stack_b);
void		ss(t_cdlist *stack_a, t_cdlist *stack_b);

void		ra(t_cdlist *stack_a);
void		rb(t_cdlist *stack_b);
void		rr(t_cdlist *stack_a, t_cdlist *stack_b);

void		rra(t_cdlist *stack_a);
void		rrb(t_cdlist *stack_b);
void		rrr(t_cdlist *stack_a, t_cdlist *stack_b);

/********************************* Algorithms *********************************/

void		ps_twosort(t_cdlist *stack_a);
void		ps_threesort(t_cdlist *stack_a);
void		ps_foursort(t_cdlist *stack_a, t_cdlist *stack_b);
void		ps_timsort(t_cdlist *stack_a, t_cdlist *stack_b, size_t size);

/************************************ Shared **********************************/

int			ps_issorted(t_cdlist *stack);
t_cdlist	*ps_fillstack(char const *argv[]);
t_push_swap	*ps_new(int num, size_t index);

/************************************* Utils **********************************/

t_cdlist	*ps_getbiggest(t_cdlist *stack);
t_cdlist	*ps_getlowest(t_cdlist *stack);
t_push_swap	*ps_data(t_cdlist *stack);

/************************************ Timsort *********************************/

void		ps_reverse_run(unsigned char const run,
						t_cdlist **stack_a, t_cdlist **stack_b);


#endif