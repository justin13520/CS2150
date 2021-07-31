#Justin Liu, jl8wf 	Date:11/08/2020		Filename: Makefile
CXX = clang++

CXXFLAGS = -Wall

DEBUG = -fsanitize=address -fno-omit-frame-pointer -g

OBJECTS = huffTree.o hNode.o huffmandec.o

a.out: $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS)

huffTree.o: huffTree.h huffTree.cpp

hNode.o: hNode.cpp hNode.h

huffmandec.o: huffmandec.cpp

.PHONY: clean
clean:
	-rm -f *.o *~
