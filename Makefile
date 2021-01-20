#définition des variables
CXX = g++
CFLAGS = -ansi -pedantic -std=c++11 -g -Wall
LDFLAGS =
MAP = 
EXEC = bin/analog
REAL = src/Analog.cpp src/Readlog.cpp src/Stats.cpp



main:
	@ echo $(CXX) $(CPPFLAGS) -std=c++11 -o $(EXEC) $(REAL)
	@ $(CXX) $(CPPFLAGS) -std=c++11 -o $(EXEC) $(REAL)

clean:
	rm -rf *.o 

mrproper : clean
	rm -rf $(EXEC)
