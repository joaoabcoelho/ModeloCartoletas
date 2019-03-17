
CC = g++
CFLAGS = -O3

all: TestCartoleta

TestCartoletas: TestCartoleta.o
	$(CC) $(CFLAGS) -o $@ $^

TestCartoletas.o: TestCartoleta.C ModeloCartoleta.h
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY:clean

clean:
	-rm *.o TestCartoleta
