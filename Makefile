# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rreedy <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/30 16:58:46 by rreedy            #+#    #+#              #
#    Updated: 2018/08/31 08:12:33 by rreedy           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := checker
PUSHSWAP := pushswap
LIB := libftprintf

POBJS := $(patsubst %.c,%.o,$(wildcard ./$(PUSHSWAP)/*.c))
COBJS := $(patsubst %.c,%.o,$(wildcard ./$(NAME)/*.c))
LOBJS := $(patsubst %.c,%.o,$(wildcard ./$(LIB)/*.c))

CFLAGS += -Wall -Wextra -Werror -I./includes -I./$(LIB)/includes
LFLAGS += -L./ -lftprintf

.PHONY := all checker pushswap libftprintf clean fclean re

all: $(NAME)

$(NAME): $(COBJS) $(LIB) $(PUSHSWAP)
	$(CC) $(CFLAGS) $(LFLAGS) -o $(NAME)

$(PUSHSWAP): $(POBJS)
	$(CC) $(CFLAGS) $(LFLAGS) -o $(PUSHSWAP)

$(LIB): $(LOBJS)
	ar rc $(LIB).a $(LOBJS)
	ranlib $(LIB).a

clean:
	@- $(RM) $(POBJS) $(COBJS) $(LOBJS)

fclean: fclean
	@- $(RM) $(NAME) $(PUSHSWAP) $(LIB)/$(LIB).a

re: fclean all
