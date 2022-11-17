NAME		=	ft_containers
CC			=	c++
CFLAGS		+=	-Wall -Wextra -Werror -std=c++98 -fsanitize=address
INC_DIR		=	./inc/
SRC_DIR		=	./src/
OBJ_DIR		=	./obj/
PREP		=	./obj/
OBJS		=	$(addprefix $(OBJ_DIR), $(SRCS:.cpp=.o))
DEPS		=	$(addprefix $(INC_DIR), $(INCS))
DEPS		+=	$(addprefix ./testing/, $(TEST))

SRCS		=	main.cpp
INCS		=	algorithm.hpp \
				iterator_traits.hpp \
				iterator.hpp \
				map.hpp \
				red_black_tree_iterator.hpp \
				red_black_tree_node.hpp \
				red_black_tree.hpp \
				reverse_iterator.hpp \
				type_traits.hpp \
				utility.hpp \
				vector_iterator.hpp \
				vector.hpp \

TEST		=	log.hpp \
				map_tests.hpp \
				vector_tests.hpp

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(PREP) $(OBJS) $(DEPS)
	$(CC) $(CFLAGS) $(OBJS) -o $@
	$(CC) $(CFLAGS) -USING_STD $(OBJS) -o std_containers

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp $(DEPS)
	$(CC) $(CFLAGS) -Iinc -Itesting -c $< -o $@

$(PREP):
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)
	rm -f a.out

re: fclean all
