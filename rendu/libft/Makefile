# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/06 11:47:48 by abarthel          #+#    #+#              #
#    Updated: 2019/02/07 16:27:01 by abarthel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# To compile with the libft.a, use the command-line: gcc main.c -L. -lft or add it to makefile

NAME = libft.a

CC = gcc

FLAGS = -Werror -Wall -Wextra

%.o : %.c
	@$(CC) $(FLAGS) $< -c $(DEBUG)
	@printf "\e[38;5;74m%-20s \e[38;5;85mobject built\n\e[0m" $(basename $@)

O_FILES	=	ft_bzero.o ft_isalpha.o ft_isdigit.o ft_isalnum.o \
	   		ft_isascii.o ft_isprint.o ft_toupper.o ft_tolower.o \
	   		ft_atoi.o ft_strcmp.o ft_strncmp.o ft_memcmp.o ft_strlen.o \
	   		ft_strlcat.o ft_memset.o ft_memcpy.o ft_memccpy.o \
	   		ft_memmove.o ft_memchr.o ft_strstr.o ft_strcat.o ft_strncat.o \
	   		ft_strcpy.o ft_strncpy.o ft_strdup.o ft_strnstr.o ft_strchr.o \
			ft_strrchr.o ft_memdel.o ft_strdel.o ft_strclr.o ft_striter.o \
	 		ft_striteri.o ft_putchar.o ft_putstr.o ft_putendl.o \
	 		ft_putnbr.o ft_putchar_fd.o ft_putstr_fd.o ft_putendl_fd.o \
			ft_putnbr_fd.o ft_strequ.o ft_strnequ.o ft_memalloc.o \
	 		ft_strnew.o ft_strmap.o ft_strmapi.o ft_strsub.o ft_strjoin.o \
	 		ft_strtrim.o ft_itoa.o ft_strsplit.o ft_lstdelone.o	ft_lstdel.o \
			ft_lstadd.o ft_lstiter.o ft_lstnew.o ft_lstmap.o ft_print_tables.o \
		 	ft_str_is_alpha.o ft_str_is_numeric.o ft_str_is_printable.o \
		 	ft_str_is_lowercase.o ft_str_is_uppercase.o ft_isprime.o \
	   		ft_fprintbits.o get_next_line.o ft_isempty.o ft_strclen.o \
			ft_chrsearch.o ft_strndup.o

all: $(NAME)

$(NAME): $(O_FILES)
	@ar rc $(NAME) $(O_FILES)
	@ranlib $(NAME)
	@printf "\n\e[38;5;82m%4s [\e[1m$(NAME) built]\n\n\e[0m"
	@printf "\e[38;5;25mTo compile with the $(NAME), use the command-line: \e[0m\e[4mgcc main.c -L. -lft\n\e[0m"

clean:
	@rm -f $(O_FILES)
	@printf "\e[0m$(NAME) .o \e[38;5;154mfiles%1sdeleted ♻\n\e[0m"

fclean: clean
	@rm -f $(NAME)
	@printf "\e[0m$(NAME)\e[38;5;154m%2sdeleted ❌\n\e[0m"

re: fclean $(NAME)

# Objects rule to be used when building larger libraries
objects: $(O_FILES)

.PHONY : all clean fclean re objects
