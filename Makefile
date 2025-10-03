CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -O2 -Isrc
LDFLAGS = -lcunit
TARGET = aoe2arena

SOURCES = src/main.c src/misc.c src/file_io.c
OBJECTS = $(SOURCES:.c=.o)

.PHONY: all clean run

all: $(TARGET)

$(TARGET): $(SOURCES)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

clean:
	rm -f $(TARGET) $(OBJECTS)

# Test binary
TEST_TARGET = run_tests
TEST_SOURCES = test/main_test.c src/misc.c
TEST_OBJECTS = $(TEST_SOURCES:.c=.o)

test: $(TEST_TARGET)

$(TEST_TARGET): $(TEST_OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)


run: $(TARGET)
	./$(TARGET)

# install: $(TARGET)
# 	cp $(TARGET) /usr/local/bin/

debug: CFLAGS += -g
debug: $(TARGET)

.PHONY: help
help:
	@echo "Available targets:"
	@echo "  all     - Build the project (default)"
	@echo "  clean   - Remove compiled files"
	@echo "  run     - Build and run the project"
	@echo "  debug   - Build with debug symbols"
	@echo "  install - Install to /usr/local/bin/"
	@echo "  help    - Show this help message"
