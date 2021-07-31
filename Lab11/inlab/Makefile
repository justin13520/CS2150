#Justin Liu, jl8wf	Date:11/15/2020 	Filename:Makefile
CXX = clang++
CXXFLAGS = -Wall -O2
DEBUG = -g

OBJECTS = middleearth.o traveling-skeleton.o

a.out: $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) $(DEBUG)
	doxygen

middleearth.o: middleearth.cpp middleearth.h

.PHONY: clean
clean:
	-rm -f *.o *~
