# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rreedy <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/30 16:58:46 by rreedy            #+#    #+#              #
#    Updated: 2018/09/05 09:26:00 by rreedy           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= checker
PSWAP		:= pushswap
LIBFT		:= libftprintf
LIBSTACK	:= libstack

CHECK_OBJS	:= $(patsubst %.c,%.o,$(wildcard ./srcs/$(NAME)/*.c))
PSWAP_OBJS	:= $(patsubst %.c,%.o,$(wildcard ./srcs/$(PSWAP)/*.c))

PRINT_OBJS	:= $(patsubst %.c,%.o,$(wildcard ./$(LIBFT)/srcs/ft_printf/*.c))
LIBFT_OBJS	:= $(patsubst %.c,%.o,$(wildcard ./$(LIBFT)/srcs/*.c))
STACK_OBJS	:= $(patsubst %.c,%.o,$(wildcard ./$(LIBSTACK)/srcs/*.c))

CFLAGS		+= -Wall -Wextra -Werror -I./includes -I./$(LIBFT)/includes -I./$(LIBSTACK)/includes
LFLAGS		+= -L./ -lftprintf -lstack

.PHONY: all $(LIBFT) $(LIBSTACK) clean fclean re

all: $(LIBFT) $(LIBSTACK) $(NAME) $(PSWAP)

$(NAME): $(CHECK_OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(CHECK_OBJS) $(LFLAGS)

$(PSWAP): $(PS_OBJS)
	$(CC) $(CFLAGS) -o $(PSWAP) $(PSWAP_OBJS) $(LFLAGS)

$(LIBFT): $(PRINT_OBJS) $(LIBFT_OBJS)
	ar rc $(LIBFT).a $(PRINT_OBJS) $(LIBFT_OBJS)
	ranlib $(LIBFT).a

$(LIBSTACK): $(STACK_OBJS) $(LIBFT_OBJS)
	ar rc $(LIBSTACK).a $(STACK_OBJS) $(LIBFT_OBJS)
	ranlib $(LIBSTACK).a

clean:
	@- $(RM) $(PSWAP_OBJS) $(CHECK_OBJS) $(PRINT_OBJS) $(LIBFT_OBJS) $(STACK_OBJS)

fclean: clean
	@- $(RM) $(NAME) $(PSWAP) $(LIBFT).a $(LIBSTACK).a

re: fclean all
