//Justin Liu, jl9wf     Date:10/30/2020       Filename: heap.cpp
//Modified version of binary_heap.cpp provided by CS2150
//
#include "heap.h"
#include "hNode.h"
#include <iostream>
#include <string>
using namespace std;

heap::heap(){
  heap_size = 0;
  hNode* blank = nullptr;
  minHeap = vector<hNode*>();
  minHeap.push_back(blank);
}

heap::heap(vector<hNode*> v) : heap_size(v.size()) {
  hNode* blank = nullptr;
  
  minHeap = v;
  minHeap.push_back(minHeap[0]);
  minHeap[0] = blank;
  for (int i = heap_size/2; i > 0; i--){
    percolateDown(i);
  }
}

heap::~heap(){
  makeEmpty(minHeap[1]);
}

void heap::insert(hNode* x) {
    // a vector push_back will resize as necessary
    minHeap.push_back(x);
    // move it up into the right position
    percolateUp(++heap_size);
}

void heap::percolateUp(int hole) {
    // get the value just inserted
    hNode* x = minHeap[hole];
    // while we haven't run off the top and while the
    // frequency is less than the parent...
    for ( ; (hole > 1) && (x->getFrequency() < minHeap[hole/2]->getFrequency()); hole /= 2) {
    
        minHeap[hole] = minHeap[hole/2]; // move the parent down
    }
    // correct position found!  insert at that spot
    minHeap[hole] = x;
}

hNode* heap::deleteMin() {
    // make sure the heap is not empty
    if (heap_size == 0) {
        throw "deleteMin() called on empty heap";
    }
   
    // save the value to be returned
    hNode* ret = minHeap[1];
    // move the last inserted position into the root
    minHeap[1] = minHeap[heap_size--];
    // make sure the vector knows that there is one less element
    minHeap.pop_back();
    // percolate the root down to the proper position
    if (!isEmpty()) {
        percolateDown(1);
    }

    // return the old root node
    return ret;
}

void heap::percolateDown(int hole) {
    // get the value to percolate down
  hNode* x = minHeap[hole];
    // while there is a left child...
    while (hole*2 <= heap_size) {
        int child = hole*2; // the left child
        // is there a right child?  if so, is it lesser?
        if ((child+1 <= heap_size) && (minHeap[child+1]->getFrequency() < minHeap[child]->getFrequency())) {
            child++;
        }
        // if the child is greater than the node...
        if (x->getFrequency() > minHeap[child]->getFrequency()) {
            minHeap[hole] = minHeap[child]; // move child up
            hole = child;             // move hole down
        } else {
            break;
        }
    }
    // correct position found!  insert at that spot
    minHeap[hole] = x;
}

string heap::findMin() {
    if (heap_size == 0) {
        throw "findMin() called on empty heap";
    }
      return minHeap[1]->getValue();
}

unsigned int heap::size() {
    return heap_size;
}

void heap::makeEmpty(hNode* hNode) {
  if(hNode == nullptr){
    return;
  }
  else if(hNode->left == nullptr && hNode->right == nullptr){
    delete hNode;
    return;
  }
  else{
    makeEmpty(hNode->left);
    makeEmpty(hNode->right);
  delete hNode;
  }
  minHeap.resize(1);
  heap_size = 0;
}

bool heap::isEmpty() {
    return heap_size == 0;
}

void heap::print() {
  cout << "(" << minHeap[0] << ") ";
    for (int i = 1; i <= heap_size; i++) {
      cout << minHeap[i]->getValue() << " ";
        // next line from http://tinyurl.com/mf9tbgm
        bool isPow2 = (((i+1) & ~(i))==(i+1))? i+1 : 0;
        if (isPow2) {
            cout << endl << "\t";
        }
    }
    cout << endl;
}
void heap :: printCode(hNode* root, string x, vector<string>& prefix, string& p){
  if(root == nullptr){
    return;
  }
  if(root->left == nullptr && root->right == nullptr){
    if(root->value == x){
      prefix.push_back(" ");
      for(int i = 0; i < prefix.size();i++){
	p += prefix[i];
	cout << prefix[i];
      }
    }
    else{
      prefix.pop_back();
      return;
    }
  }
  if(root->left){
    prefix.push_back("0");
    printCode(root->left,x,prefix,p);
  }
  if(root->right){
    prefix.push_back("1");
    printCode(root->right,x,prefix,p);
  }
  prefix.pop_back();
}
hNode* heap:: getRoot(){
  return minHeap[1];
}
