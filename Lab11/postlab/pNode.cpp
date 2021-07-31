//Justin Liu, jl8wf     Date:11/15/2020        Filename:pNode.h
#include "pNode.h"
#include <iostream>
#include <vector>
#include <math.h>
/** @file pNode.cpp The cpp file of pNode */
using namespace std;

pNode::pNode(){
  state = vector<int>();
  distance = INFINITY;
}

pNode::pNode(vector<int> p){
  state = p;
  distance = INFINITY;
}

pNode::~pNode(){

}

vector<int> pNode::getState(){
  return state;
}

double pNode::getDistance(){
  return distance;
}

vector<vector<int>> pNode::generateNeighbors(){//find where 0 is, and shift based on that
  int index;
  vector<vector<int>> neighbors = vector<vector<int>>();
  for(int i = 0; i < 9; i++){
    if(state[i] == 0){
      index = i;
    }
  }
  if(index == 0){//hole move down or right
    vector<int> down = {state[3],state[1],state[2],0,state[4],state[5],state[6],state[7],state[8]};
    vector<int> right = {state[1],0,state[2],state[3],state[4],state[5],state[6],state[7],state[8]};
    neighbors.push_back(down);
    neighbors.push_back(right);
    return neighbors;
  }
  if(index == 1){//left,right,down
    
    vector<int> left = {0,state[0],state[2],state[3],state[4],state[5],state[6],state[7],state[8]};
    vector<int> right = {state[0],state[2],0,state[3],state[4],state[5],state[6],state[7],state[8]};
    vector<int> down = {state[0],state[4],state[2],state[3],0,state[5],state[6],state[7],state[8]};
    neighbors.push_back(left);
    neighbors.push_back(right);
    neighbors.push_back(down);
    return neighbors;
  }
  if(index == 2){//left,down
    vector<int> left = {state[0],0,state[1],state[3],state[4],state[5],state[6],state[7],state[8]};
    vector<int> down = {state[0],state[1],state[5],state[3],state[4],0,state[6],state[7],state[8]};
    neighbors.push_back(left);
    neighbors.push_back(down);
    return neighbors;
  }
  if(index == 3){//up,right,down
vector<int> up = {0,state[1],state[2],state[0],state[4],state[5],state[6],state[7],state[8]};
 vector<int> right = {state[0],state[1],state[2],state[4],0,state[5],state[6],state[7],state[8]};
 vector<int> down = {state[0],state[1],state[2],state[6],state[4],state[5],0,state[7],state[8]};
 neighbors.push_back(up);
 neighbors.push_back(right);
 neighbors.push_back(down);
 return neighbors;
  }
  if(index == 4){
    vector<int> up = {state[0],0,state[2],state[3],state[1],state[5],state[6],state[7],state[8]};
    vector<int> left = {state[0],state[1],state[2],0,state[3],state[5],state[6],state[7],state[8]};
    vector<int> right = {state[0],state[1],state[2],state[3],state[5],0,state[6],state[7],state[8]};
    vector<int> down = {state[0],state[1],state[2],state[3],state[7],state[5],state[6],0,state[8]};
    neighbors.push_back(up);
    neighbors.push_back(left);
    neighbors.push_back(right);
    neighbors.push_back(down);
    return neighbors;
  }
  if(index == 5){
    vector<int> up = {state[0],state[1],0,state[3],state[4],state[2],state[6],state[7],state[8]};
    vector<int> left = {state[0],state[1],state[2],state[3],0,state[4],state[6],state[7],state[8]};
    vector<int> down = {state[0],state[1],state[2],state[3],state[4],state[8],state[6],state[7],0};
    neighbors.push_back(up);
    neighbors.push_back(left);
    neighbors.push_back(down);
    return neighbors;
  }
  if(index == 6){
    vector<int> up = {state[0],state[1],state[2],0,state[4],state[5],state[3],state[7],state[8]};
    vector<int> right = {state[0],state[1],state[2],state[3],state[4],state[5],state[7],0,state[8]};
    neighbors.push_back(up);
    neighbors.push_back(right);
    return neighbors;
  }
  if(index == 7){
    vector<int> up = {state[0],state[1],state[2],state[3],0,state[5],state[6],state[4],state[8]};
    vector<int> left = {state[0],state[1],state[2],state[3],state[4],state[5],0,state[6],state[8]};
    vector<int> right = {state[0],state[1],state[2],state[3],state[4],state[5],state[6],state[8],0};
    neighbors.push_back(up);
    neighbors.push_back(left);
    neighbors.push_back(right);
    return neighbors;
  }
  if(index == 8){
    vector<int> left = {state[0],state[1],state[2],state[3],state[4],state[5],state[6],0,state[7]};
    vector<int> up = {state[0],state[1],state[2],state[3],state[4],0,state[6],state[7],state[5]};
    neighbors.push_back(left);
    neighbors.push_back(up);
    return neighbors;
  }
  return neighbors;
}

void pNode::setStart(){
  distance = 0;
}

void pNode::setDistance(double d){
  distance = d;
}
