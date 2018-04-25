# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dhojt <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/25 19:05:31 by dhojt             #+#    #+#              #
#    Updated: 2018/04/25 20:59:37 by dhojt            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		libftprintf.a

SOURCES =	parser.c \
			treatment.c \
			initialize.c \
			reinitialize.c \
			parse_converter_flags.c \
			ft_printf.c \
			parse_field_width.c \
			parse_precision.c \
			double_percent.c \
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
			display_percent.c \
			display_gap.c

INCLUDES =	printf.h

LIBFT_A =	libft/libft.a
LIBFT_H = 	-I libft/includes

CC = gcc -c

all:
	make -C libft/
	$(CC) $(SOURCES) $(DISPLAY) $(LIBFT_H) ft_printf.h
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
