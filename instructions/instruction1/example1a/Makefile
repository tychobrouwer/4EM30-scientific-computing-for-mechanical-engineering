CC     =  gcc
CFLAGS = -lm -O3 -Wno-unused-result
DEPS   =  
OBJ    =  main.o 

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

all: example1a

example1a: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean: 
	del *.o *.exe
