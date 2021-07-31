#Justin Liu, jl8wf	Date:10/30/2020		Filename: Makefile

CXX = clang++
CXXFLAGS = -Wall -g
AS = nasm
ASFLAGS = -f elf64 -g

OBJECTS = threexinput.o threexplusone.o timer.o

a.out: $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS)

treexinput.o: threexinput.cpp

threexplusone.o: threexplusone.s

timer.o: timer.cpp timer.h

.PHONY: clean
clean:
	-rm -f *.o *~
