# Compiler
CC := g++
# Compiler flags
CFLAGS := -Wall -Wextra -std=c++11

# Source directory
SRC_DIR := game
# Output directory
BUILD_DIR := $(SRC_DIR)

# Source files
SRCS := $(wildcard $(SRC_DIR)/*.cpp)

# Object files
OBJS := $(SRCS:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)

# Executable name
EXEC := polyflop

# Platform specific flags and libraries
UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
    LDFLAGS := -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
else ifeq ($(UNAME_S),Darwin)
    LDFLAGS := -lraylib -framework OpenGL -framework OpenAL -framework Cocoa
endif

# Build rule for object files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

# Main build rule
$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

# Clean rule
clean:
	rm -f $(BUILD_DIR)/*.o $(EXEC)

# Phony targets
.PHONY: all clean
