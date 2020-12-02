// Honor Pledge:
// I pledge that I have neither given nor 
// received any help on this assignment.
// Clark Otte
#include "Node.h"

Node::Node(int data) : data_(data)
{
	
}

// Dr. Ryan: We should avoid using -1 as it might be a real value.
Node::Node() : data_(-1)
{
	
}

void Node::setData(int data)
{
	data_ = data;
}

int Node::getData()
{
	return data_;
}