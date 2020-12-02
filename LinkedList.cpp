// Honor Pledge:
// I pledge that I have neither given nor 
// received any help on this assignment.
// Clark Otte
#include "LinkedList.h"
// Dr. Ryan: Why not include this in the Header to ensure it is only included once per project?
#include <iostream>

LinkedList::LinkedList()
{
	head_ = nullptr;
	tail_ = nullptr;
}

LinkedList::~LinkedList()
{
	delete head_;
}

bool LinkedList::isEmpty()
{
	if(head_==nullptr)
		return true;
	else
		return false;
}

void LinkedList::printList()
{
	LinkedNode * ptr = head_;
	while(ptr->getNextNode() != nullptr)
	{
		std::cout<<ptr->getData()<<" ";
		ptr = ptr->getNextNode();
	}
	std::cout<<tail_->getData()<<std::endl;
}

int LinkedList::getLength()
{
	int count(0);
	LinkedNode * temp = head_;
	while(temp->getNextNode() != nullptr)
	{
		temp = temp->getNextNode();
		count++;
	}
	count++;
	return count;
}

void LinkedList::insert(int data)
{
	LinkedNode * newNode = new LinkedNode(data);
	insertLinkedNode(newNode, data);
}

void LinkedList::remove(int element)
{
	removeLinkedNode(element);
}

void LinkedList::insertLinkedNode(LinkedNode * node, int data)
{
	if(head_ == nullptr)
	{
		head_=node;
		tail_=node;
	}
	else
	{
		tail_->setNextNode(node);
		tail_=node;
	}
}

void LinkedList::removeLinkedNode(int data)
{
	//check if list is empty
	if(data == head_->getData())
	{
		if(head_->hasNextNode())
		{
			LinkedNode * nextNode = head_->getNextNode();
			LinkedNode * oldHead = head_;
			head_ = nextNode;
			
			oldHead->setNextNode(nullptr);
			delete oldHead;
		}
		else
		{
			LinkedNode * removeNode = head_;
			
			head_ = nullptr;
			tail_ = nullptr;
			
			removeNode->setNextNode(nullptr);
			delete removeNode;
		}
	}
	else if(data == tail_->getData())
	{
		LinkedNode * curNode = head_;
		LinkedNode * oldTail = tail_;
		
		while(curNode->getNextNode() != tail_)
		{
			curNode = curNode->getNextNode();
		}
		curNode->setNextNode(nullptr);
		tail_ = curNode;
		
		oldTail->setNextNode(nullptr);
		delete oldTail;
	}
	else
	{
		LinkedNode * prevNode = head_;
		
		while(prevNode->getNextNode()->getData() != data && prevNode->getNextNode() != tail_)
		{
			prevNode = prevNode->getNextNode();
		}
		
		if(prevNode->getNextNode() == tail_) 
		{
			std::cout << "Element " << data << " not found"<<std::endl;
		}
		else
		{
			LinkedNode * newNextNode = prevNode->getNextNode()->getNextNode();
			LinkedNode * removeNode = prevNode->getNextNode();
		
			prevNode->setNextNode(newNextNode);
			
			removeNode->setNextNode(nullptr);
			delete removeNode;
		}
	}
}

void LinkedList::setHead(LinkedNode * node)
{
	head_ = node;
}

void LinkedList::setTail(LinkedNode * node)
{
	tail_ = node;
}

LinkedNode * LinkedList::getHead()
{
	return head_;
}

LinkedNode * LinkedList::getTail()
{
	return tail_;
}