CC     =  gcc
CFLAGS = -lm -O3 -Wno-unused-result
DEPS   =  
OBJ    =  pq_dyn_binaryheap.o pq_dyn_example.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

all: pq_dyn_example.exe

pq_dyn_example.exe: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
	
clean: 
	del *.o *.exe
