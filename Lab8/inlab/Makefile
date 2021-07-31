#Justin Liu, jl8wf	Date:10/22/2020     Filename:Makefile
CXX = clang++

CXXFLAGS = -Wall -g

AS = nasm

ASFLAGS = -f elf64 -g

OBJECTS = testMergeSort.o mergeSort.o

a.out: $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS)

clean:
	-r -f *.o *~
