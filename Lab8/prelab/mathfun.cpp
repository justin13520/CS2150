/*Justin Liu, jl8wf Date:10/19/2020  Filename: mathfun.cpp */
#include <iostream>

using namespace std;
extern "C" int product(int x, int y);
extern "C" int power(int x, int y);
int main(){
  long a, b;
  cout << "Enter integer 1: " << endl;
  cin >> a;
  cout << "Enter integer 2: " << endl;
  cin >> b;
  cout << "Product: " << product(a,b) << endl;
  cout << "Power: " << power(a,b) << endl;
  return 0;
}
