// Insert your header information here
// TreeCalc.cpp:  CS 2150 Tree Calculator method implementations

#include "TreeCalc.h"
#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

// Constructor
TreeCalc::TreeCalc() {
  expressionStack = stack<TreeNode*>();
}

// Destructor - frees memory
TreeCalc::~TreeCalc() {
  cleanTree(expressionStack.top());
  
}

// Deletes tree/frees memory
void TreeCalc::cleanTree(TreeNode* tree) {
    if(tree == NULL){
    return;
  }
  if(tree->right == NULL && tree->left == NULL){
    delete tree;
    return;
  }
  cleanTree(tree->right);
  cleanTree(tree->left);
  delete tree;
}

// Gets data from user
// DO NOT MODIFY
void TreeCalc::readInput() {
    string response;
    cout << "Enter elements one by one in postfix notation" << endl
         << "Any non-numeric or non-operator character,"
         << " e.g. #, will terminate input" << endl;
    cout << "Enter first element: ";
    cin >> response;
    //while input is legal
    while (isdigit(response[0]) || response[0] == '/' || response[0] == '*'
            || response[0] == '-' || response[0] == '+') {
        insert(response);
        cout << "Enter next element: ";
        cin >> response;
    }
}

// Puts value in tree stack
void TreeCalc::insert(const string& val) {
  if(val == ""){
     return;
   }
  TreeNode* newChild = new TreeNode(val);
  if(val == "+" || val == "-" || val == "*" || val == "/" || val == "~"){
    newChild->right = expressionStack.top();
    expressionStack.pop();
    newChild->left = expressionStack.top();
    expressionStack.pop();
    expressionStack.push(newChild);
  }
  else{
    expressionStack.push(newChild);
  }
}

// Prints data in prefix form
void TreeCalc::printPrefix(TreeNode* tree) const {
    // print the tree in prefix format
  if(tree == nullptr){
    return;
  }
  cout << tree->value << " ";
  printPrefix(tree->left);
  printPrefix(tree->right);
}

// Prints data in infix form
void TreeCalc::printInfix(TreeNode* tree) const {
    // print tree in infix format with appropriate parentheses
  if(tree == nullptr){
    return;
  }
  if(tree->value != "+" && tree->value != "-" && tree->value !="*" && tree->value != "/"){
    
    printInfix(tree->left);
    cout << tree->value;
    printInfix(tree->right);
    
  }
  else{
    cout << "(";
    printInfix(tree->left);
    cout << " " << tree->value << " ";
    printInfix(tree->right);
    cout << ")";
  }
}

//Prints data in postfix form
void TreeCalc::printPostfix(TreeNode* tree) const {
    // print the tree in postfix form
  if(tree == nullptr){
    return;
  }
  printPostfix(tree->left);
  printPostfix(tree->right);
  cout << tree->value << " ";
}

// Prints tree in all 3 (post, in, pre) forms
// DO NOT MODIFY
void TreeCalc::printOutput() const {
    if (expressionStack.size() != 0 && expressionStack.top() != NULL) {
        TreeNode* tree = expressionStack.top();
        cout << "Expression tree in postfix expression: ";
        printPostfix(tree);
        cout << endl;

        cout << "Expression tree in infix expression: ";
        printInfix(tree);
        cout << endl;

        cout << "Expression tree in prefix expression: ";
        printPrefix(tree);
        cout << endl;
    } else {
        cout << "Size is 0." << endl;
    }
}

// Evaluates tree, returns value
// private calculate() method
int TreeCalc::calculate(TreeNode* tree) const {
  int output = 0;
  if(tree == nullptr){
    return 0;
  }
  if(tree->value == "+" || tree->value == "-" || tree->value == "*" || tree->value == "/"){
    if(tree->value == "+"){
      output += calculate(tree->left) + calculate(tree->right);
    }
    else if(tree->value == "-"){
      output += calculate(tree->left) - calculate(tree->right);
    }
    else if(tree->value == "*"){
      output += calculate(tree->left) * calculate(tree->right);
    }
    else if(tree->value == "/"){
      if(tree->right->value == "0"){
	cout << "Can't divide by 0" << endl;
        exit(-1);
      }
      output += calculate(tree->left) / calculate(tree->right);
    }
  }
  else{
      return stoi(tree->value);
    }
return output; 
}

//Calls calculate, sets the stack back to a blank stack
// public calculate() method. Hides private data from user
int TreeCalc::calculate() {
    // call private calculate method here
  return calculate(expressionStack.top());
}
