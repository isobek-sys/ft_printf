# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: blukasho <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/31 12:56:17 by blukasho          #+#    #+#              #
#*   Updated: 2019/02/20 10:08:11 by blukasho         ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

SRCS = ft_bzero.c ft_memcpy.c ft_memset.c ft_memccpy.c ft_memmove.c \
	   ft_memchr.c ft_memcmp.c ft_strlen.c ft_strdup.c ft_strcpy.c \
	   ft_strncpy.c ft_strcat.c ft_strncat.c ft_strlcat.c ft_strchr.c\
	   ft_strrchr.c ft_strcmp.c ft_strstr.c ft_strncmp.c ft_strnstr.c\
	   ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c\
	   ft_isprint.c ft_toupper.c ft_tolower.c ft_memalloc.c ft_memdel.c\
	   ft_strnew.c ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c\
	   ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c\
	   ft_strjoin.c ft_strtrim.c ft_strsplit.c ft_itoa.c ft_putchar.c\
	   ft_putstr.c ft_putendl.c ft_putnbr.c ft_putchar_fd.c ft_putstr_fd.c\
	   ft_putendl_fd.c ft_putnbr_fd.c ft_count_words.c ft_lstnew.c\
	   ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c\
	   ft_strndup.c ft_get_arr.c ft_is_lower.c ft_is_upper.c ft_is_space.c\
	   get_next_line.c ft_strlen_chr.c ft_printf.c ft_printf_parser.c\
	   parse_flags.c result_preparation.c print_char.c print_pointer.c\
	   print_digits.c print_octal.c additional_functions.c\
	   print_unsigned_digits.c print_hexdecimal.c print_double.c\
	   print_percent.c print_string.c main_function.c check_errors.c\

vpath %.c srcs srcs/ft_printf

OBJ = $(SRCS:.c=.o)

FLAGS = -Wall -Wextra -I includes

NAME = libftprintf.a

printf: $(NAME)
	gcc $(FLAGS) main.c -o ft_printf -L . -lftprintf
	@echo "\033[6;32m<---------------done-------------->\033[0m"
	@./ft_printf | cat -e

all: $(NAME)

$(NAME): $(OBJ)
	ar -rv $(NAME) $^
	ranlib $(NAME)

$(OBJ): %.o: %.c
	gcc -c $(FLAGS) $< -o $@

clean: 
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)
	rm -rf ft_printf

re:	fclean all

.PHONY: all clean fclean re
