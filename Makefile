# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/05 12:52:35 by sede-san          #+#    #+#              #
#    Updated: 2025/02/23 21:16:05 by sede-san         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ******************************* Output files ******************************* #

NAME_PUSH_SWAP = push_swap
NAME_CHECKER = checker
NAME_GENERATOR = generator

# Default name
NAME = $(NAME_PUSH_SWAP)

# ************************** Compilation variables *************************** #
# Compiler
CC = cc

# Compilation flags
CFLAGS = -Wall -Wextra -Werror

AR = ar rcs

# ****************************** Source files ******************************** #

PATH = src
PATH_PUSH_SWAP = $(PATH)/push_swap
PATH_CHECKER = $(PATH)/checker
PATH_GENERATOR = $(PATH)/generator
PATH_SHARED = $(PATH)/shared

SRC_PUSH_SWAP = \
	$(PATH_PUSH_SWAP)/push_swap.c					\
	$(PATH_PUSH_SWAP)/algorithms/ps_twosort.c		\
	$(PATH_PUSH_SWAP)/algorithms/ps_threesort.c		\
	$(PATH_PUSH_SWAP)/algorithms/ps_foursort.c		\
	$(PATH_PUSH_SWAP)/algorithms/ps_fivesort.c		\
	$(PATH_PUSH_SWAP)/algorithms/ps_timsort.c		\
	$(PATH_PUSH_SWAP)/algorithms/ps_insertionsort.c	\
	$(PATH_PUSH_SWAP)/operations/push.c				\
	$(PATH_PUSH_SWAP)/operations/reverserotate.c	\
	$(PATH_PUSH_SWAP)/operations/rotate.c			\
	$(PATH_PUSH_SWAP)/operations/swap.c				\
	$(PATH_PUSH_SWAP)/utils/ps_data.c				\
	$(PATH_PUSH_SWAP)/utils/ps_issorted.c

# SRC_CHECKER

SRC_GENERATOR = \
	$(PATH_GENERATOR)/generator.c

# ******************************* Compilation ******************************** #

OBJ_PUSH_SWAP = $(SRC_PUSH_SWAP:.c=.o)
OBJ_CHECKER = $(SRC_CHECKER:.c=.o)
OBJ_GENERATOR = $(SRC_GENERATOR:.c=.o)

# Default compilation
OBJ = $(OBJ_PUSH_SWAP)

# Compile object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# ********************************** Rules *********************************** #

all: $(NAME)

$(NAME): $(OBJ_PUSH_SWAP)
	$(MAKE) -C lib/Libft all bonus
	$(MAKE) -C lib/ft_printf all
	mkdir build
	cp lib/Libft/libft.a build
	cp lib/ft_printf/libftprintf.a build
	$(AR) build/libft.a build/libftprintf.a $(OBJ_PUSH_SWAP)

bonus:

$(NAME_GENERATOR): $(OBJ_GENERATOR)
	$(MAKE) -C lib/Libft all bonus
	$(AR) $(NAME_GENERATOR)