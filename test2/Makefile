NAME	= ft_containers
CC		= c++
CFLAGS	= -Wall -Wextra -Werror -std=c++98

O		= obj/
S		= src/
A		= stack/
B		= vector/
C		= map/
D		= set/
E		= tree/

OBJS	= $(patsubst $S%.cpp, $O%.o, $(SRCS))
SRCS	=	$Smain.cpp \
			$S$AStackTest.cpp \
			$S$BVectorTest.cpp \
			$S$CMapTest.cpp \
			$S$DSetTest.cpp \
			$S$ETreeTest.cpp \


.PHONY: all clean fclean re

all: $(NAME)

#Linking...
$(NAME):	$(OBJS)
			@echo "\033[1;33m$(NAME)\033[0m \033[0;33mlinking.\033[0m"
			@$(CC) $(OBJS) -o $(NAME)
			@echo "\033[1;35m$(NAME)\033[0m \033[0;35mcreated.\033[0m"

# Compiling...
$O%.o:		$S%.cpp
			@[ -d $(O) ]     || mkdir -p $(O)
			@[ -d $(O)$(A) ] || mkdir -p $(O)$(A)
			@[ -d $(O)$(B) ] || mkdir -p $(O)$(B)
			@[ -d $(O)$(C) ] || mkdir -p $(O)$(C)
			@[ -d $(O)$(D) ] || mkdir -p $(O)$(D)
			@[ -d $(O)$(E) ] || mkdir -p $(O)$(E)
			@echo "\033[1;36m$(NAME)\033[0m \033[0;36mcompiling.\033[0m"
			@$(CC) $(CFLAGS) -c $< -o $@

clean:
			@rm -rf $(O)
			@echo "\033[1;31mobject files\033[0m \033[0;31mremoved.\033[0m"

fclean:		clean
			@rm -f $(NAME)
			@echo "\033[1;31m$(NAME)\033[0m \033[0;31mremoved.\033[0m"

re: fclean all
