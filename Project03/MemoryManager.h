/*
Albert Wilson
Siddarth Shanmugam
Pat Coville

Project 03 Virtual Memory Paging
*/

#include "virtualMemoryManagerInterface.hpp";
#include <list>

class MemoryManager : virtualMemoryManagerInterface{

public:

	MemoryManager(ReplacementPolicy policy, unsigned int pageSize, unsigned int numFrames, unsigned int virtualAddressSpaceSize);
	unsigned long long memoryAccess(unsigned long long address);
	void FIFO(unsigned long long address);
	void LRU(unsigned long long address);
	unsigned long long convertVirtualAddresstoPhysicalAddress(unsigned long long virtualAddress);

private:
	ReplacementPolicy policy;
	unsigned int pageSize;
	unsigned int numFrames;
	unsigned int virtualAddressSpaceSize;
	list<unsigned long long> FIFOlist;
	list<unsigned long long> LRUlist;

};