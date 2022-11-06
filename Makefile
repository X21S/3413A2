CC = gcc
LD = gcc

EXE = centipede
CFLAGS = -Wall -pthread -std=c99
LIBS = -lcurses -lpthread

OBJS := main.o console.o player.o game.o

all: release

debug: CFLAGS += -g -fsanitize=undefined
debug: $(EXE)

release: CFLAGS += -DNDEBUG
release: $(EXE)

$(EXE): $(OBJS)
	$(LD) $(CFLAGS) $(OBJS) -o $(EXE) $(LIBS)

%.o: src/%.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(OBJS)
	rm -f $(EXE)
	rm -f *~

run:
	./$(EXE)
