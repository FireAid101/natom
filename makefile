CC := gcc

#-WError
# Compiler flags
CFLAGS := -Wall -Wextra -fstack-protector-strong -D_FORTIFY_SOURCE=2 -fPIE -pie -I include -DNCURSES_STATIC 
LDFLAGS := -lncurses

# Source files
SRCS := $(wildcard src/*.c)

# Output directory and target
OUT_DIR := build
TARGET := natom.exe

# Build type
DEBUG_FLAGS := -DDebug

# Default rule
all: win-debug

# Debug build for Windows
win-debug: $(SRCS)
	$(CC) $(CFLAGS) $(DEBUG_FLAGS) -o $(OUT_DIR)/$(TARGET) $(SRCS) $(LDFLAGS)

# Clean build directory
clean:
	rm -f $(OUT_DIR)/$(TARGET)

.PHONY: all win-debug clean
