# Makefile

# Compiler and compiler flags
CXX = g++
CXXFLAGS = -std=c++11 -Wall

# Directories
SRC_DIR = src
INCLUDE_DIR = headers
BUILD_DIR = build

# SDL2 flags and libraries
SDL2_CFLAGS := $(shell sdl2-config --cflags)
SDL2_LIBS := $(shell sdl2-config --libs)

# Source files
SRCS = $(wildcard $(SRC_DIR)/*.cpp)

# Object files
OBJS = $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SRCS))

# Target executable
TARGET = chip8_emulator

# Rule to build the executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(SDL2_CFLAGS) $^ -o $@ $(SDL2_LIBS)

# Rule to build object files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) $(SDL2_CFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

# Phony target to clean the build directory
.PHONY: clean
clean:
	rm -rf $(BUILD_DIR)/*.o $(TARGET)
