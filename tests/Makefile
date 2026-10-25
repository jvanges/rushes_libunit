# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/10/24 01:13:27 by mmichele          #+#    #+#              #
#    Updated: 2026/10/25 12:59:13 by mmichele         ###   ########.fr        #
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
		mandatory/00_launcher.c \
		mandatory/01_ok_test.c \
		mandatory/02_ko_test.c \
		mandatory/03_sigsegv_test.c \
		mandatory/04_sigbus_test.c
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
BONUS_SRCS 	= main_bonus.c \
			mandatory/00_launcher.c \
			mandatory/01_ok_test.c \
			mandatory/02_ko_test.c \
			mandatory/03_sigsegv_test.c \
			mandatory/04_sigbus_test.c \
			bonus/00_launcher.c \
			bonus/01_sigabrt_test.c \
			bonus/02_sigfpe_test.c \
			bonus/03_sigpipe_test.c \
			bonus/04_sigill_test.c
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
	@ $(MAKE) -C $(LIBD) fclean --no-print-directory

re: fclean all

test: all
	@ ./$(NAME)

.PHONY: clean fclean re norm lib lib-bonus san test
