# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyunkyle <hyunkyle@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/06 10:50:54 by hyunkyle          #+#    #+#              #
#    Updated: 2022/11/23 19:47:03 by hyunkyle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = $(wildcard *.cpp)

OBJS = $(SRCS:.cpp=.o)

COMFILE_FLAGS = c++ -Wall -Wextra -Werror  -std=c++98
LINLING_FLAG = c++ -Wall -Wextra -Werror -std=c++98

NAME = a.out

$(NAME)	: $(OBJS)
	$(LINLING_FLAG) -o $(NAME) $(OBJS)

.cpp.o:
	 $(COMFILE_FLAGS) -c $< -o $@
	
all	: $(NAME)

clean	:
		rm -f $(OBJS)

fclean	:
		make clean
		rm -f $(NAME)

re	:	
	make fclean 
	make all

.PHONY	:	all clean re fclean
