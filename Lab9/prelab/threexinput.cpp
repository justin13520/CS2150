//Justin Liu, jl8wf    Date:10/27/2020     Filename: threexinput.cpp
#include <iostream>
#include "timer.h"
using namespace std;

extern "C" int threexplusone(int x);


int main(){
  timer t;
  
  int x;
  cout << "Enter a number: " << endl;
  cin >> x;
  int n;
  cout << "Enter iterations of subroutine: " << endl;
  cin >> n;
  int i = threexplusone(x);
  cout << "Iterations: "<< i << endl;
 

  for(int i = 0; i < n; i++){
    threexplusone(x);
  }

  return 0;
}
