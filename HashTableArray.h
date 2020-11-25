// Honor Pledge:
// I pledge that I have neither given nor 
// received any help on this assignment.
// Clark Otte
enum Probe { linear, quadratic };
#ifndef HASHTABLEARRAY_H
#define HASHTABLEARRAY_H
#include "HashEntry.h"
#include "HashTable.h"

class HashTableArray : public HashTable
{
	public:
		HashTableArray(int size);
		~HashTableArray();
		void insert(int key, int value);
		int search(int key);
		void remove(int key);
		void print();
		int getSize();
		Probe getProbe();
		void setSize(int size);
		void setProbe(Probe probe);
	private:
		HashEntry * entry_;
		int size_;
		Probe probe_;
	protected:
		HashTableArray();
};
#endif