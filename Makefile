#définition des variables
CXX = g++
CFLAGS = -ansi -pedantic -std=c++11 -g -Wall
LDFLAGS =
MAP = 
EXEC = analog

all : $(EXEC)

$(EXEC) : Analog.o Stats.o ReadLog.o
	$(CXX) $(CFLAGS) $(LDFLAGS) -o $@ $^

Analog.o : Analog.cpp ReadLog.h
	$(CXX) $(MAP) $(CFLAGS) -c $<
	
Stats.o : Stats.cpp
	$(CXX) $(MAP) $(CFLAGS) -c $<
	
ReadLog.o : ReadLog.cpp Stats.h
	$(CXX) $(MAP) $(CFLAGS) -c $<

clean:
	rm -rf *.o 

mrproper : clean
	rm -rf $(EXEC)
	rm *.sncf
