CC       = gcc
CFLAGS   = -lm -O3 -Wno-unused-result
DEPS     =  
OBJ      = main.o ../example1/mylib.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

all: example1test

example1test: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean: 
	del *.o *.exe
