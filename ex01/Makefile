# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/12 18:25:39 by frromero          #+#    #+#              #
#    Updated: 2025/12/03 11:40:45 by frromero         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = AForm
CXX = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
INCLUDES = -I .

SRC =	main.cpp Bureaucrat.cpp Form.cpp
		
OBJ = $(SRC:.cpp=.o)

# Rules
all: $(NAME)

$(NAME): $(OBJ)
	@$(CXX) $(CFLAGS) $(INCLUDES) $(OBJ) -o $(NAME)
	@echo "$(NAME) created."

clean:
	@rm -f $(OBJ)
	@echo "Object files deleted."

fclean: clean
	@rm -f $(NAME)
	@echo "$(NAME) deleted."

re: fclean all

.PHONY: all clean fclean re