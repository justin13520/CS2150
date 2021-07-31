//Justin Liu, jl8wf    Date:11/4/2020     Filename: hNode.h

#ifndef HNODE_H
#define HNODE_H

#include <string>
using namespace std;

class hNode {
public:
  hNode();                  // Default Constructor
  hNode(string val,int fre); // Constructor
  string getValue();
  unsigned int getFrequency();
  void setRight(hNode* r);
  void setLeft(hNode* l);
private:
    unsigned int frequency;
    string value;
    hNode* left;
    hNode* right;
  friend class heap;       // gives TreeCalc access to private data
  friend class huffTree;
};

#endif
