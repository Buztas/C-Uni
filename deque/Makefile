CC=gcc
CFLAGS=-I.
DEPS = deque.h
OBJ = main.o deque.o 

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

test: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
