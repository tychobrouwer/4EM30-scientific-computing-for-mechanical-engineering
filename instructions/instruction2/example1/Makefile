CC       = gcc
CFLAGS   = -lm -O3 -Wno-unused-result
DEPS     =  
OBJ      = main.o mylib.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

all: example1

example1: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean: 
	del *.o *.exe
