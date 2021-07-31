//Justin Liu, jl8wf     Date:10/30/2020       Filename: heap.h
#ifndef HEAP_H
#define HEAP_H

#include "hNode.h"
#include <vector>

class heap{
 public:
  heap();
  heap(vector<hNode*> vec);
  ~heap();
  
  hNode* deleteMin();
  string findMin();//the value of the node or the actual node?
  void insert(hNode* x);
  unsigned int size();
  void makeEmpty(hNode* hNode);
  bool isEmpty();
  void print();
  void printCode(hNode* root, string x, vector<string>& p, string& f);
  hNode* getRoot();
 private:
  vector<hNode*> minHeap;
  unsigned int heap_size;
  //void printCode(hNode* root, string x, vector<string>& c);
  void percolateUp(int hole);
  void percolateDown(int hole);
};
#endif
