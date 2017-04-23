/*
Albert Wilson
Siddarth Shanmugam
Pat Coville

Project 03 Virtual Memory Paging
*/

#include "MemoryManager.h";
#include <list>


MemoryManager::MemoryManager(ReplacementPolicy policy, unsigned int pageSize, unsigned int numFrames, unsigned int virtualAddressSpaceSize)
	: virtualMemoryManagerInterface(policy, pageSize, numFrames, virtualAddressSpaceSize)
{

	this->policy = policy;
	this->pageSize = pageSize;
	this->numFrames = numFrames;
	this->virtualAddressSpaceSize = virtualAddressSpaceSize;
	
}

unsigned long long MemoryManager::memoryAccess(unsigned long long address) {

	switch (policy) {

	case ReplacementPolicy::FIFO:

		FIFO(address);


		break;

	case ReplacementPolicy::LRU:



		break;

	default:
		cout << "Incorrect replacement policy" << endl;

	}

	return address; //convert to physical address before returning

}

void MemoryManager::FIFO(unsigned long long address) {

	bool alreadyInList = false;

	//if someone is feeling ambituous and wants to make a hashtable that points to the FIFOlist and do this in O(1) feel free
	//need to verify that the virtual address is not already in the FIFOlist
	for (list<unsigned long long>::iterator itr = FIFOlist.begin(); itr != FIFOlist.end(); itr++) {
		if (*itr == address) {
			alreadyInList = true;
		}
	}

	if (alreadyInList == false) {

		if (FIFOlist.size() == virtualAddressSpaceSize) {

			FIFOlist.pop_front();
			FIFOlist.push_back(address);
			numSwaps++;

		}
		else {
			//just go ahead and add it to the queue
			FIFOlist.push_back(address);

		}
	}

}

void MemoryManager::LRU(unsigned long long address) {



}

unsigned long long MemoryManager::convertVirtualAddresstoPhysicalAddress(unsigned long long virtualAddress) {




}

