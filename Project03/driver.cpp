#include "MemoryManager.h"
#include <iostream>
using namespace std;


int main() {

	memoryManager pagerFIFO = memoryManager(ReplacementPolicy::FIFO, 10, 3, 15360);

	/*
	unsigned int arr[] = 
	{ 
		0,
		12,
		262144,
		32,
		581869302,
		3586334585,
		4161255391,
		3586334585,
		1323567403,
		2350294565,
		809094426,
		4264392720,
		4279768804,
		4156218106,
		3117454609,
		4213834039,
		471852626,
		3427838553 
	};
	*/

	unsigned int arr[] =
	{
		0,
		2,
		4,
		6,
		0,
		1,
		2,
		3,
		3,
		2,
		1,
		0,
		0,
		0,
		1,
		1,
		2,
		2,
		3,
		3
	};

	for (int i = 0; i < 18; i++) {

		cout << "The page number is: " << (arr[i] / 1024) << endl;

	}

	cout << endl << endl;

	for (int i = 0; i < 18; i++) {

		cout << "The physical address of " << arr[i] <<  " is: " << pagerFIFO.memoryAccess(arr[i]) << endl;

	}

	cout << "The total number of page swaps is: " << pagerFIFO.getNumSwaps() << endl << endl;

	memoryManager pagerLRU = memoryManager(ReplacementPolicy::LRU, 10, 3, 15360);

	for (int i = 0; i < 18; i++) {

		cout << "The page number is: " << (arr[i] / 1024) << endl;

	}

	cout << endl << endl;

	for (int i = 0; i < 18; i++) {

		cout << "The physical address of " << arr[i] << " is: " << pagerLRU.memoryAccess(arr[i]) << endl;

	}

	cout << "The total number of page swaps is: " << pagerLRU.getNumSwaps() << endl;

	return 0;
}
