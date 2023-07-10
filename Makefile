# Makefile

# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra -g -fPIC

OPENGL = -Iinclude -Iinclude/config -Ilib/glfw-3.3.8 -Iutl -Ishader -Iglfw-3.3.8

# Include directories
INCLUDES = -Isrc -Isrc/gpu_intf $(OPENGL)

# Source directories
# Adding a new directory? Add the directory and all sources will be compiled
SRCDIRS = src src/gpu_intf src/gpu_intf/opengl

# Source files
SOURCES = $(foreach dir,$(SRCDIRS),$(wildcard $(dir)/*.c))

# Object files
OBJECTS = $(SOURCES:.c=.o)

# Library name
LIBRARY = libvoodoo.a

# Additional libraries and frameworks
LIBS = -Llib -lglfw.3.3 -framework OpenGL -framework Cocoa -framework IOKit -framework CoreVideo -framework CoreFoundation -Wno-deprecated

# Default target
all: $(LIBRARY)

# Library creation
$(LIBRARY): $(OBJECTS)
	ar rcs $(LIBRARY) $(OBJECTS)

# Compilation
.c.o:
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Clean
clean:
	rm -f $(LIBRARY) $(OBJECTS)

.PHONY: all clean
