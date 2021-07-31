#include <string>
#include <fstream>
#include <vector>
#include <list>
#include "hashTable.h"

using namespace std;

hashTable::hashTable(){
  table = vector<list<string>>();//25143
  
}

hashTable::hashTable(unsigned int wordsInDict){
  loadFactor = .5;
  size = getNextPrime(wordsInDict/loadFactor);
  table = vector<list<string>>(size);//how do i make a vector of lists of strings a size, all things empty
  for(int i = 0; i < table.size(); i++){
    table[i] = list<string>();
  }
}

hashTable::~hashTable(){

}

unsigned int hashTable :: hash(string k){
  return (k[0]*k[k.length()-1]*size) % size;
}

void hashTable::insert(string key, string value){
  unsigned int hashKey = hash(key);
  table[hashKey].push_back(value);
}

bool hashTable::found(string key){
  unsigned int hashKey = hash(key);
  for(list<string>::iterator itr = table[hashKey].begin(); itr != table[hashKey].end(); itr++){
    if(*itr == key){
      return true;
    }
  }
  return false;
}

void hashTable::remove(string key, string value){
  if(found(key)){
    table[hash(key)].remove(value);
  }
  else{
    cout << "Doesn't exist" << endl;
  }
}

bool hashTable:: checkprime(unsigned int p) {
    if ( p <= 1 ) // 0 and 1 are not primes; the are both special cases
        return false;
    if ( p == 2 ) // 2 is prime
        return true;
    if ( p % 2 == 0 ) // even numbers other than 2 are not prime
        return false;
    for ( int i = 3; i*i <= p; i += 2 ) // only go up to the sqrt of p
        if ( p % i == 0 )
            return false;
    return true;
}

int hashTable:: getNextPrime (unsigned int n) {
    while ( !checkprime(++n) );
    return n; // all your primes are belong to us
}
