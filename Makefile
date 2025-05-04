CC = gcc
CFLAGS = -std=c99 -Wall -Wextra

BUILD = build
SRC = src/main.c
TARGET = ${BUILD}/filegen

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

clean:
	rm -f $(TARGET)