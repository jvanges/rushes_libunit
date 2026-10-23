# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/25 20:49:07 by mmichele          #+#    #+#              #
#    Updated: 2026/10/24 01:32:19 by mmichele         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= cc
FLGS	= -Wall -Wextra -Werror

NAME	= libunit.a
BLDD	= build

SRCS	= unit_test.c
OBJS	= $(patsubst %.c, $(BLDD)/%.o, $(SRCS))
INCS	= -I .
DEPS	= $(OBJS:.o=.d)

BONUS_SRCS 	= 
BONUS_OBJS	= $(patsubst %.c, $(BLDD)/%.o, $(BONUS_SRCS))

.PHONY: clean fclean re norm

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $@ $^

bonus: $(OBJS) $(BONUS_OBJS)
	ar rcs $(NAME) $^

san: FLGS += -g -fsanitize=address,leak,undefined
san: bonus

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
	norminette *.c *.h

