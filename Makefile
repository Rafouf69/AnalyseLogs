#définition des variables
CXX = g++
CFLAGS = -g -Wall -Werror -pedantic -ansi
EXEC = bin/analog
REAL = src/Analog.cpp src/Readlog.cpp src/Stats.cpp

main: 
	 $(CXX) -std=c++11 -o $(EXEC) $(REAL)

debug: 
	 $(CXX) $(CFLAGS) -std=c++11 -o $(EXEC) $(REAL)

test: 
	 @ cd Tests/ && ./mktest.sh

clean:
	rm -rf *.o
	rm -rf ./bin/*
	
