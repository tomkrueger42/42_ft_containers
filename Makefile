NAME		=	ft_containers
CC			=	c++
CFLAGS		+=	-Wall -Wextra -Werror -std=c++98 -fsanitize=address

INC_DIR		=	./inc/
ITER_DIR	=	$(INC_DIR)iterators/
UTILS_DIR	=	$(INC_DIR)utils/

DEPS		=	$(addprefix $(INC_DIR), $(CONTAINERS))
DEPS		+=	$(addprefix $(ITER_DIR), $(ITERS))
DEPS		+=	$(addprefix $(UTILS_DIR), $(UTILS))

DEPS		+=	./tests/inc/tests.hpp
SRCS		+=	$(addprefix ./tests/src/, $(TEST))

INCS		+=	-I$(INC_DIR) -I$(ITER_DIR) -I$(UTILS_DIR) -Itests/inc

CONTAINERS	=	map.hpp \
				set.hpp \
				stack.hpp \
				vector.hpp

UTILS		=	algorithm.hpp \
				red_black_tree_node.hpp \
				red_black_tree.hpp \
				type_traits.hpp \
				utility.hpp

ITERS		=	iterator.hpp \
				red_black_tree_iterator.hpp \
				reverse_iterator.hpp \
				vector_iterator.hpp

TEST		=	main.cpp \
				map_tests.cpp \
				set_tests.cpp \
				stack_tests.cpp \
				vector_tests.cpp

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(SRCS) $(DEPS)
	$(CC) $(CFLAGS) $(INCS) $(SRCS) -o ft_containers
	$(CC) $(CFLAGS) $(INCS) -DUSING_STD $(SRCS) -o std_containers

clean:
	rm -f out.*

fclean: clean
	rm -f $(NAME)
	rm -f std_containers
	rm -f a.out

re: fclean all
