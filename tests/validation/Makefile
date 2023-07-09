CC = gcc
CFLAGS = -Wall $(INCLUDES)
LDFLAGS = -L../../lib -framework OpenGL -framework cocoa -framework IOKit -framework CoreVideo -framework CoreFoundation -Wno-deprecated  ../../lib/libglfw.3.3.dylib ../../lib/glfw-3.3.8/glfw_prj.o ../../utl/utl_assert.o ../../shader/shader.o
LDLIBS = -lglfw.3.3

ROOT_DIR = ../../
INCLUDES = -I../../include -I../../lib/glfw-3.3.8 -I../../utl -I../../shader -I../../glfw-3.3.8 -I$(ROOT_DIR)

SRCS = validate_glfw.c

OBJS = $(SRCS:.c=.o)

TARGET = validate_glfw

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(MAKE) -C ../../lib/glfw-3.3.8/
	$(MAKE) -C ../../utl/
	$(CC) $(CFLAGS) $(INCLUDES) $(LDFLAGS) -o $(TARGET) $(OBJS) $(LDLIBS)

clean:
	rm -f $(OBJS) $(TARGET)
	$(MAKE) -C ../../lib/glfw-3.3.8/ clean --no-print-directory

