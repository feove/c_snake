CC = gcc
CFLAGS = -std=c99 -pedantic -Werror -Wall -Wextra -Wvla -fsanitize=address,leak -g

SRC = snake.c terrain/terrain.c
OBJ = $(SRC:.c=.o)
TARGET = c_snake

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	$(RM) $(OBJ) $(TARGET)

.PHONY: all clean
