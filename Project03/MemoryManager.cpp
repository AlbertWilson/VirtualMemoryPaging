/*
Albert Wilson
Siddarth Shanmugam
Pat Coville

Project 03 Virtual Memory Paging
*/

#include "MemoryManager.h";


MemoryManager::MemoryManager(ReplacementPolicy policy, unsigned int pageSize, unsigned int numFrames, unsigned int virtualAddressSpaceSize) {

	this->policy = policy;
	this->pageSize = pageSize;
	this->numFrames = numFrames;
	this->virtualAddressSpaceSize = virtualAddressSpaceSize;
	
}

void MemoryManager::FIFO() {



}

void MemoryManager::LRU() {



}

