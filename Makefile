# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fgaribot <fgaribot@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/10 09:32:48 by fgaribot          #+#    #+#              #
#    Updated: 2019/11/05 20:30:45 by fgaribot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = checker
NAME1 = push_swap
HEADER = ./includes/checker.h
CC = gcc
CFLAGS = -Wall -Werror -Wextra
LIBFT_DIR = ./srcs/libft/
LIB = $(LIBFT_DIR)libft.a
SRC = ./srcs/
FILES = $(SRC)pushs.c\
		$(SRC)swaps.c\
		$(SRC)rotate.c\
		$(SRC)reverse_rotate.c\
		$(SRC)checker_tests.c\
		$(SRC)checker_exits.c\
		$(SRC)parsing.c\
		$(SRC)checker.c

FILES_Push_Swap =	$(SRC)operate_pushs_sa.c\
					$(SRC)operate_reverse_rotates.c\
					$(SRC)operate_rotates.c\
					$(SRC)print_lists.c\
					$(SRC)list_3.c\
					$(SRC)list_5.c\
					$(SRC)extrema_ps.c\
					$(SRC)exec_operations.c\
					$(SRC)correct_place.c\
					$(SRC)correct_place_on_b.c\
					$(SRC)clear_leaks.c\
					$(SRC)best_combination.c\
					$(SRC)merge_total_operations.c\
					$(SRC)push_swap.c

OBJ= $(FILES:.c=.o)

OBJ_need_in_both=	$(SRC)rotate.o\
					$(SRC)reverse_rotate.o\
					$(SRC)parsing.o\
					$(SRC)pushs.o\
					$(SRC)swaps.o\
					$(SRC)checker_exits.o\
					$(SRC)checker_tests.o

OBJ_Push_Swap= $(FILES_Push_Swap:.c=.o)

all : $(NAME) $(NAME1)

%.o: %.c $(HEADER)
	@$(CC) $(CFLAGS) -c $< -o $@

$(LIB) : FORCE
	@make -C srcs/libft/

$(NAME) : $(OBJ) $(LIB)
	$(CC) -o $@ $(OBJ) ./srcs/libft/libft.a

$(NAME1) : $(OBJ_Push_Swap) $(OBJ_need_in_both) $(LIB)
	$(CC) -o $@ $(OBJ_Push_Swap) $(OBJ_need_in_both) ./srcs/libft/libft.a

clean :
	@(cd $(LIBFT_DIR) && $(MAKE) $@)
	rm -f $(OBJ) $(OBJ_Push_Swap)

fclean: clean
	@(cd $(LIBFT_DIR) && $(MAKE) $@)
	rm -f $(NAME) $(NAME1)

FORCE :

re: fclean all
