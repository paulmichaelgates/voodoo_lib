CC=gcc
CFLAGS=-Wall -Wextra -Werror -pedantic
INCLUDE=-Iinclude
LIBS=-Llib -lglfw.3.3 -framework OpenGL -framework cocoa -framework IOKit -framework CoreVideo -framework CoreFoundation -Wno-deprecated

SOURCES=tests_validation/validate_glfw.c lib/glfw-3.3.8/glad.o lib/glfw-3.3.8/utl_glfw.o utl/utl_assert.o
TARGET=validate_glfw

$(TARGET): $(SOURCES)
	$(CC) $(CFLAGS) $(INCLUDE) $(SOURCES) $(LIBS) -o $(TARGET)
