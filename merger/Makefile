

COMPILER = g++

NAME = codingame-editor-sync

FLAGS = -std=c++20 -Wall -Werror -Wextra

#ex: INCLUDES = -I libs/FTXUI/include -I libs/json-parser/include
INCLUDES=

SOURCES = \
	main \
	File \
	FileMerger \
 
SRC_WITHOUT_SUFFIX = $(addprefix src/, $(SOURCES))
SRC = $(addsuffix .cpp, $(SRC_WITHOUT_SUFFIX))
OBJ = $(SRC:src/%.cpp=obj/%.o)

all: $(NAME)

$(NAME): dir $(OBJ)
	${COMPILER} $(FLAGS) $(OBJ) -o $(NAME)

dir:
	if [ ! -d "obj" ]; then mkdir obj; fi

obj/%.o: src/%.cpp src/*.h
	${COMPILER} $(FLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all


run: all
	./${NAME}
