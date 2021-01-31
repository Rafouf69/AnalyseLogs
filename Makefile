#définition des variables
CXX = g++
CFLAGS = -g -Wall -Werror -pedantic -ansi
EXEC = bin/analog
REAL = src/Analog.cpp src/Readlog.cpp src/Stats.cpp

main: 
	 @ mkdir -p bin;$(CXX) -std=c++11 -o $(EXEC) $(REAL)

debug: 
	 @ mkdir -p bin;$(CXX) $(CFLAGS) -std=c++11 -o $(EXEC) $(REAL)

test: main
	 @ cd Tests/ && ./mktest.sh


clean:
	rm -rf *.o
	rm -rf ./bin
	
