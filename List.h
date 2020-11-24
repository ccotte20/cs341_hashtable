// Honor Pledge:
// I pledge that I have neither given nor 
// received any help on this assignment.
// Clark Otte
#ifndef LIST_H
#define LIST_H
class List
{
	public:
		virtual ~List() {}
		virtual bool isEmtpy() = 0;
		virtual int getLength() = 0;
		virtual void insert(int element) = 0;
		virtual void remove(int element) = 0;
		virtual void printList() = 0;
	protected:
		List() {}
};
#endif