#ifndef MIDDLEEARTH_H
#define MIDDLEEARTH_H

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <random>

using namespace std;

// see the comments in the lab11 write-up, or in middleearth.cpp
/** @file middleearth.h Header file for MiddleEarth object
 *  @brief Description of methods and fields in middleearth.cpp 
 */
class MiddleEarth {
public:
  /**
 *@note Iluvatar, the creator of Middle-Earth
 *@brief Constructor of MiddleEarth
 *@return Nothing is returned. This is the constructor for MiddleEarth Object
 *@param xsize xsize is an int that determines the x length of MiddleEarth
 *@param ysize ysize is an int that determines the y length of MiddleEarth
 *@param seed seed is a randomly generated int that is associated with this MiddleEarth
 *@param num_cities num_cities is an int that determines how many cities are in this MiddleEarth
 */
  MiddleEarth(int xsize, int ysize, int num_cities, int seed);
  /**
 *@note The Mouth of Sauron!
 *@brief Prints out info on the created 'world'
 *@return Does not return anything. It is a void member function of MiddleEarth
 */
  void print();
  /**
 *@brief Prints a tab-separated table of the distances, which can be loaded into Excel or similar
 *@return Does not return anything. It is a void member function of MiddleEarth
 */
  void printTable();
  /**
 *@brief This method returns the distance between the two passed cities.
 *@details If we assume that the hash table (i.e. the map) is O(1),
 *then this method call is also O(1). This can also be used to find the 
 *weight/cost of each path between cities.
 *@return Returns the distance of the distance between the two inputted cities
 *@param city1 A city in the MiddleEarth object. It is a const string&.
 *@param city2 A city in the MiddleEarth object. It is a const string&.
 */
  float getDistance(const string& city1, const string& city2);
  /**
 *@brief Gets a vector of strings that represents the cities travelled to.
 *@details The first city is the original start point as well as the end point.
 *The number of cities passed in does not include this start/end point
 *(so there will be length+1 entries in the returned vector).
 *@return Returns the list of cities to travel to.
 */
  vector<string> getItinerary(unsigned int length);

private:
  /** @brief Fields of the MiddleEarth object */
  int num_city_names, xsize, ysize;
  unordered_map<string, float> xpos, ypos;
  vector<string> cities;
  unordered_map<string, unordered_map<string, float>> distances;
  /** @brief Mersenne-Twister random number engine */
  mt19937 gen; // Mersenne-Twister random number engine
};

#endif
