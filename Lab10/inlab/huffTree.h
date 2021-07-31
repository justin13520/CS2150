//Justin Liu, jl8wf    Date: 11/08/2020     Filename: huffTree.h
#ifndef HUFFTREE_H
#define HUFFTREE_H

#include "hNode.h"

using namespace std;

class huffTree{
 public:
  huffTree();
  ~huffTree();
  void insert(hNode* root, string prefix, string value, int index);
  void decode(string code, int index);
  void deleteTree(hNode* root);
  hNode* getRoot();
 private:
  hNode* root;
  
};

#endif
