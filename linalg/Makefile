CC=gcc
CFLAGS=-Wall -Wextra -Werror -pedantic
INCLUDE=-I../include -I../

linalg.o: linalg_vect.c linalg_types.h linalg_ops.h
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@
