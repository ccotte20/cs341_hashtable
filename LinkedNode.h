// Honor Pledge:
// I pledge that I have neither given nor 
// received any help on this assignment.
// Clark Otte

#ifndef LINKEDNODE_H
#define LINKEDNODE_H
#include "Node.h"
class LinkedNode : public Node
{
	public:
		LinkedNode(int data);
		virtual ~LinkedNode();
		void setNextNode(LinkedNode * node);
		void setPrevNode(LinkedNode * node);
		bool hasNextNode();
		bool hasPrevNode();
		LinkedNode * getNextNode();
		LinkedNode * getPrevNode();
	private:
		LinkedNode * prevNode_;
		LinkedNode * nextNode_;
	protected:
		LinkedNode();
};
#endif