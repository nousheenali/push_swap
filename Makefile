# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nali <nali@42abudhabi.ae>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/27 10:33:53 by nali              #+#    #+#              #
#    Updated: 2022/02/17 12:25:54 by nali             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= pushswap.a

LIBFT	= libft

SRCS	= main.c push_swap.c  input_check_store.c small_sorting.c stack_operations.c\
		operations.c push_swap_utils.c small_sorting_utils.c big_sorting.c \
		big_sorting_utils.c big_sorting_utils_two.c sorting_algo.c checker.c\
		operations_two.c checker_utils.c get_next_line.c get_next_line_utils.c\
		big_sorting_five_hundred.c input_string_processing.c 

SRCS_B	= checker.c push_swap.c  input_check_store.c small_sorting.c stack_operations.c\
		operations.c push_swap_utils.c small_sorting_utils.c big_sorting.c \
		big_sorting_utils.c big_sorting_utils_two.c sorting_algo.c checker.c\
		operations_two.c checker_utils.c get_next_line.c get_next_line_utils.c\
		big_sorting_five_hundred.c input_string_processing.c 

OBJS	= ${SRCS:.c=.o}

OBJS_B	= ${SRCS_B:.c=.o}

CC		= gcc

CFLAGS	= -Wall -Werror -Wextra

RM		= rm -f

all:	${NAME}

.c.o:	${CC} ${CFLAGS} -I -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			make -C ${LIBFT}
			cp libft/libft.a ./${NAME}
			ar rc ${NAME} ${OBJS}
			ranlib ${NAME}
			${CC} main.c -L. ${NAME} -o push_swap
			
bonus:		${OBJS_B}
			make -C ${LIBFT}
			cp libft/libft.a ./${NAME}
			ar rc ${NAME} ${OBJS_B}
			ranlib ${NAME}
			${CC} checker.c -L. ${NAME} -o checker
clean:		
			${RM} ${OBJS} ${OBJS_B}
			make clean -C ${LIBFT}

fclean:		clean
			${RM} ${NAME}
			${RM} ${LIBFT}/libft.a
			${RM} push_swap checker

re:			fclean all

.PHONY:		all clean fclean re .c.o
