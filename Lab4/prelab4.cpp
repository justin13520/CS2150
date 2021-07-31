#include <iostream>
#include <climits>
#include <cfloat>


using namespace std;

void sizeOfTest();
void overflow();
void outputBinary(int x);

int main(){
  int x;
  cin >> x;
  
  sizeOfTest();
  overflow();
  outputBinary(x);
  return 0;
}

void sizeOfTest(){
  cout << "Size of int: " << sizeof(int) << endl;
  cout << "Size of unsigned int: " << sizeof(unsigned int) << endl;
  cout << "Size of float: " << sizeof(float) << endl;
  cout << "Size of double: " << sizeof(double) << endl;
  cout << "Size of char: " << sizeof(char) << endl;
  cout << "Size of bool: " << sizeof(bool) << endl;
  cout << "Size of int*: " << sizeof(int*) << endl;
  cout << "Size of char*: " << sizeof(char*) << endl;
  cout << "Size of double*: " << sizeof(double*) << endl;
}

void overflow(){
  bool y = true;
  
  cout << y << " + " << 1 << " = " << y+1 << endl;

}

void outputBinary(int x){
  int thirtyTwoBit[32];
  int remainder;
  for(int i = 31; i >= 0; i--){
    remainder = x%2;
    x = x >> 1;
    thirtyTwoBit[i] = remainder;
  }
  for(int k = 0; k < 32; k++){
    if(k % 4 == 0 && k != 0){
      cout << " ";
      cout << thirtyTwoBit[k];
    }
    else if(k == 31){
      cout<< thirtyTwoBit[k] << endl;
    }
    else{
      cout << thirtyTwoBit[k];
    }
  }
}

