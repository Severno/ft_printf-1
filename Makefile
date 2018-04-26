# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dhojt <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/25 19:05:31 by dhojt             #+#    #+#              #
#    Updated: 2018/04/26 03:32:47 by dhojt            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		libftprintf.a
LIBFT_A =	srcs/libft/libft.a

PRINTF_H =	-I includes/
LIBFT_H = 	-I srcs/libft/includes

PAR_DIR	=	srcs/parse/
DIS_DIR =	srcs/display/
OBJ_DIR =	objs/

PARSE =		ft_printf.c \
			treatment.c \
			initialize.c \
			reinitialize.c \
			parser.c \
			parse_converter_flags.c \
			parse_field_width.c \
			parse_precision.c \
			parse_arguments.c \
			parse_specifier.c \
			switch_display.c

DISPLAY =	display_d.c \
			display_c.c \
			display_s.c \
			display_u.c \
			display_x.c \
			display_o.c \
			display_p.c \
			display_other.c \
			display_gap.c


COMP = gcc -c

all:
	make -C libft/
	$(CC) $(SOURCES) $(DISPLAY) $(LIBFT_H)
	ar rc $(NAME) *.o libft/obj/*.o
	ranlib $(NAME)


clean:
	make -C libft/ clean
	/bin/rm -rf *.o
	/bin/rm -rf *.a

fclean: clean
	make -C libft/ fclean
	rm -rf a.out

re: fclean all

#DO .PHONY
