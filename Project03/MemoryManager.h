/*
Albert Wilson
Siddarth Shanmugam
Pat Coville

Project 03 Virtual Memory Paging
*/

#include "virtualMemoryManagerInterface.hpp"
#include <list>
#include <map>

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
	list<unsigned int> FIFOlist;
	list<unsigned int> LRUlist;

};
