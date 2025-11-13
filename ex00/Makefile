# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/15 10:58:43 by frromero          #+#    #+#              #
#    Updated: 2025/11/13 21:09:57 by frromero         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Bureaucrat
CXX = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
INCLUDES = -I .

SRC =	main.cpp Bureaucrat.cpp
		
OBJ = $(SRC:.cpp=.o)

# Rules
all: $(NAME)

$(NAME): $(OBJ)
	@$(CXX) $(CFLAGS) $(INCLUDES) $(OBJ) -o $(NAME)
	@echo "$(NAME) created."

%.o: %.cpp
	@$(CXX) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@rm -f $(OBJ)
	@echo "Object files deleted."

fclean: clean
	@rm -f $(NAME)
	@echo "$(NAME) deleted."

re: fclean all

.PHONY: all clean fclean re