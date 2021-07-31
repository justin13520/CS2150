/*Justin Liu, jl8wf  Date: 9/3/2020  Filename:  xToN.cpp*/
#include <iostream>
using namespace std;

int xToN(int a, int b){
  if(b==0){
    return 1;
  }
  if(b == 1)
    return a;
  else
    return a*xToN(a,b-1);
}

int main(){
  int a = 0;
  int b = 0;
  cout << "Enter the value of a" << endl;
  cin >> a;
  cout << "Enter the value of b" << endl;
  cin >> b;
  int x = xToN(a,b);
  cout << x << endl;
  return 0;
}

