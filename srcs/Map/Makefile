NAME		=	map
SRCS		=	tests_map.cpp
SRCS_CMP	=	tests_map_og.cpp
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
