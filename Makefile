# Makefile for raylib C++ project

# Compiler
CXX := g++

# Compiler flags
CXXFLAGS := -std=c++11 -Wall -Iexternal -DPLATFORM_DESKTOP

# Linker flags
LDFLAGS := -lraylib -lpthread -ldl -lrt -lX11

# Source files
SRC := main.cpp

# Object files
OBJ := $(SRC:.cpp=.o)

# Output executable name
TARGET := FlappyBoi

# Build rules
all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Cleanup
clean:
	rm -f $(OBJ) $(TARGET)

# Build for macOS
macos:
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC) $(LDFLAGS)

# Build for Linux
linux:
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC) $(LDFLAGS)

# Build for Windows
windows:
	$(CXX) $(CXXFLAGS) -o $(TARGET).exe $(SRC) $(LDFLAGS)

.PHONY: all clean macos linux windows
