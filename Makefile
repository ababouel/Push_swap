# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ababouel <ababouel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/28 14:33:42 by ababouel          #+#    #+#              #
#    Updated: 2022/03/30 06:07:21 by ababouel         ###   ########.fr        #
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

SRCS_BONUS = bonus/main_bonus.c \
			 bonus/mutils/checkmaxd.c \
			 bonus/mutils/freeup.c \
			 bonus/mutils/mcheck.c \
			 bonus/mutils/mcheckd.c \
			 bonus/oldtool/ft_atoi.c \
			 bonus/oldtool/ft_split.c \
			 bonus/oldtool/ft_strcmp.c \
			 bonus/oldtool/ft_strdup.c  \
			 bonus/utils/get_next_line.c \
			 bonus/utils/get_next_line_utils.c \
			 bonus/utils/rules.c \
			 bonus/utils/second_rules.c \
			 bonus/utils/tools.c

OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

FLAGS = -Wall -Werror -Wextra
NAME = push_swap
BONUS = checker

PUSH_SWAP = src/include/push_swap.h
CHECKER = bonus/include/checker.h

all : $(NAME)

$(NAME) : $(OBJS)
	cc $(FLAGS) $(OBJS) -o $@
%.o: %.c $(PUSH_SWAP)
	cc $(FLAGS) -c $< -o $@

bonus : $(OBJS_BONUS)
	cc $(FLAGS) $(OBJS_BONUS) -o $(BONUS)
%.o: %.c $(CHECKER)
	cc $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(OBJS_BONUS)

fclean: clean
	rm -f $(NAME) $(BONUS)

re: fclean $(NAME) clean

.PHONY = re fclean clean all B 
