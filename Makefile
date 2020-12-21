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

all:	map list vector stack queue

map:
		make -C ./srcs/Map
list:
		make -C ./srcs/List
vector:
		make -C ./srcs/Vector
stack:
		make -C ./srcs/Stack
queue:
		make -C ./srcs/Queue

clean:
		make clean -C srcs/Map
		make clean -C srcs/List
		make clean -C srcs/Vector
		make clean -C srcs/Stack
		make clean -C srcs/Queue

fclean:
		make fclean -C srcs/Map
		make fclean -C srcs/List
		make fclean -C srcs/Vector
		make fclean -C srcs/Stack
		make fclean -C srcs/Queue

re:
		make re -C srcs/Map
		make re -C srcs/List
		make re -C srcs/Vector
		make re -C srcs/Stack
		make re -C srcs/Queue

.PHONY:	clean fclean re all
