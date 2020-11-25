// Honor Pledge:
// I pledge that I have neither given nor 
// received any help on this assignment.
// Clark Otte
#ifndef HASHTABLE_H
#define HASHTABLE_H
class HashTable
{
	public:
		virtual ~HashTable() {}
		virtual void insert(int key, int value) = 0;
		virtual int search(int key) = 0;
		virtual void remove(int key) = 0;
		virtual void print() = 0;
	protected:
		HashTable() {}
};
#endif