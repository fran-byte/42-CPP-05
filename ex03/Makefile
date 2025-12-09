# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: frromero <frromero@student.42madrid.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/12 18:25:39 by frromero          #+#    #+#              #
#    Updated: 2025/12/09 19:15:47 by frromero         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Intern
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -g 
INCLUDES = -I .

SRC =	main.cpp Bureaucrat.cpp AForm.cpp PresidentialPardonForm.cpp \
		RobotomyRequestForm.cpp ShrubberyCreationForm.cpp Intern.cpp
		
OBJ = $(SRC:.cpp=.o)

# Rules
all: $(NAME)

$(NAME): $(OBJ)
	@$(CXX) $(CXXFLAGS) $(INCLUDES) $(OBJ) -o $(NAME)
	@echo "$(NAME) created."

clean:
	@rm -f $(OBJ)
	@echo "Object files deleted."

fclean: clean
	@rm -f $(NAME)
	@rm -f *_shrubbery
	@echo "$(NAME) deleted."

re: fclean all

.PHONY: all clean fclean re