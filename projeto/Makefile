CC = gcc
CFLAGS = -Wall -Wextra -std=c99
SRC = src/main.c src/jogo.c
OBJ = $(SRC:.c=.o)
TARGET = JogoDaVida

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -Iinclude

clean:
	rm -f $(OBJ) $(TARGET)