#Justin Liu, jl8wf	Date:11/09/2020		Filename:Makefile
CXX = clang++

CXXFLAGS = -Wall -O2 -std=c++11

DEBUG = -g

OBJECTS1 = heap.o hNode.o huffmanenc.o 

OBJECTS2 = huffTree.o hNode.o huffmandec.o
all: encoder decoder

encoder: $(OBJECTS1)
	$(CXX) $(CXXFLAGS) $(OBJECTS1) $(DEBUG) -o encoder

decoder: $(OBJECTS2)
	$(CXX) $(CXXFLAGS) $(OBJECTS2) $(DEBUG) -o decoder

heap.o: heap.h heap.cpp

huffTree.o: huffTree.h huffTree.cpp

hNode.o: hNode.h hNode.cpp

huffmanenc.o: huffmanenc.cpp heap.cpp heap.h hNode.cpp hNode.h

huffmandec.o: huffmandec.cpp huffTree.cpp huffTree.h hNode.cpp hNode.h

.SUFFIXES: .o .cpp

.PHONY: clean
clean:
	-rm -f *.o *~ encoder decoder
