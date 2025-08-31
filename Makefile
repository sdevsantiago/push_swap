# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/21 20:03:18 by sede-san          #+#    #+#              #
#    Updated: 2025/08/31 02:06:03 by sede-san         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ******************************* Output files ******************************* #

NAME		= push_swap
BONUS_NAME	= checker

# ************************** Compilation variables *************************** #

CC		= cc
CFLAGS	= -Wall -Wextra -Werror
HEADERS	= -I $(INCLUDE_PATH) -I $(LIBFT_INCLUDE_PATH) -I $(FT_PRINTF_INCLUDE_PATH) -I $(GET_NEXT_LINE_INCLUDE_PATH)

ifeq ($(DEBUG), 1)
	CFLAGS += -g3
endif

MAKE += --no-print-directory

# ****************************** Source files ******************************** #

SRC_PATH = src

SRC =																			\
	$(SRC_PATH)/push_swap/push_swap.c											\
	$(SRC_PATH)/push_swap/algorithms/ps_fivesort.c								\
	$(SRC_PATH)/push_swap/algorithms/ps_foursort.c								\
	$(SRC_PATH)/push_swap/algorithms/ps_insertionsort.c							\
	$(SRC_PATH)/push_swap/algorithms/ps_mergesort.c								\
	$(SRC_PATH)/push_swap/algorithms/ps_threesort.c								\
	$(SRC_PATH)/push_swap/algorithms/ps_timsort.c								\
	$(SRC_PATH)/push_swap/algorithms/ps_twosort.c								\
	$(SRC_PATH)/push_swap/algorithms/ps_insertionsort_utils/ps_findtargets.c	\
	$(SRC_PATH)/push_swap/algorithms/ps_insertionsort_utils/ps_getcheapest.c	\
	$(SRC_PATH)/push_swap/operations/push.c										\
	$(SRC_PATH)/push_swap/operations/reverserotate.c							\
	$(SRC_PATH)/push_swap/operations/rotate.c									\
	$(SRC_PATH)/push_swap/operations/swap.c										\
	$(SRC_PATH)/push_swap/utils/ps_data.c										\
	$(SRC_PATH)/push_swap/utils/ps_fillstack.c									\
	$(SRC_PATH)/push_swap/utils/ps_issorted_run.c								\
	$(SRC_PATH)/push_swap/utils/ps_issorted.c									\
	$(SRC_PATH)/push_swap/utils/ps_istophalf.c									\
	$(SRC_PATH)/push_swap/utils/ps_new.c										\
	$(SRC_PATH)/push_swap/utils/ps_runsize.c									\
	$(SRC_PATH)/push_swap/utils/ps_stacksize.c									\
	$(SRC_PATH)/push_swap/utils/ps_updateindexes.c

BONUS_SRC =												\
	$(SRC_PATH)/checker/checker.c						\
	$(SRC_PATH)/push_swap/operations/push.c				\
	$(SRC_PATH)/push_swap/operations/reverserotate.c	\
	$(SRC_PATH)/push_swap/operations/rotate.c			\
	$(SRC_PATH)/push_swap/operations/swap.c				\
	$(SRC_PATH)/push_swap/utils/ps_data.c				\
	$(SRC_PATH)/push_swap/utils/ps_fillstack.c			\
	$(SRC_PATH)/push_swap/utils/ps_issorted.c			\
	$(SRC_PATH)/push_swap/utils/ps_new.c				\
	$(SRC_PATH)/push_swap/utils/ps_updateindexes.c

INCLUDE_PATH = include

# ****************************** Object files ******************************** #

OBJS_PATH	= build
OBJS		= $(SRC:$(SRC_PATH)/%.c=$(OBJS_PATH)/%.o)
BONUS_OBJS	= $(BONUS_SRC:$(SRC_PATH)/%.c=$(OBJS_PATH)/%.o)

