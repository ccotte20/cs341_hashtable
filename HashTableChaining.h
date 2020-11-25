// Honor Pledge:
// I pledge that I have neither given nor 
// received any help on this assignment.
// Clark Otte
#ifndef HASHTABLECHAINING_H
#define HASHTABLECHAINING_H
#include "DoubleLinkedList.h"
#include "HashTable.h"

class HashTableChaining : public HashTable
{
	public:
		HashTableChaining(int size);
		~HashTableChaining();
		void insert(int key, int value);
		int search(int key);
		void remove(int key);
		void print();
		int getSize();
		void setSize(int size);
	private:
		DoubleLinkedList * entry_;
		int size_;
	protected:
		HashTableChaining();
};
#endif