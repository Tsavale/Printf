# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tsavale <tsavale@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/31 18:34:32 by tsavale           #+#    #+#              #
#    Updated: 2020/12/31 18:34:35 by tsavale          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCSC		= ft_printf.c\
				ft_check_syntax.c\
				ft_conversion.c\
				ft_flags.c\
				ft_symbole.c

SRCSH		= ft_printf.h

OBJS		= $(SRCSC:%.c=%.o)

LIBFTDIR	= libft

LIBFT		= libft.a

NAME		= libftprintf.a

CC			= gcc

AR			= ar -rc

RM			= rm -f

CFLAGS		= -Wall -Wextra -Werror

$(NAME):	${OBJS} ${LIBFT}
			${AR} ${NAME} ${OBJS} ${SRCSH} ${LIBFTDIR}/*.o


$(LIBFT):
			cd ${LIBFTDIR} && make $@

all:		${NAME}

clean:
			${RM} ${OBJS}
			cd ${LIBFTDIR} && make $@

fclean:		clean
			${RM} ${NAME}
			cd ${LIBFTDIR} && make $@

re:			fclean all

bonus:		all

test:		re
			@${CC} main.c ${NAME}
			make clean
			@echo "\n================" 
			@./a.out
			@echo "\n================" 


.PHONY:		all clean fclean re
