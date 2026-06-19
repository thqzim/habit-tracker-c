CC = gcc
CFLAGS = -Wall -Wextra -std=c11
SRC = src/main.c src/habit.c src/storage.c
OUT = habit-tracker

all:
	$(CC) $(CFLAGS) $(SRC) -o $(OUT)

run: all
	./$(OUT)

clean:
	rm -f $(OUT)