# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pscott <pscott@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/02 18:02:03 by pscott            #+#    #+#              #
#    Updated: 2018/12/02 22:36:54 by pscott           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libunit_test
FLAGS = -Wall -Werror -Wextra

FRAMEWORK_PATH = ../framework


LIB_UNIT_DIR = ../framework
LIB_UNIT = -L $(LIB_UNIT_DIR) -lunit

LIB_FW_DIR = $(FRAMEWORK_PATH)/libfw
LIB_FW = -L $(LIB_FW_DIR) -lfw

INCLUDES = -I $(FRAMEWORK_PATH)/includes
SRCS = $(shell find . -type f -name "*.c")

OBJS= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(LIB_UNIT_DIR)
	@gcc $(FLAGS) $(INCLUDES) $(LIB_UNIT) $(LIB_FW) -o $(NAME) $(OBJS)

test: $(NAME)
	@gcc $(FLAGS) $(INCLUDES) $(LIB_UNIT) $(LIB_FW) -o $(NAME) $(OBJS)
	@./$(NAME) || true

%.o: %.c
	gcc $(FLAGS) $(INCLUDES) -o $@ -c $<

clean:
	rm -f $(OBJS)
	make -C $(LIB_UNIT_DIR) clean


fclean: clean
	rm -f $(NAME)
	make -C $(LIB_UNIT_DIR) fclean


re: fclean all

.PHONY: fclean all clean
