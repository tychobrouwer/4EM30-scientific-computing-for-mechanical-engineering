CC     =  gcc
CFLAGS = -lm -O3 -Wno-unused-result
DEPS   =  
OBJ    =  pq_binaryheap.o pq_example.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

all: pq_example.exe

pq_example.exe: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
	
clean: 
	del *.o *.exe
