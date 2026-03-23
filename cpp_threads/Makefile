# Cross-compilation Makefile for Raspberry Pi Zero 2W
# Compiler for ARM Cortex-A53
CC = arm-linux-gnueabihf-g++
CXX = arm-linux-gnueabihf-g++

# Compiler flags
CFLAGS = -std=c++17 -pthread -mcpu=cortex-a53 -mfpu=neon-fp-armv8 -mfloat-abi=hard -O2
TEST_FLAGS = -std=c++17 -pthread -O2

# Directories
SRC_DIR = src
TEST_DIR = tests
BUILD_DIR = build
INCLUDE_DIR = include

# Target executables
TARGET = RasCpp
TEST_TARGET = test_RasCpp

# Source files
SRC_FILES = $(SRC_DIR)/main.cpp
TEST_FILES = $(TEST_DIR)/test_main.cpp

# Build target for Raspberry Pi
$(TARGET): $(SRC_FILES)
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) $(SRC_FILES) -o $(BUILD_DIR)/$(TARGET)

# Build and run tests locally
$(TEST_TARGET): $(TEST_FILES)
	g++ $(TEST_FLAGS) -I$(INCLUDE_DIR) $(TEST_FILES) -o $(BUILD_DIR)/$(TEST_TARGET) -lgtest -lgtest_main

# Run tests
test: $(TEST_TARGET)
	$(BUILD_DIR)/$(TEST_TARGET)

# Clean target
clean:
	rm -f $(BUILD_DIR)/$(TARGET)
	rm -f $(BUILD_DIR)/$(TEST_TARGET)

# Phony targets
.PHONY: clean test