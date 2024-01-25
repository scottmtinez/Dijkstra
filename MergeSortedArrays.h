#include <climits>
#include <iostream>
#include <queue>
#include <vector>

#include "Element.h"
#include "ElementComparator.h"
#include "Graph.h"
using namespace std;

#ifndef MERGESORTEDARRAYS_H_
#define MERGESORTEDARRAYS_H_

class MergeSortedArrays {

public:

	static vector<int> kWayMerge(vector<vector<int> > &lists) { // complete this function
    //Create a priority queue and a dynamic array.
      priority_queue<Element, vector<Element>, ElementComparator> priorityQueue;
      vector<int> dynamicArray;
    
    //Insert the first number of each row of lists into the priority queue – the item is the row index and the priority is the number itself.
    for(int i = 0; i < lists.size(); i++)
      {
        priorityQueue.push(Element(i, lists.at(i).at(0)));
      }
      
    //Create an array indexes having the same length as lists. Fill the array with 1.
      int indexes[lists.size()];
      for(int i = 0; i < lists.size(); i++)
        {
          indexes[i] = 1;
        }
        
    //As long as (the priority queue is not empty), do the following:
      while(priorityQueue.size() > 0)
        {
          //Extract the minimum element from the priority queue
            Element minElement = priorityQueue.top();
            priorityQueue.pop();

          //Add the priority of the minimum element to the dynamic array.
            dynamicArray.push_back(minElement.priority);
            
          //Let minItem be the item of minimum element
            int minItem = minElement.item;

          //If indexes[minItem] is less than the size of the row at index minItem, then
                if(indexes[minItem] < lists.at(minItem).size())
                  {
                    //insert a new element into the priority queue – for this new element, the item is minItem and priority is the value at row minItem and column indexes[minItem]
                      priorityQueue.push(Element(minItem, lists.at(minItem).at(indexes[minItem])));

                    //increment indexes[minItem]
                      indexes[minItem]++;
                  }

        }

    //Return the dynamic array.
      return dynamicArray;
	}
};
#endif /* MERGESORTEDARRAYS_H_ */
