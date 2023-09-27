
NAME = doom-nukem
CC = gcc
CFLAGS = -Wall -Wextra
FRAMEWORK_PATH = 'Library/mac'
FRAMEWORK_FLAGS = -F $(FRAMEWORK_PATH) -framework SDL2
# src/*
SRC = 

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ $(FRAMEWORK_FLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $^

clean:
	rm -f *.o

re: clean all