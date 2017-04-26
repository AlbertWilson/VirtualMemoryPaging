#include "MemoryManager.h"
#include <iostream>
using namespace std;


int main() {

	MemoryManager pager = MemoryManager(ReplacementPolicy::FIFO, 10, 3, 15360);

	unsigned int arr[] = { 100, 2500, 5436, 5450, 7893 , 6950, 10000, 500, 10500, 12000, 2, 9801, 3010, 4000, 6500, 7300, 8250,9380 };

	for (int i = 0; i < 18; i++) {

		cout << "The page number is: " << (arr[i] / 1024) << endl;

	}

	cout << endl << endl;

	for (int i = 0; i < 18; i++) {

		cout << "The physical address of " << arr[i] <<  " is: " << pager.memoryAccess(arr[i]) << endl;

	}

	cout << "The total number of page swaps is: " << pager.getNumSwaps() << endl;

	return 0;
}
