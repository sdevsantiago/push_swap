# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/05 12:52:35 by sede-san          #+#    #+#              #
#    Updated: 2025/03/10 10:43:59 by sede-san         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ******************************* Output files ******************************* #

PUSH_SWAP = push_swap
CHECKER = checker
GENERATOR = generator

# Default name
NAME = $(PUSH_SWAP)

# ************************** Compilation variables *************************** #
# Compiler
CC = cc

# Compilation flags
CFLAGS = -Wall -Wextra -Werror

AR = ar rcs

# ****************************** Libraries ********************************** #

LIBFT = lib/Libft/libft.a
LIBFTPRINTF = lib/ft_printf/libftprintf.a

# ****************************** Source files ******************************** #

PATH = src
PATH_PUSH_SWAP = $(PATH)/push_swap
PATH_CHECKER = $(PATH)/checker
PATH_GENERATOR = $(PATH)/generator
PATH_SHARED = $(PATH)/shared

SRC_PUSH_SWAP = \
	$(PATH_PUSH_SWAP)/push_swap.c					\
	$(PATH_PUSH_SWAP)/algorithms/ps_fivesort.c		\
	$(PATH_PUSH_SWAP)/algorithms/ps_foursort.c		\
	$(PATH_PUSH_SWAP)/algorithms/ps_insertionsort.c	\
	$(PATH_PUSH_SWAP)/algorithms/ps_mergesort.c		\
	$(PATH_PUSH_SWAP)/algorithms/ps_threesort.c		\
	$(PATH_PUSH_SWAP)/algorithms/ps_timsort.c		\
	$(PATH_PUSH_SWAP)/algorithms/ps_twosort.c		\
	$(PATH_PUSH_SWAP)/operations/push.c				\
	$(PATH_PUSH_SWAP)/operations/reverserotate.c	\
	$(PATH_PUSH_SWAP)/operations/rotate.c			\
	$(PATH_PUSH_SWAP)/operations/swap.c				\
	$(PATH_PUSH_SWAP)/utils/ps_fillstack.c			\
	$(PATH_PUSH_SWAP)/utils/ps_issorted_run.c		\
	$(PATH_PUSH_SWAP)/utils/ps_issorted.c			\
	$(PATH_PUSH_SWAP)/utils/ps_new.c

# SRC_CHECKER

SRC_GENERATOR = \
	$(PATH_GENERATOR)/generator.c

# ******************************* Compilation ******************************** #

OBJ_PUSH_SWAP = $(SRC_PUSH_SWAP:.c=.o)
OBJ_CHECKER = $(SRC_CHECKER:.c=.o)
OBJ_GENERATOR = $(SRC_GENERATOR:.c=.o)

# # Default compilation
# OBJ = $(OBJ_PUSH_SWAP)

# Compile object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# ********************************** Rules *********************************** #

all: $(NAME)

$(NAME): $(OBJ_PUSH_SWAP)
	$(MAKE) -C lib/Libft all bonus
	$(MAKE) -C lib/ft_printf all
	$(shell mkdir -p build/{push_swap,checker,generator})
	cp lib/Libft/libft.a build
	cp lib/ft_printf/libftprintf.a build
	$(CC) $(CFLAGS) $(SRC_PUSH_SWAP) $(LIBFT) $(LIBFTPRINTF) -o $(PUSH_SWAP)


bonus:

$(NAME_GENERATOR): $(OBJ_GENERATOR)
	$(MAKE) -C lib/Libft all bonus
	$(AR) $(NAME_GENERATOR)

# ********************************** Tools ********************************** #

VISUALIZER_URL = https://github.com/o-reo/push_swap_visualizer.git
VISUALIZER_PATH = push_swap_visualizer
GIT = /usr/bin/git
$(NAME_VISUALIZER):
	$(GIT) clone $(VISUALIZER_URL) $(VISUALIZER_PATH)
.PHONY: visualizer
