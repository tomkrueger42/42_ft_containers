NAME		=	ft_containers
CC			=	c++
CFLAGS		=	-Wall -Wextra -Werror -std=c++98
INC_DIR		=	./inc/
SRC_DIR		=	./src/
OBJ_DIR		=	./obj/
PREP		=	./obj/
OBJS		=	$(addprefix $(OBJ_DIR), $(SRCS:.cpp=.o))
DEPS		=	$(addprefix $(INC_DIR), $(INCS))

SRCS		=	main.cpp
INCS		=	Vector.hpp

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(PREP) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp $(DEPS)
	$(CC) $(CFLAGS) -Iinc -c $< -o $@

$(PREP):
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all
