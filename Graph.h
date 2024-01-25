#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Edge.h"
using namespace std;

#ifndef GRAPH_H_
#define GRAPH_H_

class Graph {

public:

	int numVertices;
	vector<vector<Edge> > adjList;

	Graph() {
		numVertices = 0;
	}

	~Graph() {
	}

	void readWeightedGraph(string &filePath) { // complete this function
    //C++: Create an input file stream fileReader on filePath.
      ifstream fileReader(filePath, ios::in);

    //Read the number of vertices into the class-variable numVertices.
      fileReader >> numVertices;

    //Allocate numVertices rows for adjList
      adjList.reserve(numVertices);
    
    //for (i = 0 to i < numVertices), do the following:
      for(int i = 0; i < numVertices; i++)
        {
          //add a blank row to adjList
            adjList.push_back(vector<Edge>());
        }

    //Read remaining lines of the file one at a time, and do the following:
      while(!fileReader.eof()) 
        {       
          //declare three integer variables src, dest, and weight
            int src, dest, weight;
            
          //use fileReader to read from the file into these 3 variables respectively
            fileReader >> src;
            fileReader >> dest;
            fileReader >> weight;
            
          //create an edge e by calling the Edge constructor with arguments src, dest, and weight respectively
            Edge e(src, dest, weight);

          //add the edge e to the end of adjList[src]
            adjList.at(src).push_back(e);
        }

    //After the loop, close fileReader.
      fileReader.close();

	}
};

#endif /* GRAPH_H_ */
