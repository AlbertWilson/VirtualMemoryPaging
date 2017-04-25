/*
Albert Wilson
Siddarth Shanmugam
Pat Coville

Project 03 Virtual Memory Paging
*/

#include "MemoryManager.h";


MemoryManager::MemoryManager(ReplacementPolicy policy, unsigned int pageSize, unsigned int numFrames, unsigned int virtualAddressSpaceSize)
	: virtualMemoryManagerInterface(policy, pageSize, numFrames, virtualAddressSpaceSize)
{

	this->policy = policy;
	this->pageSize = pageSize;
	this->numFrames = numFrames;
	this->virtualAddressSpaceSize = virtualAddressSpaceSize;
	
}

unsigned long long MemoryManager::memoryAccess(unsigned long long address) {

	unsigned int pageNumber;

	switch (policy) {

	case ReplacementPolicy::FIFO:

		//get the page number from virtual address
		pageNumber = address / pageSize;

		//do the mapping from page to frame

		//determine which frame to swap, and make the swap
		FIFO(address);

		//return the physical address of 

		break;

	case ReplacementPolicy::LRU:



		break;

	default:
		cout << "Incorrect replacement policy" << endl;

	}

	return address; //convert to physical address before returning

}

void MemoryManager::FIFO(unsigned int pageNum) {

	bool alreadyInList = false;

	//if someone is feeling ambituous and wants to make a hashtable that points to the FIFOlist and do this in O(1) feel free
	//need to verify that the virtual address is not already in the FIFOlist
	for (list<unsigned int>::iterator itr = FIFOlist.begin(); itr != FIFOlist.end(); itr++) {
		if (*itr == pageNum) {
			alreadyInList = true;
		}
	}

	if (alreadyInList == false) {

		if (FIFOlist.size() == numFrames) { //if the FIFOlist is full, where the memory map is equal to the size of the physical memory

			FIFOlist.pop_front();
			FIFOlist.push_back(pageNum);
			numSwaps++;

		}
		else {
			//just go ahead and add it to the queue
			FIFOlist.push_back(pageNum);

		}
	}

}

/*
Least recently used page is at the end of the list
*/
void MemoryManager::LRU(unsigned int pageNum) {

	bool alreadyInList = false;

	//if someone is feeling ambituous and wants to make a hashtable that points to the FIFOlist and do this in O(1) feel free
	//need to verify that the virtual address is not already in the FIFOlist
	for (list<unsigned int>::iterator itr = LRUlist.begin(); itr != LRUlist.end(); itr++) {

		if (*itr == pageNum) {
			alreadyInList = true;
			LRUlist.erase(itr);
			LRUlist.push_front(pageNum);
		}

	}

	if (alreadyInList == false) {

		if (LRUlist.size() == numFrames) { //if the FIFOlist is full, where the memory map is equal to the size of the physical memory

			LRUlist.pop_back();
			LRUlist.push_front(pageNum);
			numSwaps++;

		}
		else {
			//just go ahead and add it to the queue
			LRUlist.push_front(pageNum);

		}
	}

}

unsigned long long MemoryManager::convertVirtualAddresstoPhysicalAddress() {


	
	return 1;

}

