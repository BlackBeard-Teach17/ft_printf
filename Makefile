# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kmfoloe <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/27 08:56:27 by kmfoloe           #+#    #+#              #
#    Updated: 2018/08/11 15:09:24 by kmfoloe          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
FLAGS = -Wall -Wextra -Werror
AR = ar rc
NAME = libftprintf.a
HEADER = ft_printf.h
FILES = ft_printf.c ft_conversions.c get_mods.c print.c set.c ft_error_handling.c maxstrlen.c \
	get_length_spec.c maxnbrlen.c ft_get_flags.c set_base.c \
	convert_int.c convert_unsigned_int.c print_str.c print_nbr.c print_base.c \
	ft_memalloc.c ft_memdel.c ft_bzero.c \
	ft_strnew.c ft_strlen.c ft_strindex.c ft_strdup.c \
	ft_atoi.c ft_strcount.c \
	ft_putwchar.c ft_putwstr.c ft_wstrlen.c ft_wcharlen.c \
	ft_putnstr.c ft_putnchar.c ft_putchar.c \
	ft_isdigit.c ft_isupper.c ft_itoa_base.c ft_itoa.c ft_uitoa_base.c ft_nbrlen.c \
	
OBJ = $(FILES:.c=.o)
TMP = Makefile~  $(F_DIR)/header.h~ $(NAME)~ $(FILES:.c=.c~)

all : $(NAME)

$(NAME) :
	@echo Project : $(NAME)
	@echo "\t"- Compiler : $(CC)
	@echo "\t"- Flags : $(FLAGS)
	@$(CC) $(FLAGS) -c $(FILES) 
	@$(AR) $(NAME) $(OBJ)
	@ranlib $(NAME)

clean :
	@echo clean :"\n\t files deleted"
	@rm -f $(TMP) $(OBJ)

fclean : clean
	@echo fclean :"\n\t" $(NAME) deleted
	@rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
