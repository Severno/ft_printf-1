# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dhojt <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/25 19:05:31 by dhojt             #+#    #+#              #
#    Updated: 2018/04/29 21:03:45 by dhojt            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		libftprintf.a
LIBFT_A =	libft.a

COMP =		gcc -Wall -Werror -Wextra $(PRINTF_H) $(LIBFT_H) -c

PRINTF_H =	-I includes/
LIBFT_H = 	-I srcs/libft/includes

LIB_DIR =	srcs/libft/

CFILE =		srcs/ft_printf.c \
			srcs/treatment.c \
			srcs/initialize.c \
			srcs/reinitialize.c \
			srcs/parser.c \
			srcs/parse_convert.c \
			srcs/parse_field_width.c \
			srcs/parse_precision.c \
			srcs/parse_arguments.c \
			srcs/parse_specifier.c \
			srcs/switch_display.c \
			srcs/display_d.c \
			srcs/display_c.c \
			srcs/display_s.c \
			srcs/display_u.c \
			srcs/display_x.c \
			srcs/display_o.c \
			srcs/display_p.c \
			srcs/display_ws.c \
			srcs/display_gap.c \
			srcs/display_wchar.c \
			srcs/display_other.c

OFILE =		ft_printf.o \
			treatment.o \
			initialize.o \
			reinitialize.o \
			parser.o \
			parse_convert.o \
			parse_field_width.o \
			parse_precision.o \
			parse_arguments.o \
			parse_specifier.o \
			switch_display.o \
			display_d.o \
			display_c.o \
			display_s.o \
			display_u.o \
			display_x.o \
			display_o.o \
			display_p.o \
			display_ws.o \
			display_gap.o \
			display_wchar.o \
			display_other.o

all: $(NAME)

$(NAME): $(OFILE)
		@make -C $(LIB_DIR)
		@cp $(LIB_DIR)$(LIBFT_A) .
		@mv $(LIBFT_A) $(NAME)
		@ar rc $(NAME) $(OFILE)
		@ranlib $(NAME)

$(OFILE):
		@$(COMP) $(CFILE)

clean:
		@/bin/rm -rf *.o
		@make -C $(LIB_DIR) fclean

fclean: clean
		@/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean flcean re
