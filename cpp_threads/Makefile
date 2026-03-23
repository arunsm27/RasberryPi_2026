# Cross-compilation Makefile for Raspberry Pi Zero 2W
# Compiler for ARM Cortex-A53
CC = arm-linux-gnueabihf-g++

# Compiler flags
CFLAGS = -std=c++17 -pthread -mcpu=cortex-a53 -mfpu=neon-fp-armv8 -mfloat-abi=hard -O2

# Target executable name
TARGET = RasCpp

# Source files
SRC = main.cpp

# Build target
$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

# Clean target
clean:
	rm -f $(TARGET)

# Phony targets
.PHONY: clean