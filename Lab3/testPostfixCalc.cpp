/*Justin LIu, jl8wf   Date:9/17/2020    Filename: testPostfixCalc.cpp */

#include "postfixCalculator.h"
#include <iostream>
#include <deque>
#include <cstdlib>
#include <string>
using namespace std;

int main(){
  int num;
  string input;
  postfixCalculator calc = postfixCalculator();
  while(cin >> input){
    if(input == "+"){
      calc.add();
    }
    else if(input == "-"){
      calc.subtract();
    }
    else if(input == "*"){
      calc.multiply();
    }
    else if(input == "/"){
      calc.divide();
    }
    else if(input == "~"){
      calc.negate();
    }
    else if(input == " "){
        
    }
    else{
      num = stoi(input);
      calc.push(num);
    }
  }
  calc.print();
  return 0;
}
