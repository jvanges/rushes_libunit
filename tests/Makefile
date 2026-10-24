# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/10/24 01:13:27 by mmichele          #+#    #+#              #
#    Updated: 2026/10/24 01:58:36 by mmichele         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= cc
FLGS	= -Wall -Wextra -Werror -g

NAME	= tests
BLDD	= build
LIBD	= ../framework

SRCS	= main.c
OBJS	= $(patsubst %.c, $(BLDD)/%.o, $(SRCS))
INCS	= -I . -I $(LIBD)
LNKS	= -L $(LIBD)
LIBS	= -lunit
DEPS	= $(OBJS:.o=.d)

.PHONY: clean fclean re norm lib san

all: lib $(NAME)

lib:
	$(MAKE) -C $(LIBD) --no-print-directory

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
	$(MAKE) -C $(LIBD) $@

re: fclean all

norm:
	norminette

san: FLGS += -g -fsanitize=address,leak,undefined
san: all
