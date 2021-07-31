/*Justin LIu, jl8wf   Date:9/17/2020    Filename: postfixCalculator.cpp */

#include "postfixCalculator.h"
#include <cstdlib>
#include <stack>
#include <deque>
postfixCalculator :: postfixCalculator(){
  theStack = stack<int>();
}

postfixCalculator :: ~postfixCalculator(){
  while(!empty()){
    theStack.pop();
  }

}

void postfixCalculator :: push(int e){
  theStack.push(e);
}

int postfixCalculator :: top(){
  if(empty()){
    exit(-1);
  }
  return theStack.top();
}

void postfixCalculator :: pop(){
  if(empty()){
    exit(-1);
  }
  theStack.pop();
}

bool postfixCalculator :: empty(){
  if(theStack.size() == 0){
     return true;
  }
  return false;
}

void postfixCalculator :: add(){
  int x = theStack.top();
  theStack.pop();
  int y = theStack.top();
  theStack.pop();
  int XPlusY = x+y;
  theStack.push(XPlusY);
}

void postfixCalculator :: subtract(){
  int x = theStack.top();
  theStack.pop();
  int y = theStack.top();
  theStack.pop();
  int YMinusX = y-x;
  theStack.push(YMinusX);
}

void postfixCalculator :: multiply(){
  int x = theStack.top();
  theStack.pop();
  int y = theStack.top();
  theStack.pop();
  int XTimesY = x*y;
  theStack.push(XTimesY);
}

void postfixCalculator :: divide(){
  if(theStack.top() == 0){
    cout << "Division by Zero is not possible" << endl;
  }
  else{
    int x = theStack.top();
    theStack.pop();
    int y = theStack.top();
    theStack.pop();
    int YDivideX = y/x;
    theStack.push(YDivideX);
  }
}

void postfixCalculator :: negate(){
  int x = theStack.top();
  theStack.pop();
  x *= -1;
  theStack.push(x);
}

void postfixCalculator :: print(){
  if(!theStack.empty()){
    cout << theStack.top() << endl;
  }
}
