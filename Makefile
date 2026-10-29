CC      = gcc
CFLAGS  = -Wall -Wextra -std=c99
TARGET  = main.exe
SRC     = main.c grille.c jeu.c menu.c mode_2j.c utils.c victoire.c

all: $(TARGET)

$(TARGET): $(SRC) $(wildcard *.h)
	$(CC) $(CFLAGS) $(SRC) -o $@

run: all
	./$(TARGET)

clean:
	del /Q $(TARGET) 2>nul

.PHONY: all run clean