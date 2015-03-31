CC=gcc
CFLAGS=-Wall -g -Ilib/glfw/include/
FILES=src/main.c $(wildcard src/pong/*.c)
FRAMEWORKS=-framework CoreVideo -framework Cocoa -framework IOKit -framework OpenGL
LIBS=-Llib/glfw/_build/src/ -lglfw
LDFLAGS=$(FRAMEWORKS) $(LIBS)
OUTPUT=build/main

all: clean compile

clean:
	rm -rf build
	mkdir build

compile:
	$(CC) $(CFLAGS) $(FILES) $(LDFLAGS) -o $(OUTPUT)

deps/build: deps/build/glfw
deps/build/glfw:
	mkdir -p lib/glfw/_build; \
	cd lib/glfw/_build; \
	cmake -D BUILD_SHARED_LIBS=ON ..; \
	make

deps/clean:
	rm -rf lib/glfw/_build

run: all
	./build/main
