// Honor Pledge:
// I pledge that I have neither given nor 
// received any help on this assignment.
// Clark Otte
#include "DoubleLinkedList.h"
// Dr. Ryan: Why not include this in the Header to ensure it is only included once per project?
#include <iostream>
DoubleLinkedList::DoubleLinkedList() : LinkedList()
{
	
}

bool DoubleLinkedList::isEmtpy()
{
	if(LinkedList::getHead()==nullptr)
		return true;
	else
		return false;
}

int DoubleLinkedList::getLength()
{
	if(!isEmtpy())
	{
		int count(0);
		LinkedNode * temp = LinkedList::getHead();
		while(temp->getNextNode() != nullptr)
		{
			temp = temp->getNextNode();
			count++;
		}
		count++;
		return count;
	}
	else
		return 0;
}

void DoubleLinkedList::insert(int element)
{
	LinkedNode * newNode = new LinkedNode(element);
	insertLinkedNode(newNode, element);
}

void DoubleLinkedList::insert(int element, int value)
{
	LinkedNode * newNode = new LinkedNode(element, value);
	insertLinkedNode(newNode, element);
}

int DoubleLinkedList::find(int data)
{
	if(!isEmtpy())
	{
		LinkedNode * temp = LinkedList::getHead();
		while(temp->getNextNode() != nullptr)
		{
			if(temp->getData() == data)
			{
				return temp->getEntry().getValue();
			}
			else
				temp = temp->getNextNode();
		}
		
		if(LinkedList::getTail()->getData() == data)
			return LinkedList::getTail()->getEntry().getValue();
		else
			return -1;
	}
	else
	{
		return -1;
	}
}

void DoubleLinkedList::printList()
{
	if(!isEmtpy())
	{
		LinkedNode * ptr = LinkedList::getHead();
		while(ptr->getNextNode() != nullptr)
		{
			std::cout<<ptr->getData()<<"<-->";
			ptr = ptr->getNextNode();
		}
		std::cout<<LinkedList::getTail()->getData()<<std::endl;
	}
}

void DoubleLinkedList::insertLinkedNode(LinkedNode * node, int data)
{
	if(isEmtpy())
	{
		setHead(node);
		setTail(node);
	}
	else
	{
		LinkedList::getTail()->setNextNode(node);
		node->setPrevNode(LinkedList::getTail());
		LinkedList::setTail(node);
	}
}

void DoubleLinkedList::removeLinkedNode(int data)
{
	if(!isEmtpy())
	{
		// 3 options - head, tail, in the list
		if(LinkedList::getHead()->getData() == data)
		{
			LinkedNode * oldHead = LinkedList::getHead();
			
			if(oldHead->hasNextNode())
			{
				LinkedNode * curNextNode = oldHead->getNextNode();
				
				curNextNode->setPrevNode(nullptr);
				oldHead->setNextNode(nullptr);
				
				LinkedList::setHead(curNextNode);
			}
			else
			{
				LinkedList::setHead(nullptr);
				LinkedList::setTail(nullptr);
			}
			
			delete oldHead;
			std::cout<<"Key "<<data<<" removed"<<std::endl;
		}
		else if(LinkedList::getTail()->getData() == data)
		{
			LinkedNode * oldTail = LinkedList::getTail();
			LinkedNode * newTail = oldTail->getPrevNode();
			
			newTail->setNextNode(nullptr);
			oldTail->setPrevNode(nullptr);
			
			LinkedList::setTail(newTail);
			
			delete oldTail;
			std::cout<<"Key "<<data<<" removed"<<std::endl;
		}
		else
		{
			LinkedNode * currentLinkedNode = LinkedList::getHead();
			bool isFound = false;
			
			while(currentLinkedNode->hasNextNode())
			{
				if(currentLinkedNode->getData() == data)
				{
					LinkedNode * oldNode = currentLinkedNode;
					
					oldNode->getPrevNode()->setNextNode(oldNode->getNextNode());
					oldNode->getNextNode()->setPrevNode(oldNode->getPrevNode());
					
					oldNode->setPrevNode(nullptr);
					oldNode->setNextNode(nullptr);
					
					delete oldNode;
					
					isFound = true;
					
					std::cout<<"Key "<<data<<" removed"<<std::endl;
					
					break;
				}
				
				currentLinkedNode = currentLinkedNode->getNextNode();
			}
			
			if(!isFound)
				std::cout << "Key " << data << " was not found." << std::endl;
		}
	}
}

void DoubleLinkedList::insertAfter(LinkedNode * node, int data)
{
	LinkedNode * newNode = new LinkedNode(data);
	if(node->getNextNode() == nullptr)
	{
		newNode->setPrevNode(node);
		node->setNextNode(newNode);
		LinkedList::setTail(newNode);
		
	}
	else
	{
		newNode->setNextNode(node->getNextNode());
		newNode->setPrevNode(node);
		node->getNextNode()->setPrevNode(newNode);
		node->setNextNode(newNode);
	}
}

void DoubleLinkedList::insertBefore(LinkedNode * node, int data)
{
	LinkedNode * newNode = new LinkedNode(data);
	if(node->getPrevNode() == nullptr)
	{
		node->setPrevNode(newNode);
		newNode->setNextNode(node);
		setHead(newNode);
	}
	else
	{
		newNode->setNextNode(node);
		newNode->setPrevNode(node->getPrevNode());
		node->getPrevNode()->setNextNode(newNode);
		node->setPrevNode(newNode);
	}
}