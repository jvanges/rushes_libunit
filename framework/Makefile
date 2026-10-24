# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/25 20:49:07 by mmichele          #+#    #+#              #
#    Updated: 2026/10/24 06:20:26 by mmichele         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= cc
FLGS	= -Wall -Wextra -Werror -g

BLDD	= build
LIBD	= ../libft

INCS	= -I . -I $(LIBD)
LNKS	= -L $(LIBD)
LIBS	= -lunit -lft
DEPS	= $(OBJS:.o=.d)

# Mandatory 

NAME	= libunit.a
SRCS	= unit_test.c exec_test.c print_res.c
OBJS	= $(patsubst %.c, $(BLDD)/%.o, $(SRCS))

all: lib $(NAME)

$(NAME): $(OBJS)
	ar rcs $@ $^

# Bonus

BONUS_NAME	= libunit_bonus.a
BONUS_SRCS 	= unit_test.c exec_test.c print_res_bonus.c
BONUS_OBJS	= $(patsubst %.c, $(BLDD)/%.o, $(BONUS_SRCS))

bonus: lib $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJS)
	ar rcs $@ $^
	cp $@ $(NAME)

# Common targets

$(BLDD)/%.o: %.c
	@ mkdir -p $(@D)
	$(CC) $(FLGS) -MMD -c $< -o $@ $(INCS)

-include $(DEPS)

clean:
	rm -rf $(BLDD)

fclean: clean
	rm -rf $(NAME)
	rm -rf $(BONUS_NAME)

re: fclean all

lib:
	@ $(MAKE) -C $(LIBD) --no-print-directory

norm:
	norminette

.PHONY: clean fclean re norm lib bonus
