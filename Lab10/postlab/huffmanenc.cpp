//Justin Liu, jl8wf    Date:11/01/2020     Filename: huffmanenc.cpp
#include "heap.h"
#include "hNode.h"
#include <map>
#include <vector>
#include <string>
#include <algorithm>

#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

  int main(int argc, char** argv) {
    // verify the correct number of parameters
    if (argc != 2) {
        cout << "Must supply the input file name as the one and only parameter" << endl;
        exit(1);
    }

    // attempt to open the supplied file
    // ifstream stands for "input file stream"
    ifstream file(argv[1]);
    // if the file wasn't found, output an error message and exit
    if (!file.is_open()) {
        cout << "Unable to open '" << argv[1] << "' for reading" << endl;
        exit(2);
    }

    map<string,int> tbl;
    heap mHeap;
    vector<string> unique = vector<string>();
    // read in characters one by one, until reading fails (we hit the end of the file)
    char g;
    int distinct = 0;
    int total = 0;
    while (file.get(g)) {//everything in file goes into a map that has the keys as the chars and the 
      if(g > '~' || g < ' ')
	continue;
      string s(1,g);
      map<string,int>::iterator it = tbl.find(s);
      if(it == tbl.end()){//for the first time seeing a new character
	tbl[s] = 1;
	distinct++;
	unique.push_back(s);//vector of unique characters
      }
      else{//for second or higher occurances
	it->second++;

      }
      total++;
    }
    //TODO: Get frequency values in table to heap
    for(pair<string,int> key: tbl){
      	// if(key.first == ' '){
	//   cout << "space has frequency: " << key.second << endl;
	// }
	// else{
	//   cout << key.first << " has frequency: " << key.second << endl;
	// }
      hNode* l = new hNode(key.first,key.second);
      mHeap.insert(l);
    }
    //mHeap.print();

    // once we hit the end of the file we are marked as "failed", so clear that
    // then "seek" to the beginning of the file to start again
    file.clear(); // Clears the _state_ of the file, not its contents!
    file.seekg(0);

    int count = 0;
    while(mHeap.size() > 1){//minheap to huffman tree
      hNode* firstMin = mHeap.deleteMin();
      //cout << "FirstMin is: " << firstMin->getValue() << ". Frequency of firstMin: " << firstMin->getFrequency() << endl;
      hNode* secondMin = mHeap.deleteMin();
      // cout << "SecondMin is: " << secondMin->getValue() << ". Frequency of SecondMin: " << secondMin->getFrequency() << endl;
      int dummyFrequency = firstMin->getFrequency() + secondMin->getFrequency();
      //cout << "Frequency of dummy node is: " << dummyFrequency << endl;
      count++;
      string temp = "T" + to_string(count);
      hNode* dummy = new hNode(temp, dummyFrequency);
      dummy->setLeft(firstMin);
      dummy->setRight(secondMin);
      mHeap.insert(dummy);
    }

    double cost = 0.0;
    for(int i = 0; i < unique.size(); i++){//printing characters with their codes
      vector<string> prefix = vector<string>();
      string fileCode = "";
      if(unique[i] == " ")
	cout << "space ";
      else
	cout << unique[i] << " ";
      mHeap.printCode(mHeap.getRoot(),unique[i],prefix,fileCode);
      cout << endl;
      cost += ((double)tbl[unique[i]]/total) * (fileCode.length()-1);
    }  


    cout << "----------------------------------------" << endl;

    string fileCode = "";
    vector<string> prefix = vector<string>();
    //TODO: get frequency / total, then multiply this by the length of the encoded bits
    // Read the file again, and print to the screen the file encoded
    while (file.get(g)) {
      if(g > '~' || g < ' '){
	continue;
      }
      string s(1,g);
      string compressed = "";
      mHeap.printCode(mHeap.getRoot(),s,prefix,compressed);
      fileCode += compressed;
      //if(g == ' '){
	//cout << "Searching for space" << endl;
	//cout << "Root is: " << mHeap.getRoot()->getValue() << endl;
	//fileCode += mHeap.printCode(mHeap.getRoot(),s,prefix);
	//cout << mHeap.printCode(mHeap.getRoot(),s) << endl;
      //}
      //else{
	//cout << "Searching for " << s << endl;
	//cout << "Root is: " << mHeap.getRoot()->getValue() << endl;
	//fileCode += mHeap.printCode(mHeap.getRoot(),s,prefix);
	//cout << mHeap.printCode(mHeap.getRoot(),s) << endl;
      //}
    }
    cout << endl;
    
    // close the file
    file.close();
    cout << "----------------------------------------" << endl;
    
    fileCode.erase(remove(fileCode.begin(), fileCode.end(), ' '),fileCode.end());
    //cout << fileCode << endl;
    
    cout << "There are a total of " << total<< " symbols that are encoded" << endl;
    cout << "There are " << distinct << " distinct symbols used." << endl;
    cout << "There were " << total*8 << " bits in the original file." << endl;
    cout << "There were " << fileCode.length() << " bits in the compressed file." << endl;
    cout << "This gives a compression ratio of " << total*8.0/fileCode.length() << endl;
    cout << "The cost of the Huffman tree is " << cost << " its per character." << endl;


    
  return 0;
}

