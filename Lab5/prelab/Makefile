#Justin Liu, jl8wf Labsection: 107 Date 10/4/2020  FileName: Makefile
CXX = clang++ $(CXXFLAGS)
CXXFLAGS = -Wall
DEBUG = -g

OBJECTS = TreeCalc.o TreeCalcTest.o TreeNode.o

TreeCalc: $(OBJECTS)
	$(CXX) $(DEBUG) $(OBJECTS)

TreeCalc.o: TreeCalc.h TreeCalc.cpp

TreeCalcTest.o: TreeCalcTest.cpp

TreeNode.o: TreeNode.h TreeNode.cpp

.PHONY: clean
clean:
	-rm -f *.o *~ TreeCalc
