/*Justin Liu, jl8wf   Date: 11/5/2020    Filename:hashTable.h  */
#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <vector>

using namespace std;

class hashTable{
 public:
  hashTable();
  hashTable(unsigned int size);
  ~hashTable();
  unsigned int hash(char k);
  void insert(char key);
  unsigned int getFrequency(char key);
 private:
  vector<unsigned int> table;
};
#endif
