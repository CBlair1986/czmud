# Making things. First Makefile, ever.
TCOD= libtcod-1.4.1
INCLUDE= $(TCOD)/include
CC= g++
WFLAGS= # -Wall
LDFLAGS= -L$(TCOD) -ltcod -ltcod++ -I$(INCLUDE)

all: main.o region.o player.o nonplayer.o
	$(CC) -o czgame main.o region.o player.o nonplayer.o $(WFLAGS) $(LDFLAGS)

main.o: main.cpp region.h
	$(CC) -c main.cpp $(WFLAGS) $(LDFLAGS)

region.o: region.cpp region.h
	$(CC) -c region.cpp $(WFLAGS) $(LDFLAGS)

player.o: player.cpp player.h
	$(CC) -c player.cpp $(WFLAGS) $(LDFLAGS)

nonplayer.o: nonplayer.cpp nonplayer.h
	$(CC) -c nonplayer.cpp $(WFLAGS) $(LDFLAGS)

.PHONY : clean
clean:
	# Remove things that would be added from compiling:
	-rm *.o *~ czgame
	# Remove things that shouldn't be there:
	-rm .*.swp

