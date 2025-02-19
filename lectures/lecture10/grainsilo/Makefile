CC     =  gcc
CFLAGS = -lm -O3 -Wno-unused-result
DEPS   =  mylib.h
OBJ    =  silo.o mylib.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

all: silo.exe

silo.exe: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean: 
	del *.o *.exe
