/*Justin LIu, jl8wf   Date:9/17/2020    Filename: postfixCalculator.h */
#ifndef POSTFIXCALCULATOR_H
#define POSTFIXCALCULATOR_H

#include <stack>
#include <iostream>
#include <deque>
#include <cstdlib>
#include <string>
using namespace std;

class postfixCalculator{
 public:
  postfixCalculator();
  ~postfixCalculator();
  void push(int e);
  int top();
  void pop();
  bool empty();
  void add();
  void subtract();
  void multiply();
  void divide();
  void negate();
  void print();
 private:
  stack<int> theStack;
};

#endif
