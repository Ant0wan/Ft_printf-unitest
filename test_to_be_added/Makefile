# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pscott <pscott@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/02 18:02:03 by pscott            #+#    #+#              #
#    Updated: 2019/02/12 14:11:01 by abarthel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libunit_test
FLAGS = -Werror -Wall -Wextra

FRAMEWORK_PATH = ../framework

RENDU_PATH = ../rendu
LIB_RENDU = -L $(RENDU_PATH) -lftprintf

LIB_UNIT_DIR = ../framework
LIB_UNIT = -L $(LIB_UNIT_DIR) -lunit

INCLUDES = -I $(FRAMEWORK_PATH)
SRCS = $(shell find . -type f -name "*.c")

OBJS= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(RENDU_PATH)
	@make -C $(LIB_UNIT_DIR)
	@gcc $(FLAGS) $(INCLUDES) $(LIB_UNIT) $(LIB_RENDU) -o $(NAME) $(OBJS)
#	@gcc $(INCLUDES) $(LIB_UNIT) -o $(NAME) $(OBJS)
	@printf "\e[38;5;51mFt\e[38;5;50m_\e[38;5;49mpr\e[38;5;48min\e[38;5;47mtf\e[38;5;46m te\e[38;5;47mst\e[38;5;48ms r\e[38;5;49mea\e[38;5;50mdy\e[0m\n"

test: $(NAME)
#	@gcc $(INCLUDES) $(LIB_UNIT) $(LIB_RENDU) -o $(NAME) $(OBJS)
	@gcc $(FLAGS) $(INCLUDES) $(LIB_UNIT) $(LIB_RENDU) -o $(NAME) $(OBJS)
	@./$(NAME) || true

%.o: %.c
#	@gcc $(FLAGS) $(INCLUDES) -o $@ -c $<
	@gcc $(INCLUDES) -o $@ -c $<

clean:
	@make -C $(RENDU_PATH) clean
	@make -C $(LIB_UNIT_DIR) clean
	@rm -f $(OBJS)
	@printf "\e[38;5;51mFt_\e[38;5;50mpri\e[38;5;49mntf\e[38;5;48m tes\e[38;5;47mts \e[0m.o\e[38;5;47m f\e[38;5;46mile\e[38;5;47ms de\e[38;5;48mlet\e[38;5;49med\e[0m\n"

fclean:
	@make -C $(RENDU_PATH) fclean
	@make -C $(LIB_UNIT_DIR) fclean
	@rm -f $(OBJS)
	@printf "\e[38;5;51mFt_\e[38;5;50mpri\e[38;5;49mntf\e[38;5;48m tes\e[38;5;47mts \e[0m.o\e[38;5;47m f\e[38;5;46mile\e[38;5;47ms de\e[38;5;48mlet\e[38;5;49med\e[0m\n"
	@rm -f $(NAME)
	@printf "\e[38;5;51mFt_\e[38;5;50mpri\e[38;5;49mntf\e[38;5;48m tes\e[38;5;47mts \e[0m.a\e[38;5;48m de\e[38;5;49mlet\e[38;5;50med\e[0m\n"

re: fclean all

.PHONY: fclean all clean re test
