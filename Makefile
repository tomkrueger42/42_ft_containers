NAME		=	ft_containers
CC			=	c++
CFLAGS		+=	-Wall -Wextra -Werror -std=c++98 -fsanitize=address
INC_DIR		=	./inc/
DEPS		=	$(addprefix $(INC_DIR), $(INCS))
DEPS		+=	$(addprefix ./testing/, $(TEST))

SRCS		=	./src/main.cpp

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

$(NAME): $(SRCS) $(DEPS)
	$(CC) $(CFLAGS) -Iinc -Itesting $(SRCS) -o $@
	$(CC) $(CFLAGS) -Itesting -DUSING_STD $(SRCS) -o std_containers

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)
	rm -f std_containers
	rm -f a.out

re: fclean all
