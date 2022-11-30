NAME		=	ft_containers
CC			=	c++
CFLAGS		+=	-Wall -Wextra -Werror -std=c++98 -fsanitize=address

INC_DIR		=	./inc/
ITER_DIR	=	$(INC_DIR)iterators/
UTILS_DIR	=	$(INC_DIR)utils/

DEPS		=	$(addprefix $(INC_DIR), $(CONTAINERS))
DEPS		+=	$(addprefix $(ITER_DIR), $(ITERS))
DEPS		+=	$(addprefix $(UTILS_DIR), $(UTILS))
DEPS		+=	$(addprefix ./testing/, $(TEST))

INCS		+=	-I$(INC_DIR) -I$(ITER_DIR) -I$(UTILS_DIR) -Itesting

CONTAINERS	=	map.hpp \
				set.hpp \
				stack.hpp \
				vector.hpp

UTILS		=	algorithm.hpp \
				red_black_tree_node.hpp \
				red_black_tree.hpp \
				type_traits.hpp \
				utility.hpp \
				log.hpp

ITERS		=	iterator.hpp \
				red_black_tree_iterator.hpp \
				reverse_iterator.hpp \
				vector_iterator.hpp

SRCS		=	./src/main.cpp

TEST		=	map_tests.hpp \
				vector_tests.hpp

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(SRCS) $(DEPS)
	$(CC) $(CFLAGS) $(INCS) -DDEBUG=0 $(SRCS) -o ft_containers
	$(CC) $(CFLAGS) $(INCS) -DDEBUG=0 -DUSING_STD $(SRCS) -o std_containers
	bash ./test.sh

1: $(SRCS) $(DEPS)
	$(CC) $(CFLAGS) $(INCS) -DDEBUG=1 -DUSING_STD $(SRCS) -o std_containers
	$(CC) $(CFLAGS) $(INCS) -DDEBUG=1 $(SRCS) -o ft_containers
	bash ./test.sh

2: $(SRCS) $(DEPS)
	$(CC) $(CFLAGS) $(INCS) -DDEBUG=2 -DUSING_STD $(SRCS) -o std_containers
	$(CC) $(CFLAGS) $(INCS) -DDEBUG=2 $(SRCS) -o ft_containers
	bash ./test.sh

clean:
	rm -f out.*

fclean: clean
	rm -f $(NAME)
	rm -f std_containers
	rm -f a.out

re: fclean all
