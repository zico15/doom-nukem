
NAME = doom-nukem
CC = gcc
CFLAGS = -Wall -Wextra -fsanitize=leak -lSDL2 -lSDL2_image -lm -lpthread
INCLUDES	= 	-Iheaders
FRAMEWORK_PATH = Library/mac
FRAMEWORK_FLAGS = -F $(FRAMEWORK_PATH) -framework SDL2
SRCS		=   $(shell find . -name "*.c")
OBJS		= 	$(SRCS:.c=.o)

ifeq ($(shell uname 2>/dev/null),Darwin) # Mac OS X
	CFLAGS = -c -ILibrary/mac/SDL2.framework/Headers  -ILibrary/mac/SDL2_image.framework/Headers -ILibrary/mac/SDL2_ttf.framework/Headers
	INCLUDES = -Iheaders -ILibrary/mac/SDL2.framework/Headers -ILibrary/mac/SDL2_image.framework/Headers -ILibrary/mac/SDL2_ttf.framework/Headers
	FRAMEWORK_FLAGS = Library/mac/SDL2.framework/SDL2 Library/mac/SDL2_image.framework/SDL2_image Library/mac/SDL2_ttf.framework/SDL2_ttf
endif
ifeq ($(shell uname 2>/dev/null),Linux)
	CFLAGS = -Iheaders  -I./Library/linux/include
	INCLUDES = -I./headers -I./Library/linux/include
	FRAMEWORK_FLAGS = -L./Library/linux/lib -lSDL2 -lSDL2_image -lm -ldl -lpthread -lrt
endif

all: $(NAME)

$(NAME): $(OBJS) 
	@$(CC)  -o $@ $^ $(FRAMEWORK_FLAGS)

%.o: %.c
	@$(CC) $(INCLUDES) -c $(^) -o $(@)

bonus: all

clean:
	@$(RM) $(OBJS)
	@echo "\033[0;31mREMOVED OBJECT FILES\033[0m"

fclean: clean
	@$(RM) $(NAME)
	@echo "\033[0;31mREMOVED cub3D EXECUTABLE\033[0m"

re: fclean all


m: fclean

r:
	@make re && make clean && clear && ./${NAME}

.PHONY: all re clean fclean m