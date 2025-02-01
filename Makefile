NAME = youSql

CC = g++

FLAGS = -Wall -Wextra -Werror
RM = rm -rf

SRC = main.cpp \
	tokens/Lexer.cpp \
	utils/message.cpp

OBJ = $(SRC:.cpp=.o)


all: $(NAME)

$(NAME): $(OBJ)
		@$(CC) $(FLAGS) $(OBJ) -o $(NAME)

clean: 
		@$(RM) $(OBJ)
		
fclean: clean
		@$(RM) $(NAME)

re: fclean all
