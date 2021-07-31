#Justin Liu, jl8wf	Date:10/30/2020		Filename: Makefile

CXX = clang++ 
CXXFLAGS = -Wall -g
AS = nasm
ASFLAGS = -f elf64 -g

OBJECTS = testBinarySearch.o timer.o binarySearch.o

a.out: $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS)

testBinarySearch.o: testBinarySearch.cpp

timer.o: timer.cpp timer.h

binarySearch.o: binarySearch.s

.PHONY: clean
clean:
	-rm -f *.o *~
