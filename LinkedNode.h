// Honor Pledge:
// I pledge that I have neither given nor 
// received any help on this assignment.
// Clark Otte

#ifndef LINKEDNODE_H
#define LINKEDNODE_H
#include "Node.h"
#include "HashEntry.h"
class LinkedNode : public Node
{
	public:
		LinkedNode(int data);
		LinkedNode(int data, int value);
		virtual ~LinkedNode();
		void setNextNode(LinkedNode * node);
		void setPrevNode(LinkedNode * node);
		bool hasNextNode();
		bool hasPrevNode();
		LinkedNode * getNextNode();
		LinkedNode * getPrevNode();
		HashEntry getEntry();
	private:
		HashEntry entry_;
		LinkedNode * prevNode_;
		LinkedNode * nextNode_;
	protected:
		LinkedNode();
};
#endif