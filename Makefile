# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpadenko <dpadenko@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/28 14:00:45 by dpadenko          #+#    #+#              #
#    Updated: 2023/12/20 11:53:37 by dpadenko         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra
NAME = push_swap

LIBDIR = ./libft
#PRINTFDIR = ./printf
LIBFT = ${LIBDIR}/libft.a
#PRINTF = ${PRINTFDIR}/libftprintf.a

SRC = positioning.c push.c rotate.c reverse_rotate.c swap.c \
		build_list.c main.c prebuild_controls.c \
		cost_calculation.c return_algorithm.c set_cost.c sort_stack.c \
		sort_aux.c

OBJ = ${SRC:.c=.o}

all: ${NAME}

%.o: %.c
#		${CC} ${CFLAGS} -o $@ -c $< -I . -I $(PRINTFDIR)
		${CC} ${CFLAGS} -o $@ -c $< -I .

${NAME}: ${LIBFT} ${PRINTF} ${OBJ}
#		${CC} ${CFLAGS} ${OBJ} -L${LIBDIR} -lft -L${PRINTFDIR} -lftprintf -o ${NAME}
		${CC} ${CFLAGS} ${OBJ} -L${LIBDIR} -lft -o ${NAME}
${LIBFT}:
		${MAKE} -C ${LIBDIR} all

#${PRINTF}:
#		${MAKE} -C ${PRINTFDIR} all

.PHONY: clean fclean all re

clean:
		${MAKE} -C ${LIBDIR} clean
#		${MAKE} -C ${PRINTFDIR} clean
		rm -f ${OBJ} ${OBJ_B}

fclean: clean
		${MAKE} -C ${LIBDIR} fclean
#		${MAKE} -C ${PRINTFDIR} fclean
		rm -rf ${NAME}

re: fclean all