# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aperraul <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/27 15:26:56 by aperraul          #+#    #+#              #
#    Updated: 2016/06/14 11:02:54 by aperraul         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libgraph.a

SRCS = ft_make_3dpt.c \
	   ft_make_line.c \
	   ft_make_pt.c \
	   ft_make_vector.c \
	   ft_init_matrix.c \
	   ft_apply_matrix.c \
	   ft_multiply_matrix.c \
	   make_matrix.c \
	   rgb_hexa_convert.c \
	   ft_make_ptll.c \

OBJS = ft_make_3dpt.o \
	   ft_make_line.o \
	   ft_make_pt.o \
	   ft_make_vector.o \
	   ft_init_matrix.o \
	   ft_apply_matrix.o \
	   ft_multiply_matrix.o \
	   make_matrix.o \
	   rgb_hexa_convert.o \
	   ft_make_ptll.o \

FLAGS = -Wall -Wextra -Werror

CC = gcc

RM = rm -f

all: $(NAME)

$(NAME) : $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

$(OBJS) :
	$(CC) $(FLAGS) -c $(SRCS)

clean :
		$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME) $(LIBFT) $(LIBMLX)

re: fclean all
