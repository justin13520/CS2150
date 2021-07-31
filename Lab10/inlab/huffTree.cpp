//Justin Liu, jl8wf    Date: 11/08/2020     Filename: huffTree.h
#include "huffTree.h"
#include "hNode.h"
#include <iostream>
#include <string>

using namespace std;

huffTree::huffTree(){
  root = new hNode("?",0);
}

huffTree::~huffTree(){
  deleteTree(root);
}

void huffTree::insert(hNode* root, string prefix, string value, int index){//
  if(index == prefix.length()-1 && prefix[index] == '0'){//make the leaf node
    hNode* leaf = new hNode(value, 0);
    //cout << "Moving to the left and setting value: " << leaf->value << " " << endl;
    root->left = leaf;
    return;
  }
  if(index == prefix.length()-1 && prefix[index] == '1'){//make the leaf node
    hNode* leaf = new hNode(value, 0);
    //cout << "Moving to the right and setting value: " << leaf->value << " " << endl;
    root->right = leaf;
    return;
  }
  if(prefix[index] == '0' && index < prefix.length()){
    //cout << "Moving to the left " << endl;
    if(root->left == nullptr){
      hNode* internal = new hNode("?",0);
      root->left = internal;
    }
    index++;
    insert(root->left, prefix, value, index);
    
    //index = prefix.length();
  }
  else if(prefix[index] == '1' && index < prefix.length()){
    //cout << "Moving to the right " << endl;
    if(root->right == nullptr){
      hNode* internal = new hNode("?",0);
      root->right = internal;
    }
    index++;
    insert(root->right, prefix, value, index);
  }
	
}

void huffTree::decode(string code, int index){//
  hNode* current = getRoot();
  while(index < code.length()){
    //cout << code[index] << endl;
    if(code[index] == '1' && current->right != nullptr){
      //cout << "Moving to the right" << endl;
      current = current->right;
    }
    if(code[index] == '0' && current->left != nullptr){
      //cout << "Moving to the left" << endl;
      current = current->left;
    }
    if(current->right == nullptr && current->left == nullptr){
      cout << current->value;
      //cout << "Reseting current" << endl;
      current = getRoot();
    }
    index++;
  }
  
}
  

void huffTree::deleteTree(hNode* root){
  if(root == nullptr){
    return;
  }
  if(root->left == nullptr && root->right == nullptr){
    delete root;
    return;
  }
  deleteTree(root->left);
  deleteTree(root->right);
  delete root;
}

hNode* huffTree::getRoot(){
   return root;
 }
