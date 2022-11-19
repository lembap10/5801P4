CC=g++
CFLAGS=-I.
DEPS = ParsedCode.h
OBJ = main.cpp 

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

ppalms: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)