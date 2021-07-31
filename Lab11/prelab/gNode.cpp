//Justin Liu, jl8wf        Date:11/12/2020           Filename:gNode.cpp
#include <iostream>
#include <vector>
#include "gNode.h"
using namespace std;
/** @file gNode.cpp The cpp file foe the gNode object. 
 *@brief All the member function of gNode are implemented here
 */
gNode::gNode(){
  course = "";
  outPtrs = vector<gNode*>();
  inDegree = outPtrs.size();
}

gNode::gNode(string c){
  course = c;
  outPtrs = vector<gNode*>();//decrement all nodes in the vectors
  inDegree = outPtrs.size();
  
}

gNode::~gNode(){
  remove();
}

void gNode::addPtr(gNode* ptr){
  outPtrs.push_back(ptr);
}

void gNode::inDegreeInc(){
  inDegree++;
}

void gNode::inDegreeDec(){
  inDegree--;
}

vector<gNode*> gNode::getOutwardPtrs(){
  return outPtrs;
}
int gNode::getInDegree(){
  return inDegree;
}

string gNode::getCourse(){
  return course;
}

void gNode::remove(){
  while(!outPtrs.empty()){
    outPtrs.pop_back();
  }
}
