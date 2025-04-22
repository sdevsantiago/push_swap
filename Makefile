# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/21 20:03:18 by sede-san          #+#    #+#              #
#    Updated: 2025/04/22 21:39:12 by sede-san         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ******************************* Output files ******************************* #

PUSH_SWAP = push_swap

# ************************** Compilation variables *************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

# ********************************** Utils *********************************** #

MAKE += --no-print-directory

# ******************************* Compilation ******************************** #

OBJ_PUSH_SWAP = $(SRC_PUSH_SWAP:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

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

all: libft ft_printf $(PUSH_SWAP)
	$(CC) $(CFLAGS) $(PUSH_SWAP_PATH)/$(PUSH_SWAP).a $(LIBFT) $(LIBFTPRINTF) -o $(PUSH_SWAP)

$(PUSH_SWAP): $(OBJ_PUSH_SWAP)
	ar rcs $(PUSH_SWAP_PATH)/$(PUSH_SWAP).a $(OBJ_PUSH_SWAP)

clean:
	if [ -d $(LIBFT_PATH) ]; then \
		$(MAKE) -C $(LIBFT_PATH) clean; \
	fi
	if [ -d $(LIBFTPRINTF_PATH) ]; then \
		$(MAKE) -C $(LIBFTPRINTF_PATH) clean; \
	fi
	rm -f $(OBJ_PUSH_SWAP)
	rm -f $(PUSH_SWAP_PATH)/$(PUSH_SWAP).a

fclean: clean
	rm -rf $(LIB_PATH)
	rm -rf $(VISUALIZER_PATH)
	rm -f $(PUSH_SWAP)
	rm -f $(PUSH_SWAP_PATH)/$(PUSH_SWAP).a

re: fclean all

# ******************************** Tools ************************************ #

VISUALIZER_PATH = push_swap_visualizer

visualizer:
	git clone https://github.com/o-reo/push_swap_visualizer.git $(VISUALIZER_PATH)

# ****************************** Libraries ********************************** #

LIB_PATH = lib

LIBFT_PATH = $(LIB_PATH)/Libft

LIBFT = $(LIBFT_PATH)/libft.a

libft:
	if [ ! -d $(LIBFT_PATH) ]; then \
		git clone https://github.com/sdevsantiago/Libft.git $(LIBFT_PATH); \
		$(MAKE) -C $(LIBFT_PATH) all bonus; \
	elif [ ! -f $(LIBFT) ]; then \
		$(MAKE) -C $(LIBFT_PATH) re bonus; \
	else \
		cd $(LIBFT_PATH); \
		git pull; \
		cd -; \
	fi

LIBFTPRINTF_PATH = $(LIB_PATH)/ft_printf

LIBFTPRINTF = $(LIBFTPRINTF_PATH)/libftprintf.a

ft_printf:
	if [ ! -d $(LIBFTPRINTF_PATH) ]; then \
		git clone https://github.com/sdevsantiago/ft_printf.git $(LIBFTPRINTF_PATH); \
		$(MAKE) -C $(LIBFTPRINTF_PATH) all; \
	elif [ ! -f $(LIBFTPRINTF) ]; then \
		$(MAKE) -C $(LIBFTPRINTF_PATH) re; \
	else \
		cd $(LIBFTPRINTF_PATH); \
		git pull; \
		cd -; \
	fi

# *********************************** Phony ********************************** #
.PHONY = all clean fclean re libft $(PUSH_SWAP) ft_printf
