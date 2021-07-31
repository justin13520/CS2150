#Justin Liu, jl8wf 	Date:11/08/2020		Filename: Makefile
CXX = clang++

CXXFLAGS = -Wall

DEBUG = -fsanitize=address -fno-omit-frame-pointer -g

OBJECTS = heap.o hNode.o huffmanenc.o

a.out: $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS)

heap.o: heap.cpp heap.h

hNode.o: hNode.cpp hNode.h

huffmanenc.o: huffmanenc.cpp

.PHONY: clean
clean:
	-rm -f *.o *~
