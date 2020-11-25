// Honor Pledge:
// I pledge that I have neither given nor 
// received any help on this assignment.
// Clark Otte

#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H
#include "LinkedList.h"
class DoubleLinkedList : public LinkedList
{
	public:
		DoubleLinkedList();
		virtual ~DoubleLinkedList() {}
		virtual bool isEmtpy();
		virtual int getLength();
		virtual void insert(int element);
		void insert(int element, int value);
		int find(int data);
		virtual void printList();
		virtual void insertLinkedNode(LinkedNode * node, int data);
		virtual void removeLinkedNode(int data);
		void insertAfter(LinkedNode * node, int data);
		void insertBefore(LinkedNode * node, int data);
};
#endif