$(OBJS_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@
	@echo "$< compiled"

# ********************************* Rules ************************************ #

all: mandatory bonus
.PHONY: all

mandatory: libft ft_printf $(NAME)
.PHONY: mandatory

bonus: libft ft_printf get_next_line $(BONUS_NAME)
.PHONY: bonus

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT_BIN) $(FT_PRINTF_BIN) -o $(NAME)
	@echo "$(GREEN)$(EMOJI_CHECK) $(NAME) ready. $(RESET)"

$(BONUS_NAME): $(BONUS_OBJS)
	@$(CC) $(CFLAGS) $(BONUS_OBJS) $(LIBFT_BIN) $(FT_PRINTF_BIN) $(GET_NEXT_LINE_BIN) $(LIBS) -o $(BONUS_NAME)
	@echo "$(GREEN)$(EMOJI_CHECK) $(BONUS_NAME) ready. $(RESET)"

clean:
	@rm -rf $(OBJS_PATH)
.PHONY: clean

fclean: clean
	@rm -f $(NAME)
	@rm -f $(BONUS_NAME)
	@if [ -d $(LIBFT_PATH) ]; then										\
		$(MAKE) --silent -C $(LIBFT_PATH) fclean > /dev/null;			\
	fi
	@if [ -d $(FT_PRINTF_PATH) ]; then									\
		$(MAKE) --silent -C $(FT_PRINTF_PATH) fclean > /dev/null;		\
	fi
	@if [ -d $(GET_NEXT_LINE_PATH) ]; then								\
		$(MAKE) --silent -C $(GET_NEXT_LINE_PATH) fclean > /dev/null;	\
	fi
	@if [ -d $(VISUALIZER_PATH) ]; then									\
		rm -rf $(VISUALIZER_PATH)/build;								\
	fi
.PHONY: fclean

re: fclean all
.PHONY: re

# ****************************** Libraries ********************************** #

LIB_PATH = lib

# ** Libft ** #

LIBFT				= Libft
LIBFT_REPO			= https://github.com/sdevsantiago/Libft.git
LIBFT_PATH			= $(LIB_PATH)/$(LIBFT)
LIBFT_INCLUDE_PATH	= $(LIBFT_PATH)
LIBFT_BIN			= $(LIBFT_PATH)/libft.a

libft: $(LIBFT_BIN)
.PHONY: libft

$(LIBFT_BIN):
	@if [ ! -d $(LIBFT_PATH) ]; then									\
		echo "$(YELLOW)$(EMOJI_WRENCH) Cloning $(LIBFT)...$(RESET)";	\
		git clone --quiet $(LIBFT_REPO) $(LIBFT_PATH);					\
		rm -rf $(LIBFT_PATH)/.git;										\
		echo "$(GREEN)$(EMOJI_CHECK) $(LIBFT) cloned...$(RESET)";		\
	fi
	@if [ ! -f $(LIBFT_BIN) ]; then										\
		echo "$(YELLOW)$(EMOJI_WRENCH) Compiling $(LIBFT)...$(RESET)";	\
		$(MAKE) --silent -C $(LIBFT_PATH) all clean;					\
		echo "$(GREEN)$(EMOJI_CHECK) $(LIBFT) compiled.$(RESET)";		\
	fi

# ** ft_printf **

FT_PRINTF				= ft_printf
FT_PRINTF_REPO			= https://github.com/sdevsantiago/ft_printf.git
FT_PRINTF_PATH			= $(LIB_PATH)/$(FT_PRINTF)
FT_PRINTF_INCLUDE_PATH	= $(FT_PRINTF_PATH)/include
FT_PRINTF_BIN			= $(FT_PRINTF_PATH)/libftprintf.a

ft_printf: $(FT_PRINTF_BIN)
.PHONY: ft_printf

$(FT_PRINTF_BIN):
	@if [ ! -d $(FT_PRINTF_PATH) ]; then \
		echo "$(YELLOW)$(EMOJI_WRENCH) Cloning $(FT_PRINTF)...$(RESET)";	\
		git clone --quiet $(FT_PRINTF_REPO) $(FT_PRINTF_PATH);				\
		rm -rf $(FT_PRINTF_PATH)/.git;										\
		echo "$(GREEN)$(EMOJI_CHECK) $(FT_PRINTF) cloned...$(RESET)";		\
	fi
	@if [ ! -f $(FT_PRINTF_BIN) ]; then \
		echo "$(YELLOW)$(EMOJI_WRENCH) Compiling $(FT_PRINTF)...$(RESET)";					\
		$(MAKE) --silent -C $(FT_PRINTF_PATH) all clean LIBFT_PATH=../$(LIBFT) > /dev/null;	\
		echo "$(GREEN)$(EMOJI_CHECK) $(FT_PRINTF) compiled.$(RESET)";						\
	fi

