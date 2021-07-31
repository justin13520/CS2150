/*Justin Liu, jl8wf       Filename: bitCounter.cpp    Date: 9/24/2020   */
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <string>

using namespace std;

int bitCounter(int n);
string baseConverter(string numToConvert, int startBase, int endBase);

int main(int argc, char *argv[]){
  if(argc == 1){
    cout << "Enter command lines" << endl;
    exit(-1);
  }
  
  string s(argv[1]);
  string numToConvert(argv[2]);
  string b1(argv[3]);
  int startBase = stoi(b1);
  string b2(argv[4]);
  int endBase = stoi(b2);
  int n = stoi(s);
  cout << argv[1] << " has " << bitCounter(n) <<" bit(s)"<< endl;
  cout << numToConvert << " (base " << b1 << ") = " << baseConverter(numToConvert, startBase, endBase) << " (base " << b2 << ")" << endl;
  return 0;
}

int bitCounter(int n){
  if(n == 1){
    return 1;
  }
  else if(n%2 == 0){
    return bitCounter(n/2);
  }
  else{
    return 1 + bitCounter(floor(n/2));
  }
}

string baseConverter(string numToConvert, int startBase, int endBase){
  string values = "0123456789ABCDEFGHIJKLMNOPQRSTVUWXYZ";
  int baseTen = 0;
  string output = "";
  int converted;
  for(int i = 0, power = numToConvert.length()-1; i < numToConvert.length() && power >= 0; i++,power--){
    for(int k = 0; k < values.length(); k++){
      if(numToConvert[i] == values[k]){
	converted = k;
	baseTen += converted*pow(startBase,power);
	break;
      }
    }
  }
  while(baseTen > 0){
    if(baseTen % endBase < 10){
      output += to_string(baseTen % endBase);
      baseTen /= endBase;
    }
    else{
      char let = baseTen % endBase +55;
      output += let;
      baseTen /= endBase;
    }
  }
  string realOutput = "";
  for(int index = output.length()-1; index >= 0; index--){
    realOutput += output[index];
  }
  return realOutput; 
}
