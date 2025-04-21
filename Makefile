# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/21 20:03:18 by sede-san          #+#    #+#              #
#    Updated: 2025/04/21 20:30:15 by sede-san         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ******************************* Output files ******************************* #

PUSH_SWAP = push_swap
VISUALIZER = visualizer

# ************************** Compilation variables *************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

# ********************************** Utils *********************************** #

MAKE += --no-print-directory

# ******************************* Compilation ******************************** #

# OBJ_PUSH_SWAP = $(SRC_PUSH_SWAP:.c=.o)

# %.o: %.c
# 	$(CC) $(CFLAGS) -c $< -o $@

# ****************************** Source files ******************************** #

SRC_PATH = src

PUSH_SWAP_PATH = $(SRC_PATH)/push_swap

SRC_PUSH_SWAP = \
	$(PUSH_SWAP_PATH)/push_swap.c											\
	$(PUSH_SWAP_PATH)/algorithms/ps_fivesort.c								\
	$(PUSH_SWAP_PATH)/algorithms/ps_foursort.c								\
	$(PUSH_SWAP_PATH)/algorithms/ps_insertionsort.c							\
	$(PUSH_SWAP_PATH)/algorithms/ps_mergesort.c								\
	$(PUSH_SWAP_PATH)/algorithms/ps_threesort.c								\
	$(PUSH_SWAP_PATH)/algorithms/ps_timsort.c								\
	$(PUSH_SWAP_PATH)/algorithms/ps_twosort.c								\
	$(PUSH_SWAP_PATH)/algorithms/ps_insertionsort_utils/ps_findtargets.c	\
	$(PUSH_SWAP_PATH)/algorithms/ps_insertionsort_utils/ps_getcheapest.c	\
	$(PUSH_SWAP_PATH)/operations/push.c										\
	$(PUSH_SWAP_PATH)/operations/reverserotate.c							\
	$(PUSH_SWAP_PATH)/operations/rotate.c									\
	$(PUSH_SWAP_PATH)/operations/swap.c										\
	$(PUSH_SWAP_PATH)/utils/ps_fillstack.c									\
	$(PUSH_SWAP_PATH)/utils/ps_issorted_run.c								\
	$(PUSH_SWAP_PATH)/utils/ps_issorted.c									\
	$(PUSH_SWAP_PATH)/utils/ps_new.c										\
	$(PUSH_SWAP_PATH)/utils/ps_runsize.c									\
	$(PUSH_SWAP_PATH)/utils/ps_updateindexes.c

# ********************************* Rules ************************************ #

all: $(PUSH_SWAP)

$(PUSH_SWAP): libft	ft_printf
	$(CC) $(CFLAGS) $(SRC_PUSH_SWAP) $(LIBFT) $(LIBFTPRINTF) -o $(PUSH_SWAP)

clean:
	$(MAKE) -C $(LIBFT_PATH) clean

fclean: clean
	rm -rf $(LIB_PATH)

re: fclean all

# ****************************** Libraries ********************************** #

LIB_PATH = lib

LIBFT_PATH = $(LIB_PATH)/Libft

LIBFT = $(LIBFT_PATH)/libft.a

libft:
	git clone git@github.com:sdevsantiago/Libft.git $(LIBFT_PATH)
	$(MAKE) -C $(LIBFT_PATH) all bonus clean

LIBFTPRINTF_PATH = $(LIB_PATH)/ft_printf

LIBFTPRINTF = $(LIBFTPRINTF_PATH)/libftprintf.a

ft_printf:
	git clone git@github.com:sdevsantiago/ft_printf.git $(LIBFTPRINTF_PATH)
	$(MAKE) -C $(LIBFTPRINTF_PATH) all
