# Makefile for linked-list-sort project

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -Iinclude
DEBUG_FLAGS = -g -DDEBUG
RELEASE_FLAGS = -O2 -DNDEBUG

# Directories
SRC_DIR = src
INCLUDE_DIR = include
BUILD_DIR = build

# Source files
SOURCES = main.c $(SRC_DIR)/linked_list.c $(SRC_DIR)/args.c
OBJECTS = $(BUILD_DIR)/main.o $(BUILD_DIR)/linked_list.o $(BUILD_DIR)/args.o

# Target executable
TARGET = $(BUILD_DIR)/linked_list_sort

# Default target
all: $(TARGET)

# Debug build
debug: CFLAGS += $(DEBUG_FLAGS)
debug: $(TARGET)

# Release build
release: CFLAGS += $(RELEASE_FLAGS)
release: $(TARGET)

# Create build directory if it doesn't exist
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Build target executable
$(TARGET): $(OBJECTS) | $(BUILD_DIR)
	$(CC) $(OBJECTS) -o $(TARGET)

# Compile main.c
$(BUILD_DIR)/main.o: main.c $(INCLUDE_DIR)/linked_list.h $(INCLUDE_DIR)/args.h | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c main.c -o $(BUILD_DIR)/main.o

# Compile linked_list.c
$(BUILD_DIR)/linked_list.o: $(SRC_DIR)/linked_list.c $(INCLUDE_DIR)/linked_list.h | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $(SRC_DIR)/linked_list.c -o $(BUILD_DIR)/linked_list.o

# Compile args.c
$(BUILD_DIR)/args.o: $(SRC_DIR)/args.c $(INCLUDE_DIR)/args.h | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $(SRC_DIR)/args.c -o $(BUILD_DIR)/args.o

# Clean build artifacts
clean:
	rm -rf $(BUILD_DIR)

# Install (optional - copies binary to /usr/local/bin)
install: $(TARGET)
	cp $(TARGET) /usr/local/bin/

# Uninstall
uninstall:
	rm -f /usr/local/bin/linked_list_sort

# Run the program with sample data
run: $(TARGET)
	$(TARGET) -f names.txt

# Help
help:
	@echo "Available targets:"
	@echo "  all      - Build the project (default)"
	@echo "  debug    - Build with debug flags"
	@echo "  release  - Build with optimization flags"
	@echo "  clean    - Remove build artifacts"
	@echo "  run      - Build and run with names.txt"
	@echo "  install  - Install binary to /usr/local/bin"
	@echo "  uninstall- Remove binary from /usr/local/bin"
	@echo "  help     - Show this help message"

# Phony targets
.PHONY: all debug release clean install uninstall run help
