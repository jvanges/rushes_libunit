# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/25 20:49:07 by mmichele          #+#    #+#              #
#    Updated: 2026/10/23 22:22:35 by mmichele         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= cc
FLGS	= -Wall -Wextra -Werror

BLDD	= build

NAME	= libunit.a
SRCS	= unit_test.c
OBJS	= $(patsubst %.c, $(BLDD)/%.o, $(SRCS))

BONUS_SRCS 	= 
BONUS_OBJS	= $(patsubst %.c, $(BLDD)/%.o, $(BONUS_SRCS))

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $@ $^

bonus: $(OBJS) $(BONUS_OBJS)
	ar rcs $(NAME) $^

san: FLGS += -g -fsanitize=address,leak,undefined
san: bonus

$(BLDD)/%.o: %.c
	@ mkdir -p $(BLDD)
	$(CC) $(FLGS) -c $^ -o $@

clean:
	rm -rf $(BLDD)

fclean: clean
	rm -rf $(NAME)

re: fclean all

norm:
	norminette *.c *.h

.PHONY: clean fclean re norm
