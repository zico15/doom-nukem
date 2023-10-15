
NAME = doom-nukem
CC = gcc
CFLAGS = 
INCLUDES =
LIBS = 
SRCS =   $(shell find . -name "*.c")
OBJS = 	$(SRCS:.c=.o)
FRAMEWORKS = 

ifeq ($(shell uname 2>/dev/null),Darwin) # Mac OS X
	CC = clang
	# CFLAGS = `./Library/mac/bin/sdl2-config --cflags`
	INCLUDES = -Iheaders -I./Library/mac/include  -ILibrary/mac/frameworks/SDL2_image.framework/Headers -ILibrary/mac/frameworks/SDL2.framework/Headers
	# LIBS = `./Library/mac/bin/sdl2-config --libs`
	FRAMEWORKS = -F./Library/mac/frameworks -framework SDL2 -framework SDL2_image
endif
ifeq ($(shell uname 2>/dev/null),Linux)
	CC = gcc
	CFLAGS = `./Library/linux/bin/sdl2-config --cflags`
	INCLUDES = -I./headers -I./Library/linux/include
	LIBS = -L./Library/linux/lib -lSDL2 -lSDL2_image -lm -ldl -lpthread -lrt
endif
ifeq ($(OS),Windows_NT)
	CC = gcc
	CFLAGS = `./Library/windows/bin/sdl2-config --cflags`
	INCLUDES = -Iheaders -I./Library/windows/include/SDL2
	LIBS = `./Library/windows/bin/sdl2-config --libs`
endif

all: $(NAME)

$(NAME): $(OBJS) 
	@$(CC) $(CFLAGS) -o $@ $^ $(LIBS) $(FRAMEWORKS)

%.o: %.c
	@$(CC) $(CFLAGS) $(INCLUDES) -c $(^) -o $(@)

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
ifeq ($(shell uname 2>/dev/null),Darwin)
	@make re && make clean && clear && DYLD_FRAMEWORK_PATH=./Library/mac/frameworks ./${NAME} > test.log
else
	@make re && make clean && clear && ./${NAME}
endif

.PHONY: all re clean fclean m