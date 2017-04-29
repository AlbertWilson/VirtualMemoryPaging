/*
Albert Wilson
Siddarth Shanmugam
Pat Coville

Project 03 Virtual Memory Paging
*/

#include "MemoryManager.h"

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
	unsigned int offset;
	unsigned int frameNumber;

	switch (policy) {

	case ReplacementPolicy::FIFO:

		//get the page number from virtual address
		pageNumber = (unsigned int) (address / pow(2, pageSize));
		offset = (unsigned int) (address % ((unsigned int)pow(2, pageSize)));

		//determine which frame to swap, and make the swap
		frameNumber = FIFO(pageNumber);

		return convertVirtualAddresstoPhysicalAddress(frameNumber, offset);

		break;

	case ReplacementPolicy::LRU:

		//get the page number from virtual address
		pageNumber = (unsigned int)(address / pow(2, pageSize));
		offset = (unsigned int)(address % ((unsigned int)pow(2, pageSize)));

		//determine which frame to swap, and make the swap
		frameNumber = FIFO(pageNumber);

		return convertVirtualAddresstoPhysicalAddress(frameNumber, offset);

		break;

	default:
		cout << "Incorrect replacement policy" << endl;
		exit(EXIT_FAILURE);

	}

}

unsigned int MemoryManager::FIFO(unsigned int pageNum) {

	bool alreadyInList = false;
	Frame newFrame;
	
	//if someone is feeling ambituous and wants to make a hashtable that points to the FIFOlist and do this in O(1) feel free
	//need to verify that the virtual address is not already in the FIFOlist
	for (list<Frame>::iterator itr = FIFOlist.begin(); itr != FIFOlist.end(); itr++) {
		if (itr->pageNumber == pageNum) {
			alreadyInList = true;
			return itr->frameNumber;
		}
	}

	if (alreadyInList == false) {

		if (FIFOlist.size() == numFrames) { //if the FIFOlist is full, where the memory map is at its max size

			unsigned int oldFrameNum = FIFOlist.front().frameNumber;

			newFrame = {pageNum, oldFrameNum};

			FIFOlist.push_back(newFrame);
			FIFOlist.pop_front();
			numSwaps++;

		}
		else {
			//just go ahead and add it to the queue
			unsigned int frameNum = FIFOlist.size();
			newFrame = {pageNum, frameNum};

			FIFOlist.push_back(newFrame);

		}
	}

	return newFrame.frameNumber;

}

/*
Least recently used page is at the end of the list
*/
unsigned int MemoryManager::LRU(unsigned int pageNum) {

	bool alreadyInList = false;
	Frame newFrame;

	//if someone is feeling ambituous and wants to make a hashtable that points to the FIFOlist and do this in O(1) feel free
	//need to verify that the virtual address is not already in the FIFOlist
	for (list<Frame>::iterator itr = LRUlist.begin(); itr != LRUlist.end(); itr++) {

		if (itr->pageNumber == pageNum) {

			Frame frameCopy = {pageNum, itr->frameNumber};

			alreadyInList = true;
			LRUlist.erase(itr);
			LRUlist.push_front(frameCopy);

			return frameCopy.frameNumber;
		}

	}

	if (alreadyInList == false) {

		if (LRUlist.size() == numFrames) { //if the LRUlist is full, where the memory map is at its max size

			unsigned int oldFrameNum = FIFOlist.back().frameNumber;

			newFrame = { pageNum, oldFrameNum };

			LRUlist.push_front(newFrame);
			LRUlist.pop_back();
			numSwaps++;

		}
		else {
			
			//just go ahead and add it to the queue
			unsigned int frameNum = numFrames - LRUlist.size();
			newFrame = { pageNum, frameNum };

			LRUlist.push_front(newFrame);

		}
	}

	return newFrame.frameNumber;

}

unsigned long long MemoryManager::convertVirtualAddresstoPhysicalAddress(unsigned int frameNum, unsigned int offset) {

	return frameNum * (unsigned int) pow(2, N) + offset;

}

unsigned long long MemoryManager::getNumSwaps() {

	return numSwaps;

}

