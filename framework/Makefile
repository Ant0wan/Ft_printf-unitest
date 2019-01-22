# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/22 16:55:38 by abarthel          #+#    #+#              #
#    Updated: 2019/01/22 16:57:13 by abarthel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	libunit.a

FLAGS			= 	-Wall -Werror -Wextra

FRAMEWORK_PATH	=	.

INCLUDES		=	-I $(FRAMEWORK_PATH)

SRC				=	framework.c format.c processes.c init.c void_function_tests.c

SRCS			=	$(addprefix $(FRAMEWORK_PATH)/, $(SRC))

OBJS			=	$(SRCS:.c=.o)

all				:	$(NAME)

$(NAME)			:	$(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

%.o				:	%.c
	gcc $(FLAGS) $(INCLUDES) -o $@ -c $<

clean			:
	rm -f $(OBJS)

fclean			:	clean
	rm -f $(NAME)

re				:	fclean all

.PHONY			:	all clean fclean re
