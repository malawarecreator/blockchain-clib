# Define variables for source and object files
SRC_DIR = src
LIB_DIR = lib
SOURCES = $(SRC_DIR)/blockchain.c 
OBJECTS = $(patsubst $(SRC_DIR)/%.c,%.o,$(SOURCES)) # Object files in the same directory

# Define the compiler and flags
CC = gcc
CFLAGS = -g -Wall

# Define the library name
LIB_NAME = libblockchain.a

# Default target: build the static library
all: $(LIB_DIR)/$(LIB_NAME)

# Rule to build the static library
$(LIB_DIR)/$(LIB_NAME): $(OBJECTS)
	mkdir -p $(LIB_DIR)  # Create the lib directory if it doesn't exist
	ar rcs $@ $^

# Rule to compile .c files into .o files (in the same directory)
%.o: $(SRC_DIR)/%.c $(SRC_DIR)/blockchain.h 
	$(CC) $(CFLAGS) -c $< -o $@

# Clean rule to remove object files and the library
clean:
	rm -f *.o $(LIB_DIR)/$(LIB_NAME)



install: $(LIB_DIR)/$(LIB_NAME)
	sudo mkdir -p /usr/local/lib /usr/local/include

	sudo cp $(LIB_DIR)/$(LIB_NAME) /usr/local/lib
	sudo cp $(SRC_DIR)/blockchain.h /usr/local/include