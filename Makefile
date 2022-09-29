CC=gcc
CFLAGS=-I. -Wall -g
DEPS = hello.h
OBJ = hello.o hello_message.o
TEST_OBJ = test_hello.o hello_message.o
TEST_LIBS=-lcunit -lefence

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

hello: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

test_hello: CFLAGS += -fsanitize=address
test_hello: $(TEST_OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(TEST_LIBS)

.PHONY: clean valgrind

clean:
	rm -f *.o hello core 

valgrind: ./hello
	valgrind ./hello
