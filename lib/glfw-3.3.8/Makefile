export GLFW_OBJS

GLFW_OBJS = glfw_prj.o

CC=gcc
CFLAGS=-Wall
INCLUDE=-I../../include
LIBS=-L../../lib -lglfw.3.3

$(GLFW_OBJS): utl_glfw.c utl_glfw.h glad.c
	$(CC) $(CFLAGS) $(INCLUDE) -c utl_glfw.c -o $@
	$(CC) $(CFLAGS) $(INCLUDE) -c glad.c -o glad.o
	ld -r $@ glad.o -o $@

.PHONY: all clean

all:
	@echo "Building $(GLFW_OBJS)"

clean:
	rm -f $(GLFW_OBJS)