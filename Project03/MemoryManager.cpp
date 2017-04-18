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

	return address;

}

void MemoryManager::FIFO(unsigned int frames[]) {

	list<unsigned int> FIFOlist;
	numSwaps = 0; //just to make sure we start with a fresh number of numSwaps
	bool alreadyInList = false;

	for (int i = 0; i < numFrames; i++) {

		alreadyInList = false;

		//if someone is feeling ambituous and wants to make a hashtable that points to the FIFOlist and do this in O(1) feel free
		//need to verify that the value of frames[i] is not already in the FIFOlist
		for (list<unsigned int>::iterator itr = FIFOlist.begin(); itr != FIFOlist.end(); itr++) {
			if (*itr == frames[i]) {
				alreadyInList = true;
			}
		}

		if (alreadyInList == false) {

			if (FIFOlist.size() == virtualAddressSpaceSize) {

				FIFOlist.pop_front();
				FIFOlist.push_back(frames[i]);
				numSwaps++;

			}
			else {
				//just go ahead and add it to the queue
				FIFOlist.push_back(frames[i]);

			}
		}

	}

}

void MemoryManager::LRU(unsigned int frames[]) {



}

