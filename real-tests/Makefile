# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/10/24 01:13:27 by mmichele          #+#    #+#              #
#    Updated: 2026/10/24 21:04:36 by mmichele         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= cc
FLGS	= -Wall -Wextra -Werror -g

BLDD	= build
LIBD	= ../framework
LIBFT	= ../libft

INCS	= -I . -I $(LIBD) -I $(LIBFT)
LNKS	= -L $(LIBD) -L $(LIBFT)
LIBS	= -lunit -lft

# Mandatory
NAME	= tests
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
DEPS	= $(OBJS:.o=.d)

all: lib $(NAME)

lib:
	@ $(MAKE) -C $(LIBFT) --no-print-directory
	@ $(MAKE) -C $(LIBD) --no-print-directory

$(NAME): $(OBJS)
	$(CC) $(FLGS) $^ -o $@ $(INCS) $(LNKS) $(LIBS)

# Bonus
BONUS_NAME	= tests_bonus
BONUS_SRCS 	= $(SRCS)
BONUS_OBJS	= $(patsubst %.c, $(BLDD)/%.o, $(BONUS_SRCS))
BONUS_DEPS	= $(BONUS_OBJS:.o=.d)

lib-bonus:
	@ $(MAKE) -C $(LIBFT) --no-print-directory
	@ $(MAKE) -C $(LIBD) bonus --no-print-directory

bonus: FLGS += -D BONUS
bonus: lib-bonus $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJS)
	$(CC) $(FLGS) $^ -o $@ $(INCS) $(LNKS) $(LIBS)
	@ cp $@ $(NAME)

# Common
$(BLDD)/%.o: %.c
	@ mkdir -p $(@D)
	$(CC) $(FLGS) -MMD -c $< -o $@ $(INCS)

-include $(DEPS)
-include $(BONUS_DEPS)

clean:
	rm -rf $(BLDD)

fclean: clean
	rm -rf $(NAME)

re: fclean all

test: all
	@ ./$(NAME)

.PHONY: clean fclean re norm lib lib-bonus san test

