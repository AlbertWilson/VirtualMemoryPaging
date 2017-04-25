/*
Albert Wilson
Siddarth Shanmugam
Pat Coville

Project 03 Virtual Memory Paging
*/

#include "virtualMemoryManagerInterface.hpp"
#include <list>

struct Frame {

	unsigned int pageNumber;
	unsigned int frameNumber;

};

class MemoryManager : virtualMemoryManagerInterface{

public:

	MemoryManager(ReplacementPolicy policy, unsigned int pageSize, unsigned int numFrames, unsigned int virtualAddressSpaceSize);
	unsigned long long memoryAccess(unsigned long long address);
	void FIFO(unsigned int pageNum);
	void LRU(unsigned int pageNum);
	unsigned long long convertVirtualAddresstoPhysicalAddress();

private:
	ReplacementPolicy policy;
	unsigned int pageSize;
	unsigned int numFrames;
	unsigned int virtualAddressSpaceSize;
	list<Frame> FIFOlist;
	list<Frame> LRUlist;

};
