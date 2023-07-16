# Makefile

# Compiler
CC = gcc

# GPU interfaces
OPENGL = GPU_INTF_OPEN_GL
VULKAN = GPU_INTF_VULKAN

# GPU interface we are using
GPU_INTF = GPU_INTF_OPEN_GL

# Compiler flags
CFLAGS = -Wall -Wextra -g -fPIC -D$(GPU_INTF)

OPENGL = -Iinclude -Iinclude/config -Isrc/gpu_intf/opengl  -Ilib/glfw-3.3.8 -Iutl -Ishader -Iglfw-3.3.8

# Include directories
INCLUDES = -Isrc -Isrc/gpu_intf -Isrc/vdo/win $(OPENGL)

# Source directories
# Adding a new directory? Add the directory and all sources will be compiled
SRCDIRS = src/gpu_intf src/gpu_intf/opengl src src/vdo/win

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
