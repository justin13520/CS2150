#Justin Liu, jl8wf      Date:11/16/2020         Filename:Makefile
CXX = clang++

CXXFLAGS = -Wall -O2

OBJECTS = pNode.o slideEightPuzzle.o

a.out: $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS)
	doxygen

pNode.o: pNode.cpp pNode.h

slideEightPuzzle.o: slideEightPuzzle.cpp

.PHONY: clean
clean:
	-rem -f *.o *~
