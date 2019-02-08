# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/22 16:55:38 by abarthel          #+#    #+#              #
#    Updated: 2019/02/08 16:02:09 by abarthel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	libunit.a

#FLAGS			= 	-Wall -Werror -Wextra

FRAMEWORK_PATH	=	.

INCLUDES		=	-I $(FRAMEWORK_PATH)

SRC				=	framework.c format.c processes.c init.c void_function_tests.c libtools.c

SRCS			=	$(addprefix $(FRAMEWORK_PATH)/, $(SRC))

OBJS			=	$(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@printf "\e[38;5;231mLi\e[38;5;230mbu\e[38;5;223mnit frammewo\e[38;5;230mrk\e[38;5;231m built\n\e[0m"

%.o: %.c
	@gcc $(FLAGS) $(INCLUDES) -o $@ -c $<


clean:
	@rm -f $(OBJS)

fclean:	clean
	@rm -f $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
