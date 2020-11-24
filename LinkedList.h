// Honor Pledge:
// I pledge that I have neither given nor 
// received any help on this assignment.
// Clark Otte
#include "List.h"
#include "LinkedNode.h"
#ifndef LINKEDLIST_H
#define LINKEDLIST_H
class LinkedList : public List
{
	public:
		LinkedList();
		virtual ~LinkedList();
		virtual void printList();
		virtual int getLength();
		virtual bool isEmpty();
		virtual void insert(int data);
		virtual void remove(int element);
		void insertLinkedNode(LinkedNode * node, int data);
		void removeLinkedNode(int data);
		void setHead(LinkedNode * node);
		void setTail(LinkedNode * node);
		LinkedNode * getHead();
		LinkedNode * getTail();
	private:
		LinkedNode * head_;
		LinkedNode * tail_;
};
#endif