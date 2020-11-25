// Honor Pledge:
// I pledge that I have neither given nor 
// received any help on this assignment.
// Clark Otte

#include "HashTableArray.h"
#include <iostream>

HashTableArray::HashTableArray(int size) : size_(size)
{
	entry_ = new HashEntry [size];
	for(int i=0; i<size_; i++)
		entry_[i] = HashEntry();
}

HashTableArray::HashTableArray()
{
	
}

HashTableArray::~HashTableArray()
{
	delete entry_;
}

void HashTableArray::insert(int key, int value)
{
	if(probe_ == linear)
	{
		int pos = key % size_;
		int n(1);
		while(entry_[pos].getStatus() == OCCUPIED && n <= size_)
		{
			pos=(key + n) % size_;
			n++;
		}
		if(n<=size_)
		{
			entry_[pos].setKey(key);
			entry_[pos].setValue(value);
			entry_[pos].setStatus(OCCUPIED);
		}
		else
		{
			std::cout<<"Hash Table Full!"<<std::endl;
		}
	}
	else if(probe_ == quadratic)
	{
		int pos = key % size_;
		int n(1);
		while(entry_[pos].getStatus() == OCCUPIED && n <= size_)
		{
			pos=(key + (n*n)) % size_; //newHashValue = (hashValue + (i * i)) % size_;

			n++;
		}
		if(n<=size_)
		{
			entry_[pos].setKey(key);
			entry_[pos].setValue(value);
			entry_[pos].setStatus(OCCUPIED);
		}
		else
		{
			std::cout<<"Hash Table Full!"<<std::endl;
		}
	}
}

int HashTableArray::search(int key)
{
	if(probe_ == linear)
	{
		int pos = key % size_;
		int n(1);
		while(entry_[pos].getStatus() != EMPTY && entry_[pos].getKey() != key && n <= size_)
		{
			pos=(key + n) % size_;
			n++;
		}
		if(entry_[pos].getKey() == key)
			return entry_[pos].getValue();
		else
			return -1;
	}
	else if(probe_ == quadratic)
	{
		int pos = key % size_;
		int n(1);
		while(entry_[pos].getStatus() != EMPTY && entry_[pos].getKey() != key && n <= size_)
		{
			pos=(key + (n*n)) % size_;
			n++;
		}
		if(entry_[pos].getKey() == key)
			return entry_[pos].getValue();
		else
			return -1;
	}
}

void HashTableArray::remove(int key)
{
	if(probe_ == linear)
	{
		int pos = key % size_;
		int n(1);
		while(entry_[pos].getStatus() != EMPTY && entry_[pos].getKey() != key && n <= size_)
		{
			pos=(key + n) % size_;
			n++;
		}
		if(entry_[pos].getKey() == key)
		{
			entry_[pos].remove();
			std::cout<<"Key "<<key<<" removed."<<std::endl;
		}
		else
			std::cout<<"Key "<<key<<"not found"<<std::endl;
	}
	else if(probe_ == quadratic)
	{
		int pos = key % size_;
		int n(1);
		while(entry_[pos].getStatus() != EMPTY && entry_[pos].getKey() != key && n <= size_)
		{
			pos=(key + (n*n)) % size_;
			n++;
		}
		if(entry_[pos].getKey() == key)
		{
			entry_[pos].remove();
			std::cout<<"Key "<<key<<" removed."<<std::endl;
		}
		else
			std::cout<<"Key "<<key<<"not found"<<std::endl;
	}
}

void HashTableArray::print()
{
	std::cout<<"*********************************"<<std::endl;
	for(int i=0; i<size_; i++)
	{
		if(entry_[i].getKey()!= -1)
			std::cout<<"["<<i<<"]: "<<entry_[i].getKey()<<std::endl;
		else
			std::cout<<"["<<i<<"]: "<<std::endl;
	}
	std::cout<<"*********************************"<<std::endl;
}

int HashTableArray::getSize()
{
	return size_;
}

Probe HashTableArray::getProbe()
{
	return probe_;
}

void HashTableArray::setSize(int size)
{
	size_=size;
}

void HashTableArray::setProbe(Probe probe)
{
	probe_=probe;
}