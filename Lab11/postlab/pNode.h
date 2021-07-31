//Justin Liu, jl8wf     Date:11/15/2020        Filename:pNode.h
#ifndef PNODE_H
#define PNODE_H

#include <vector>

using namespace std;

class pNode{
 public:
  /** @brief Default constructor for pNode */
  pNode();
  /** @brief Custom constructor for pNode*/
  pNode(vector<int> puzzle);
  /** @brief Destructor */
  ~pNode();
  
  vector<int> getState();
  double getDistance();
  vector<vector<int>> generateNeighbors();
  void setStart();
  void setDistance(double d);

 private:
  vector<int> state;
  double distance;
};
#endif
