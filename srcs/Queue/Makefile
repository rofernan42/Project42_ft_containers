# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rofernan <rofernan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/16 14:43:27 by rofernan          #+#    #+#              #
#    Updated: 2020/12/16 14:43:29 by rofernan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	queue
SRCS		=	tests_queue.cpp
SRCS_CMP	=	tests_queue_og.cpp
OBJS		=	$(SRCS:.cpp=.o)
OBJS_CMP	=	$(SRCS_CMP:.cpp=.o)
CXX			=	clang++
CFLAGS		=	-Wall -Wextra -Werror -I./
DEBUG		=	-Wall -Wextra -Werror -I./ -g -fsanitize=address

all:		$(NAME)
$(NAME):	$(OBJS)
			$(CXX) $(CFLAGS) -o $(NAME) $(OBJS)
cmp:		$(OBJS_CMP)
			$(CXX) $(CFLAGS) -o $(NAME) $(OBJS_CMP)
debug:		$(OBJS)
			$(CXX) $(DEBUG) -o $(NAME) $(OBJS)
clean:
			rm -rf $(OBJS) $(OBJS_CMP)
fclean:		clean
			rm -rf $(NAME)
re:			fclean all
.PHONY:		clean fclean re all