# ** get_next_line **

GET_NEXT_LINE				= get_next_line
GET_NEXT_LINE_REPO			= https://github.com/sdevsantiago/get_next_line.git
GET_NEXT_LINE_PATH			= $(LIB_PATH)/$(GET_NEXT_LINE)
GET_NEXT_LINE_INCLUDE_PATH	= $(GET_NEXT_LINE_PATH)/include
GET_NEXT_LINE_BIN			= $(GET_NEXT_LINE_PATH)/get_next_line.a

get_next_line: $(GET_NEXT_LINE_BIN)
.PHONY: get_next_line

$(GET_NEXT_LINE_BIN):
	@if [ ! -d $(GET_NEXT_LINE_PATH) ]; then \
		echo "$(YELLOW)$(EMOJI_WRENCH) Cloning $(GET_NEXT_LINE)...$(RESET)";	\
		git clone --quiet $(GET_NEXT_LINE_REPO) $(GET_NEXT_LINE_PATH);			\
		rm -rf $(GET_NEXT_LINE_PATH)/.git;										\
		rm -rf $(GET_NEXT_LINE_PATH)/tests;										\
		rm -rf $(GET_NEXT_LINE_PATH)/files;										\
		echo "$(GREEN)$(EMOJI_CHECK) $(GET_NEXT_LINE) cloned...$(RESET)";		\
	fi
	@if [ ! -f $(GET_NEXT_LINE_BIN) ]; then \
		echo "$(YELLOW)$(EMOJI_WRENCH) Compiling $(GET_NEXT_LINE)...$(RESET)";					\
		$(MAKE) --silent -C $(GET_NEXT_LINE_PATH) mandatory clean BUFFER_SIZE=1 > /dev/null; 	\
		echo "$(GREEN)$(EMOJI_CHECK) $(GET_NEXT_LINE) compiled.$(RESET)";						\
	fi

# ******************************** Tools ************************************ #

VISUALIZER		= push_swap_visualizer
VISUALIZER_REPO	= https://github.com/o-reo/push_swap_visualizer.git
VISUALIZER_PATH	= $(VISUALIZER)
VISUALIZER_BIN	= $(VISUALIZER_PATH)/bin/visualizer

visualizer: $(VISUALIZER_BIN)
.PHONY: visualizer

$(VISUALIZER_BIN):
	@if [ ! -d $(VISUALIZER_PATH) ]; then \
		echo "$(YELLOW)$(EMOJI_WRENCH) Cloning $(VISUALIZER)...$(RESET)";	\
		git clone --quiet $(VISUALIZER_REPO);								\
		rm -rf $(VISUALIZER_PATH)/.git;										\
		echo "$(GREEN)$(EMOJI_CHECK) $(VISUALIZER) cloned...$(RESET)";		\
	fi
	@if [ ! -f $(VISUALIZER_BIN) ]; then \
		echo "$(YELLOW)$(EMOJI_WRENCH) Compiling $(VISUALIZER)...$(RESET)";	\
		cd $(VISUALIZER_PATH);												\
		mkdir build;														\
		cd build;															\
		cmake ..;															\
		make;																\
		echo "$(GREEN)$(EMOJI_CHECK) $(VISUALIZER) compiled.$(RESET)";		\
	fi

# ***************************** Style variables ****************************** #

RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
BLUE = \033[0;34m
RESET = \033[0m

EMOJI_BROOM = 🧹
EMOJI_CHECK = ✅
EMOJI_CROSS = ❌
EMOJI_WRENCH = 🔧
EMOJI_BOX = 📦
