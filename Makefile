# Target binary name
target   := cot

# Directories
SRC_DIR  := src
INC_DIR  := include
BLD_DIR  := build

# Basic compiler flags
LDFLAGS  := -static-libgcc

# Libraries to link against
LIBS     := -ldl -lm

# Packages to include via pkg-config
packages := sdl2

# Debug and feature flags
DEBUG   ?= 0

# Adjust compiler flags based on debug mode
ifeq ($(DEBUG), 1)
    CFLAGS += -Wall -Wextra -O0 -g -DDEBUG -march=armv8-a
else
    CFLAGS += -O3 -march=armv8-a -ftree-vectorize -fomit-frame-pointer -pipe
endif

# Use pkg-config to get flags for compiling and linking
ifneq ($(packages),)
    LIBS    += $(shell pkg-config --libs-only-l $(packages))
    LDFLAGS += $(shell pkg-config --libs-only-L --libs-only-other $(packages))
    CFLAGS  += $(shell pkg-config --cflags $(packages))
endif

# Automatically determine object files from source files
objects := $(patsubst $(SRC_DIR)/%.c,$(BLD_DIR)/%.o,$(wildcard $(SRC_DIR)/*.c))

.PHONY: all clean

all: $(target)

clean:
	-rm -rf $(BLD_DIR)
	-rm -f $(target)

# Link the target binary
$(target): $(objects)
	$(CC) $(LDFLAGS) -o $@ $(objects) $(LIBS)

# Compile source files into object files
$(BLD_DIR)/%.o: $(SRC_DIR)/%.c $(INC_DIR)/*.h
	-mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c -MMD -o $@ $<
