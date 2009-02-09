# Making things. First Makefile, ever.
TCOD= libtcod-1.4.1
INCLUDE= $(TCOD)/include
CC= g++
WFLAGS= -Wall
LDFLAGS= -L$(TCOD) -ltcod -ltcod++ -I$(INCLUDE)

all: main.o
	$(CC) -o czgame main.o $(WFLAGS) $(LDFLAGS)

main.o:
	$(CC) -c main.cpp $(WFLAGS) $(LDFLAGS)

.PHONY : clean
clean:
	# Remove things that would be added from compiling:
	-rm *.o *~ czgame
	# Remove things that shouldn't be there:
	-rm .*.swp

