# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/10/24 01:13:27 by mmichele          #+#    #+#              #
#    Updated: 2026/10/24 12:02:50 by mmichele         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= cc
FLGS	= -Wall -Wextra -Werror -g

NAME	= tests
BLDD	= build
LIBD	= ../framework
LIBFT	= ../libft

SRCS	= main.c \
		libunit/00_launcher.c \
		libunit/01_ok_test.c \
		libunit/02_ko_test.c \
		libunit/03_sigsegv_test.c \
		libunit/04_sigbus_test.c
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
