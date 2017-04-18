/*
Albert Wilson
Siddarth Shanmugam
Pat Coville

Project 03 Virtual Memory Paging
*/

#include "virtualMemoryManagerInterface.hpp";

class MemoryManager : virtualMemoryManagerInterface{

public:

	MemoryManager(ReplacementPolicy policy, unsigned int pageSize, unsigned int numFrames, unsigned int virtualAddressSpaceSize);
	unsigned long long memoryAccess(unsigned long long address);
	void FIFO(unsigned int frames[]);
	void LRU(unsigned int frames[]);

private:
	ReplacementPolicy policy;
	unsigned int pageSize;
	unsigned int numFrames;
	unsigned int virtualAddressSpaceSize;

};