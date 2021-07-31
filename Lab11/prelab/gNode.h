//Justin Liu, jl8wf        Date:11/12/2020           Filename:gNode.h
#ifndef GNODE_H
#define GNODE_H

#include <vector>
/**
 *@file gNode.h Header file of gNode
 *@details The gNode object is meant to represent the courses that are
 *read in via the textfile. The gNode has the fields of int inDegree to 
 *keep track of the number of pointers pointing towards it, string course
 *to know what the node's course is, and vector<gNode*> outPtrs to store the
 *nodes the current node is pointing towards.
 */
using namespace std;

class gNode{
 public:
  /**
   *@brief Default constructor for gNode
   */
  gNode();
  /**
   *@brief Custom constructor that takes in a string to initialize its course name
   *@param c c is a string that represents a course name
   */
  gNode(string c);
  /**@brief Destructor for gNode. */
  ~gNode();
  /** @brief Adds a pointer to outPtrs field, which represents the nodes the current node is pointing at.
   *@param ptr A gNode pointer that the current node is now pointing at
   *@return Does not return anything. It is a void member function.
   */
  void addPtr(gNode* ptr);
  /** @brief Increment the inDegree of a gNode. 
   *@details Function's purpose is to allow user to modify inDegree because inDegree is a private field.
   */
  void inDegreeInc();
  /** @brief Decrements the inDegree of a gNode. 
   *@details Function's purpose is to allow user to modify inDegree because inDegree is a private field.
   */
  void inDegreeDec();
  /** @brief Allows user to access the vector of pointers that represents the nodes the current node is point to
   *@details Usage of this function might be to get the vector of all the gNodes the current node is pointing to to decrement their inDegrees
   *@return A vector of gNodes.
   */
  vector<gNode*> getOutwardPtrs();
  /** @brief Accessor for the string course field
   *@return A string that represents the course of the gNode
   */
  string getCourse();
    /** @brief Accessor for the int inDegree field
   *@return An int that represents the number of nodes pointing toward the current node
   */
  int getInDegree();
  /** @brief clears the outPtrs vector when the destructor is called
   */
  void remove();
 private:
  /** Fields of the gNode object */
  string course;
  vector<gNode*> outPtrs;
  int inDegree;
};
#endif
