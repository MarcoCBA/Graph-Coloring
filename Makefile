CC = gcc
CFLAGS = -g -ITiotimolina -Wall -Wextra -std=c99 -O3 -DNDEBUG
OBJ = graphcd.o stdio.o main.o graph_helpers.o comparisons.o orders.o greedy.o bipartito.o queue.o

all: $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o main

valgrind: $(OBJ)
	$(CC) $(CFLAGS) -o main $(OBJ)
	valgrind --leak-check=full --show-reachable=yes ./main

clean:
	$(RM) $(OBJ) main
