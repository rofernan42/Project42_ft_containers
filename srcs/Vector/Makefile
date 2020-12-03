# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rofernan <rofernan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/02 19:13:49 by rofernan          #+#    #+#              #
#    Updated: 2020/12/02 19:13:53 by rofernan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	vector
SRCS		=	tests_vector.cpp
SRCS_CMP	=	tests_vector_og.cpp
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
