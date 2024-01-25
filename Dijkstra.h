#include <climits>
#include <iostream>
#include <queue>
#include <vector>

#include "Element.h"
#include "ElementComparator.h"
#include "Graph.h"
using namespace std;

#ifndef DIJKSTRA_H_
#define DIJKSTRA_H_

class Dijkstra: public Graph {

private:
	bool *closed;

public:

	int *distance, *parent;

	Dijkstra(string &filePath) {
		readWeightedGraph(filePath);
		distance = new int[numVertices];
		parent = new int[numVertices];
		closed = new bool[numVertices];
	}

	~Dijkstra() {
		delete[] distance;
		delete[] parent;
		delete[] closed;
	}

	void executeDijkstra(int source) { // complete this function
    //Set all cells of distance[ ] array to ∞, all cells of parent[ ] array to −1, and all cells of closed[ ] array to false
      for(int i = 0; i < numVertices; i++)
        {
          distance[i] = INT_MAX;
          parent[i] = -1;
          closed[i] = false;
        }
      
    //Set distance[source] to 0
      distance[source] = 0;
    
    //Create a priority queue open
      priority_queue<Element, vector<Element>, ElementComparator> open;
    
    //Insert source (as item) into open with priority 0
      int priority = 0;
      open.push(Element(source, priority));
    
    //As long as (open is not empty), do the following:
      while(open.size() > 0)
        {
          //Let minElement be the element obtained by extracting open
            Element minElement = open.top();
            open.pop();

          //Let minVertex be the item in minElement
            int minVertex = minElement.item;

          //If minVertex is closed then this vertex has already been relaxed. So, continue and skip the remainder of the code in this loop
            if(closed[minVertex] != false)
              {
                continue; //break; doesnt work here has to be continue
              }

          //for (each outgoing edge adjEdge of minVertex), do the following: 
              for(int i = 0; i < adjList.at(minVertex).size(); i++)
                {
                  //Let adjVertex be the destination of adjEdge
                    Edge adjEdge = adjList.at(minVertex).at(i);
                    int adjVertex = adjEdge.dest;

                  //If (adjVertex is not closed), do the following:
                    if(closed[adjVertex] == false)
                      {
                        //Let newDist be distance[minVertex] + adjEdge weight
                            int newDist = distance[minVertex] + adjEdge.weight;

                        //Use Dijkstra’s edge relaxation rule (i.e., when newDist < distance[adjVertex]) to update distance[adjVertex], parent[adjVertex], and insert adjVertex (as item) into open with priority newDist.
                          if(newDist < distance[adjVertex])
                            {
                              open.push(Element(adjVertex, newDist)); //Inserting adjVertex into newDist
                              distance[adjVertex] = newDist; //Update distance
                              parent[adjVertex] = minVertex; //Update parent
                            }
                      }
                }

        }
        
    
    
    
	}

	void printDistanceArray() {
		cout << "[";
		for (int i = 0; i < numVertices - 1; i++) {
			if (distance[i] == INT_MAX)
				cout << "infty, ";
			else
				cout << distance[i] << ", ";
		}
		if (distance[numVertices - 1] == INT_MAX)
			cout << "infty]";
		else
			cout << distance[numVertices - 1] << "]";
	}

	void printParentArray() {
		cout << "[";
		for (int i = 0; i < numVertices - 1; i++) {
			cout << parent[i] << ", ";
		}
		cout << parent[numVertices - 1] << "]";
	}
};

#endif
