// Honor Pledge:
// I pledge that I have neither given nor 
// received any help on this assignment.
// Clark Otte
#include "HashTableChaining.h"
#include <iostream>

HashTableChaining::HashTableChaining(int size) : size_(size)
{
	entry_ = new DoubleLinkedList [size];
	for(int i=0; i<size_; i++)
		entry_[i] = DoubleLinkedList();
}

HashTableChaining::HashTableChaining()
{
	
}

HashTableChaining::~HashTableChaining()
{
	delete [] entry_;
}

void HashTableChaining::insert(int key, int value)
{
	int pos = key % size_;
	entry_[pos].insert(key, value);
}

int HashTableChaining::search(int key)
{
	int pos = key % size_;
	return entry_[pos].find(key);
}

void HashTableChaining::remove(int key)
{
	int pos = key % size_;
	entry_[pos].removeLinkedNode(key);
}

void HashTableChaining::print()
{
	std::cout<<"*********************************"<<std::endl;
	for(int i=0; i<size_; i++)
	{
		if(!entry_[i].isEmtpy())
		{
			std::cout<<"["<<i<<"]: ";
			entry_[i].printList();
		}
		else
			std::cout<<"["<<i<<"]: "<<std::endl;
	}
	std::cout<<"*********************************"<<std::endl;
}

int HashTableChaining::getSize()
{
	return size_;
}

void HashTableChaining::setSize(int size)
{
	size_=size;
}