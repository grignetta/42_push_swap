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

CC       = cc
CFLAGS   = -Wall -Wextra -Werror -Iinclude -I$(LIBFT_INC)
NAME     = push_swap

# Libft (submodule)
LIBFT_DIR = libft
LIBFT_A   = $(LIBFT_DIR)/libft.a
LIBFT_INC = $(LIBFT_DIR)

SRCDIR   = src
OBJDIR   = obj

SRC = $(SRCDIR)/main.c \
      $(wildcard $(SRCDIR)/init/*.c) \
      $(wildcard $(SRCDIR)/ops/*.c)  \
      $(wildcard $(SRCDIR)/algo/*.c)

OBJ = $(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o,$(SRC))

all: $(NAME)

$(NAME): $(LIBFT_A) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -L$(LIBFT_DIR) -lft -o $@

$(LIBFT_A):
	$(MAKE) -C $(LIBFT_DIR) all

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -rf $(OBJDIR)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
