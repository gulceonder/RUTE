

CC= clang
CFLAGS=-g -Wall
OBJS=sharedmemory.o
EXE=writeshmem.elf readshmem.elf destroyshmem.elf

LIBS= -pthread

all: $(EXE)

%.elf: %.o $(OBJS)
	$(CC) $(CFLAGS) $< $(OBJS) -o$@ $(LIBS)

%.O: %.c %h
	$(CC) $(CFLAGS) -c $< -o $@ $(LIBS)

%.O: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(LIBS)

clean:
	rm -rf *.dSYM *.o $(EXE)
