//Justin Liu, jl8wf     Date:11/15/2020         Filename: slideEightPuzzle.cpp
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include "pNode.h"
#include <map>
#include <queue>
#include <vector>
using namespace std;
/** @file slideEightPuzzle.cpp Main cpp file */
void solve(pNode* p, map<vector<int>,unsigned int>& seen, vector<int> goal);

int main(){
  
  cout << "Enter Puzzle" << endl;
  string line1;
  string line2;
  string line3;
  getline(cin,line1);
  getline(cin,line2);
  getline(cin,line3);

  istringstream l1(line1);
  istringstream l2(line2);
  istringstream l3(line3);
  
  int puzzle[3][3];
  vector<int> goal{1,2,3,4,5,6,7,8,0};

    
  int num;
  int row = 0;
  
  //Inserting input values into puzzle
  
  while(l1 >> num){
    puzzle[0][row] = num;
    row++;
  }
  row = 0;
  while(l2 >> num){
    puzzle[1][row] = num;
    row++;
  }
  row = 0;
  while(l3 >> num){
    puzzle[2][row] = num;
    row++;
  }

  vector<int> start = vector<int>();//start state 
  //checks if they were inserted right and makes start state from input
  for(int i = 0; i < 3; i++){
    //cout << endl;
     for(int j = 0; j < 3; j++){
       //cout << puzzle[i][j] << " ";
       start.push_back(puzzle[i][j]);
       }
     }
  cout << endl;
  
  pNode* startState = new pNode(start);
  map<vector<int>,unsigned int> visited;//Map used to check if the node has been visited before
  
  solve(startState,visited, goal);
  map<vector<int>,unsigned int>::iterator it = visited.find(goal);//Iterator to see if the goal state was reached after exhuasting the possible combinations
  if(it != visited.end())
    cout << it->second << endl;
  else
    cout << "IMPOSSIBLE" << endl;
  return 0;
}

/**
 *@brief A BFS function that uses a map to keep track of whether we've been at that node before. The code has more detailed documentations
 *@return Nothing is returned. It is a void function
 *@param p is a pNode* that points at a node with the starting state of the puzzle as a vector
 *@param seen A map that keeps track of what we've seen before. If the goal state is found, it'll keep it when we try to find it again in the main function
 *@param goal A vector that reperesents goal state and is used to compare whether we've found the combination or not
 */
void solve(pNode* p, map<vector<int>,unsigned int>& seen, vector<int> goal){
  cout << "Solving puzzle" << endl;
  queue<pNode*> q;
  pNode* v;
  p->setStart();
  seen[p->getState()] = 0;//set the distance to the start node to 0 in map
  p->setDistance(0);//unnecessary, but he actual node has distance 0 now
  q.push(p);
  //cout << q.front()->getDistance() << endl;
  bool found = false;
  while(!q.empty()){
    v = q.front();
    if(found){//if it's already found, no need to find other combinations from goal
      while(!q.empty()){//deallocate everything in the queue and then empty the queue
	delete q.front();
	q.pop();
      }
      break;//breaks out of this while loop
    }
    vector<vector<int>> states = v->generateNeighbors();//neighbors are vectors representing the puzzle state
    for(int i = 0; i < states.size(); i++){//for each adjacent state
      if(found){//if found, no need to try to find what is already found. This iteration of combination wouldn't be it anyways
	break;
      }
      map<vector<int>,unsigned int>::iterator it = seen.find(states[i]);//iterator that finds if the combination has been seen before
      if(states[i] == goal){//if a neighbor generated is the goal state
	//cout << "Distance before the combination was found: " << v->getDistance() << endl;
	seen.insert(pair<vector<int>,unsigned int>(states[i],v->getDistance()+1));
	found = true;
	break;
      }
      if(it == seen.end()){//if this state has not been seen before
	pNode* neighbor = new pNode(states[i]);//This right now has distance infinity
	neighbor->setDistance(v->getDistance()+1);//Have to reset it to be one greater than the last distance
	q.push(neighbor);//push on queue it to continue the search
	seen.insert(pair<vector<int>,unsigned int>(states[i],v->getDistance()+1));//store in map to say we've been there before
      }
    }
    delete v;//deallocate this. won't need it anymore
    q.pop();//remove the pointer that is no longer pointing from queue
  }
}
