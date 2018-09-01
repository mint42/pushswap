# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rreedy <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/30 16:58:46 by rreedy            #+#    #+#              #
#    Updated: 2018/08/31 19:12:45 by rreedy           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := checker
PSWAP := pushswap
LIB := libftprintf

CH_OBJS := $(patsubst %.c,%.o,$(wildcard ./srcs/$(NAME)/*.c))
PS_OBJS := $(patsubst %.c,%.o,$(wildcard ./srcs/$(PSWAP)/*.c))

PF_OBJS := $(patsubst %.c,%.o,$(wildcard ./$(LIB)/srcs/ft_printf/*.c))
LIB_OBJS := $(patsubst %.c,%.o,$(wildcard ./$(LIB)/srcs/*.c))

CFLAGS += -Wall -Wextra -Werror -I./includes -I./$(LIB)/includes
LFLAGS += -L./ -lftprintf

.PHONY: all $(LIB) clean fclean re

all: $(LIB) $(NAME) $(PSWAP)

$(NAME): $(CH_OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(CH_OBJS) $(LFLAGS)

$(PSWAP): $(PS_OBJS)
	$(CC) $(CFLAGS) -o $(PSWAP) $(PS_OBJS) $(LFLAGS)

$(LIB): $(PF_OBJS) $(LIB_OBJS)
	ar rc $(LIB).a $(PF_OBJS) $(LIB_OBJS)
	ranlib $(LIB).a

clean:
	@- $(RM) $(PS_OBJS) $(CH_OBJS) $(PF_OBJS) $(LIB_OBJS)

fclean: clean
	@- $(RM) $(NAME) $(PSWAP) $(LIB).a

re: fclean all
