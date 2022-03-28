# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ababouel <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/28 14:33:42 by ababouel          #+#    #+#              #
#    Updated: 2022/03/28 15:18:56 by ababouel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = src/algosort/algutils.c \
	   src/algosort/first_sort.c \
	   src/algosort/second_sort.c \
	   src/algosort/third_sort.c \
	   src/main.c \
	   src/mutils/checkmaxd.c \
	   src/mutils/freeup.c \
	   src/mutils/mcheck.c \
	   src/mutils/mcheckd.c \
	   src/oldtool/ft_atoi.c \
	   src/oldtool/ft_split.c \
	   src/oldtool/ft_strdup.c \
	   src/oldtool/ft_strjoin.c \
	   src/utils/rules.c \
	   src/utils/second_rules.c \
	   src/utils/stools.c \
	   src/utils/tools.c

OBJS = $(SRCS:.c=.o)

FLAGS = -Wall -Werror -Wextra
NAME = push_swap
PUSH_SWAP = src/include/push_swap.h


all : $(NAME)

$(NAME) : $(OBJS)
	cc $(FLAGS) $(OBJS) -o $@

%.o: %.c $(PUSH_SWAP)
	cc $(FLAGS) -c $< -o $@


clean:
	rm -f $(OBJS) $(OBJS_BONUS)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME) clean

.PHONY = re fclean clean all 
