CC       = gcc
CFLAGS   = -lm -O3 -Wno-unused-result
DEPS     =  
OBJ      = main.o ../example2c/mylib.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

all: example2ctest

example2ctest: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean: 
	del *.o *.exe
