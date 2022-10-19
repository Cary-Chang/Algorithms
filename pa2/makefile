CC = g++
CFLAGS = -c
OPTFLAGS = -O2

all	: bin/mps
	@echo -n ""
	
bin/mps	: MaximumPlanarSubset.o main_opt.o
			$(CC) $(OPTFLAGS) MaximumPlanarSubset.o main_opt.o -o bin/mps
main_opt.o 	   	: src/main.cpp 
			$(CC) $(CFLAGS) $< -o $@
MaximumPlanarSubset.o	: src/MaximumPlanarSubset.cpp src/MaximumPlanarSubset.h
			$(CC) $(CFLAGS) $(OPTFLAGS) $< -o $@
			
clean:
		rm -rf *.o bin/*