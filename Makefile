###
# Nion Library
# Mikaela Nion
# @built: 2025-09-25
# @version: 0.0.0.1.20250925
# @license: MIT
###

CC = gcc
CFLAGS = -Wall -Wextra -Werror -O2 -std=c11
LDFLAGS = #-lm
SRC = ./src/main.c ./src/arena.c # Add library source files here
OBJ = $(SRC:.c=.o)
TARGET = nionlib

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(LDFLAGS) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) $(OBJ)