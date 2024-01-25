#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <time.h>
#include <vector>
#include <string>
#include <algorithm>

#include "MergeSortedArrays.h"
#include "Dijkstra.h"
using namespace std;

static const string DIJKSTRA1 = "dijkstra1.txt";
static const string DIJKSTRA2 = "dijkstra2.txt";

static void printArray(int *A, int len) {
	if (len == 0) {
		cout << "[]";
		return;
	}
	cout << "[";
	for (int i = 0; i < len - 1; i++) {
		cout << A[i] << ", ";
	}
	cout << A[len - 1] << "]";
}

static void printVector(vector<int> &vect) {
	if (vect.size() == 0) {
		cout << "[]";
		return;
	}
	cout << "[";
	for (int i = 0; i < vect.size() - 1; i++) {
		cout << vect.at(i) << ", ";
	}
	cout << vect.at(vect.size() - 1) << "]";
}

static vector<vector<int> > arraysToLists(int **arrays, int *arrayLengths,
		int n) {
	vector<vector<int> > lists;
	lists.reserve(n);
	for (int i = 0; i < n; i++) {
		vector<int> list;
		list.reserve(arrayLengths[i]);
		for (int j = 0; j < arrayLengths[i]; j++)
			list.push_back(arrays[i][j]);
		lists.push_back(list);
	}
	return lists;
}

static void testKSortedMerge() {
	cout << "*** Test Merging k Sorted Arrays ***\n" << endl;
	int list0[] = { 1, 5, 9, 18 };
	int list1[] = { -10, 5, 18, 67, 100 };
	int list2[] = { -12, -9, -6, 0, 1, };
	int list3[] = { -65, -32, 10, };
	int list4[] = { 1, 19, 45, 67 };
	int *lists[] = { list0, list1, list2, list3, list4 };
	int k;

	k = 5;
	MergeSortedArrays merge;
	int eachListLength1[] = { 4, 5, 5, 3, 4 };
	cout << "Original sorted arrays" << endl;
	for (int i = 0; i < k; i++) {
		printArray(lists[i], eachListLength1[i]);
		cout << endl;
	}
	vector<vector<int> > list = arraysToLists(lists, eachListLength1, k);
	vector<int> mergedList = merge.kWayMerge(list);
	cout << endl << "Final merged array:";
	printVector(mergedList);

	k = 4;
	int eachListLength2[] = { 4, 5, 5, 3 };
	cout << endl << endl << "Original sorted arrays" << endl;
	for (int i = 0; i < k; i++) {
		printArray(lists[i], eachListLength2[i]);
		cout << endl;
	}
	list = arraysToLists(lists, eachListLength2, k);
	mergedList = merge.kWayMerge(list);
	cout << "\nFinal merged array:";
	printVector(mergedList);

	k = 2;
	int eachListLength3[] = { 4, 5 };
	list = arraysToLists(lists, eachListLength3, k);
	mergedList = merge.kWayMerge(list);
	cout << endl << endl << "Original sorted arrays" << endl;
	for (int i = 0; i < k; i++) {
		printArray(lists[i], eachListLength2[i]);
		cout << endl;
	}
	cout << "\nFinal merged array:";
	printVector(mergedList);

	k = 1;
	int eachListLength4[] = { 4 };
	list = arraysToLists(lists, eachListLength4, k);
	mergedList = merge.kWayMerge(list);
	cout << endl << endl << "Original sorted arrays" << endl;
	for (int i = 0; i < k; i++) {
		printArray(lists[i], eachListLength2[i]);
		cout << endl;
	}
	cout << "\nFinal merged array:";
	printVector(mergedList);
}

void testDijkstra() {
	cout << endl;
	string filePaths[] = { DIJKSTRA1, DIJKSTRA2 };
	for (int j = 0; j < 2; j++) {
		cout << "\n*** Test Dijkstra (" << filePaths[j] << ") ***" << endl;
		Dijkstra dijk(filePaths[j]);
		for (int i = 0; i < dijk.numVertices; i++) {
			dijk.executeDijkstra(i);
			cout << "\nDistance array (from v" << i << "): ";
			dijk.printDistanceArray();
			cout << endl;
			cout << "Parent array (from v" << i << "):   ";
			dijk.printParentArray();
			cout << endl;
		}
	}
}

int main() {
	testKSortedMerge();
	testDijkstra();
	return 1;
}
