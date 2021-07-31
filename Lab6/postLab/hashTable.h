/*Justin Liu, jl8wf   Date: 10/7/2020    Filename:hashTable.h  */
#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <list>

using namespace std;

class hashTable{
 public:
  hashTable();
  hashTable(unsigned int size);
  ~hashTable();
  unsigned int hash(string k);
  unsigned int rehash(string k);
  void insert(string key, string value);
  void remove(string key, string value);
  bool found(string key);
  bool checkprime(unsigned int p);
  int getNextPrime(unsigned int n);
  float loadFactor;
  unsigned int size;
 private:
  vector<list<string>> table;
};
#endif
