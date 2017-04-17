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

	return address;

}

void MemoryManager::FIFO() {



}

void MemoryManager::LRU() {



}

