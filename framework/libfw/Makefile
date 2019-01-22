# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abarthel <abarthel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/06 11:47:48 by abarthel          #+#    #+#              #
#    Updated: 2018/12/01 15:41:44 by abarthel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# To compile with the libft.a, use the command-line: gcc main.c -L. -lfw

NAME = libfw.a

CC = gcc

CFLAGS = -Werror -Wall -Wextra -I $(INCLUDES_PATH)

SRCS = $(LIBC) $(FW) $(LISTS) $(OTHERS)

INCLUDES_PATH = ../includes/

INCLUDES = $(INCLUDES_PATH)libfw.h

OBJ = $(SRCS:.c=.o)

LIBC = fw_bzero.c \
	   fw_isalpha.c \
	   fw_isdigit.c \
	   fw_isalnum.c \
	   fw_isascii.c \
	   fw_isprint.c \
	   fw_toupper.c \
	   fw_tolower.c \
	   fw_atoi.c \
	   fw_strcmp.c \
	   fw_strncmp.c \
	   fw_memcmp.c \
	   fw_strlen.c \
	   fw_strlcat.c \
	   fw_memset.c \
	   fw_memcpy.c \
	   fw_memccpy.c \
	   fw_memmove.c\
	   fw_memchr.c \
	   fw_strstr.c \
	   fw_strcat.c \
	   fw_strncat.c \
	   fw_strcpy.c \
	   fw_strncpy.c \
	   fw_strdup.c \
	   fw_strnstr.c \
	   fw_strchr.c \
	   fw_strrchr.c

FW = fw_memdel.c \
	 fw_strdel.c \
	 fw_strclr.c \
	 fw_striter.c \
	 fw_striteri.c \
	 fw_putchar.c \
	 fw_putstr.c \
	 fw_putendl.c \
	 fw_putnbr.c \
	 fw_putchar_fd.c \
	 fw_putstr_fd.c \
	 fw_putendl_fd.c \
	 fw_putnbr_fd.c \
	 fw_strequ.c \
	 fw_strnequ.c \
	 fw_memalloc.c \
	 fw_strnew.c \
	 fw_strmap.c \
	 fw_strmapi.c \
	 fw_strsub.c \
	 fw_strjoin.c \
	 fw_strtrim.c \
	 fw_itoa.c \
	 fw_strsplit.c

LISTS = fw_lstdelone.c \
		fw_lstdel.c \
		fw_lstadd.c \
		fw_lstiter.c \
		fw_lstnew.c \
		fw_lstmap.c

OTHERS = fw_print_tables.c \
		 fw_str_is_alpha.c \
		 fw_str_is_numeric.c \
		 fw_str_is_printable.c \
		 fw_str_is_lowercase.c \
		 fw_str_is_uppercase.c \
		 fw_isprime.c

all: $(NAME)

$(NAME): $(INCLUDES) $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY: clean
