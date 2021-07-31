#include <iostream>
#include <cstdlib>
#include <algorithm>

using namespace std;

#include "middleearth.h"

float computeDistance(MiddleEarth& me, const string& start, vector<string> dests);
void printRoute(const string& start, const vector<string>& dests);

int main(int argc, char** argv) {
    // check the number of parameters
    if (argc != 6) {
        cout << "Usage: " << argv[0] << " <world_height> <world_width> "
             << "<num_cities> <random_seed> <cities_to_visit>" << endl;
        exit(0);
    }

    // we'll assume the parameters are all well-formed
    int width = stoi(argv[1]);
    int height = stoi(argv[2]);
    int num_cities = stoi(argv[3]);
    int rand_seed = stoi(argv[4]);
    int cities_to_visit = stoi(argv[5]);

    // create the world, and select your itinerary
    MiddleEarth me(width, height, num_cities, rand_seed);
    vector<string> dests = me.getItinerary(cities_to_visit);

    // TODO: YOUR CODE HERE
    vector<string> shortestPath;
    string startCity = dests[0];
    float shortestDistance = 99999.0;
    //cout << dests.size() << endl;
    dests.erase(dests.begin());//drops the starting location since it'll always be there
    //cout << dests.size() << endl;
    sort(dests.begin(),dests.end());
    //printRoute(startCity,dests);
    
    do{
      //cout << "This is the current path: ";
      //printRoute(startCity,dests);

      //cout << "Comparing current shortest distance: " << shortestDistance << ", to current path distance: " << computeDistance(me,startCity,dests) << endl;
      //cout << endl;
      float temp = computeDistance(me, startCity, dests);
      if(shortestDistance > temp){
	shortestPath = dests;
	shortestDistance = temp;
	//cout << "This is the new shortest path: ";
	//printRoute(startCity,dests);
	//cout << endl;
	
      }
    }
    while(next_permutation(dests.begin(),dests.end()));//makes the possible routes
    //me.printTable();
    cout << "Minumum path has distance " << shortestDistance << ": ";
    printRoute(startCity,shortestPath);

    return 0;
}

// This method will compute the full distance of the cycle that starts
// at the 'start' parameter, goes to each of the cities in the dests
// vector IN ORDER, and ends back at the 'start' parameter.
float computeDistance(MiddleEarth& me, const string& start, vector<string> dests) {
    // TODO: YOUR CODE HERE
  if(dests.size() == 0){//if the TSP doesn't need to travel anywhere
    return 0;
  }
  if(dests.size() == 1){//going to and back from only one city
    return me.getDistance(start,dests[0])*2;
  }
  float total = me.getDistance(start,dests[0]);//starting city to the first city
  for(int i = 0; i < dests.size()-1; i++){//i = 0 is the first city
    total += me.getDistance(dests[i],dests[i+1]);
  }
  total += me.getDistance(start,dests[dests.size()-1]);
  return total;
}

// This method will print the entire route, starting and ending at the
// 'start' parameter.
// The output should be similar to:
// Erebor -> Khazad-dum -> Michel Delving -> Bree -> Cirith Ungol -> Erebor
void printRoute(const string& start, const vector<string>& dests) {
    // TODO: YOUR CODE HERE
  cout << start << " -> ";
  for(int i = 0; i < dests.size(); i++){
      cout << dests[i] << " -> ";
    }
  cout << start << endl;
}
