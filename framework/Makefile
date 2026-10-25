# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/25 20:49:07 by mmichele          #+#    #+#              #
#    Updated: 2026/10/24 20:55:09 by mmichele         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= cc
FLGS	= -Wall -Wextra -Werror -g

BLDD	= build
LIBD	= ../libft

INCS	= -I . -I $(LIBD)
LNKS	= -L $(LIBD)
LIBS	= -lunit -lft

# Mandatory 
NAME	= libunit.a
SRCS	= unit_test.c exec_test.c print_res.c child_proc.c
OBJS	= $(patsubst %.c, $(BLDD)/%.o, $(SRCS))
DEPS	= $(OBJS:.o=.d)

all: lib $(NAME)

lib:
	@ $(MAKE) -C $(LIBD) --no-print-directory

$(NAME): $(OBJS)
	ar rcs $@ $^

# Bonus
BONUS_NAME	= libunit_bonus.a
BONUS_SRCS 	= unit_test.c exec_test_bonus.c print_res_bonus.c child_proc_bonus.c
BONUS_OBJS	= $(patsubst %.c, $(BLDD)/%.o, $(BONUS_SRCS))
BONUS_DEPS	= $(BONUS_OBJS:.o=.d)

bonus: FLGS += -D BONUS
bonus: lib $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJS)
	ar rcs $@ $^
	cp $@ $(NAME)

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
	rm -rf $(BONUS_NAME)

re: fclean all

.PHONY: clean fclean re norm lib bonus
