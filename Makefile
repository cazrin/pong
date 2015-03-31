CC=cc
CFLAGS=-Wall -g
FILES=src/main.c $(wildcard src/pong/*.c)
OUTPUT=build/main

all: clean compile

clean:
	rm -rf build
	mkdir build

compile:
	$(CC) $(CFLAGS) $(FILES) -o $(OUTPUT)
