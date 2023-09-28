
NAME = doom-nukem
CC = gcc
CFLAGS = -Wall -Wextra -fsanitize=leak
INCLUDES	= 	-Iheaders
FRAMEWORK_PATH = Library/mac
FRAMEWORK_FLAGS = -F $(FRAMEWORK_PATH) -framework SDL2
SRCS		=   $(shell find . -name "*.c")
OBJS		= 	$(SRCS:.c=.o)

ifeq ($(shell uname 2>/dev/null),Darwin) # Mac OS X
	INCLUDES	+= -ILibrary/mac/SDL2.framework/Headers
	INCLUDES 	+= -ILibrary/mac/SDL2_image.framework/Headers
	FRAMEWORK_PATH = Library/mac
	FRAMEWORK_FLAGS = -F $(FRAMEWORK_PATH) -framework SDL2 -framework SDL2_image
endif
ifeq ($(shell uname 2>/dev/null),Linux)
	FRAMEWORK_PATH = Library/linux
	FRAMEWORK_FLAGS = -F $(FRAMEWORK_PATH) -framework SDL2 -framework SDL2_image
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