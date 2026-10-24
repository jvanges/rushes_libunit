# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/10/24 01:13:27 by mmichele          #+#    #+#              #
#    Updated: 2026/10/24 14:55:02 by mmichele         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= cc
FLGS	= -Wall -Wextra -Werror -g

NAME	= tests
BLDD	= build
LIBD	= ../framework
LIBFT	= ../libft

SRCS	= main.c \
		strlen/00_launcher.c \
		strlen/01_basic_test.c \
		strlen/02_null_test.c \
		strlen/03_bigger_str_test.c \
		atoi/00_launcher.c \
		atoi/01_basic_test.c \
		atoi/02_whitespace_test.c \
		atoi/03_invalid_characters_test.c \
		atoi/04_limits_test.c \
		atoi/05_null_test.c
OBJS	= $(patsubst %.c, $(BLDD)/%.o, $(SRCS))
INCS	= -I . -I $(LIBD) -I $(LIBFT)
LNKS	= -L $(LIBD) -L $(LIBFT)
LIBS	= -lunit -lft
DEPS	= $(OBJS:.o=.d)

.PHONY: clean fclean re norm lib san test

all: lib $(NAME)

lib:
	@ $(MAKE) -C $(LIBFT) --no-print-directory
	@ $(MAKE) -C $(LIBD) --no-print-directory

$(NAME): $(OBJS)
	$(CC) $(FLGS) $^ -o $@ $(INCS) $(LNKS) $(LIBS)

$(BLDD)/%.o: %.c
	@ mkdir -p $(@D)
	$(CC) $(FLGS) -MMD -c $< -o $@ $(INCS)

-include $(DEPS)

clean:
	rm -rf $(BLDD)

fclean: clean
	rm -rf $(NAME)

re: fclean all

norm:
	norminette

san: FLGS += -g -fsanitize=address,leak,undefined
san: all

test: all
	@ ./$(NAME)
