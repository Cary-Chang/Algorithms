CC = g++
CFLAGS = -c
OPTFLAGS = -O3

all	: bin/cb
	@echo -n ""
	
bin/cb	: cyclebreaker_opt.o UndirectedGraph_opt.o DirectedGraph_opt.o DisjointSets_opt.o
			$(CC) $(OPTFLAGS) cyclebreaker_opt.o UndirectedGraph_opt.o DirectedGraph_opt.o DisjointSets_opt.o -o bin/cb
cyclebreaker_opt.o 	   	: src/cyclebreaker.cpp  
			$(CC) $(CFLAGS) $< -o $@
UndirectedGraph_opt.o	: src/UndirectedGraph.cpp src/UndirectedGraph.h 
			$(CC) $(CFLAGS) $(OPTFLAGS) $< -o $@
DirectedGraph_opt.o	: src/DirectedGraph.cpp src/DirectedGraph.h 
			$(CC) $(CFLAGS) $(OPTFLAGS) $< -o $@	
DisjointSets_opt.o	: src/DisjointSets.cpp src/DisjointSets.h
			$(CC) $(CFLAGS) $(OPTFLAGS) $< -o $@
		
clean:
		rm -rf *.o bin/*