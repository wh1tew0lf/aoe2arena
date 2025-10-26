CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -O2 -Isrc
LDFLAGS = -lcunit

TARGET = bin/build/aoe2arena
SOURCES = src/main.c src/misc.c src/file_io.c src/battle.c
OBJECTS_DIR = bin/objects
OBJECTS = $(patsubst src/%.c,bin/objects/%.o,$(SOURCES))

.PHONY: all clean run

all: $(TARGET)

$(TARGET): $(OBJECTS) | bin/build
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

$(OBJECTS_DIR):
	mkdir -p $(OBJECTS_DIR)

bin/objects:
	mkdir -p bin/objects

data:
	mkdir -p data

bin/build:
	mkdir -p bin/build

bin/objects/%.o: src/%.c | bin/objects
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf bin/

run: $(TARGET)
	./$(TARGET)

.PHONY: help
help:
	@echo "Available targets:"
	@echo "  all     - Build the project (default)"
	@echo "  clean   - Remove compiled files"
	@echo "  run     - Build and run the project"
	@echo "  help    - Show this help message"
