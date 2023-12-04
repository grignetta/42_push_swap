# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpadenko <dpadenko@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/04 11:32:55 by dpadenko          #+#    #+#              #
#    Updated: 2023/12/04 12:22:34 by dpadenko         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpadenko <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/28 14:00:45 by dpadenko          #+#    #+#              #
#    Updated: 2023/09/28 14:01:19 by dpadenko         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra
NAME = push_swap

LIBDIR = ./libft
LIBFT = ${LIBDIR}/libft.a

SRC = first_trial.c ft_strtok.c push.c rotate.c reverse_rotate.c swap.c

OBJ = ${SRC:.c=.o}

%.o: %.c
		${CC} ${CFLAGS} -o $@ -c $< -I .

${NAME}: ${LIBFT} ${OBJ}
		cp ${LIBFT} ${NAME}
		ar -rcs $@ ${OBJ}
		${CC} ${CFLAGS} -L${LIBDIR} -lft ${OBJ} -o ${NAME}

${LIBFT}:
		${MAKE} -C ${LIBDIR} all

all: ${NAME}

.PHONY: clean fclean all re

clean:
		${MAKE} -C ${LIBDIR} clean
		rm -f ${OBJ} ${OBJ_B}

fclean: clean
		${MAKE} -C ${LIBDIR} fclean
		rm -rf ${NAME}

re: fclean all