// Honor Pledge:
// I pledge that I have neither given nor 
// received any help on this assignment.
// Clark Otte

#include "HashEntry.h"

HashEntry::HashEntry(int key, int value) : key_(key), value_(value), status_(OCCUPIED)
{
	
}

// Dr. Ryan: We should avoid using -1 as it may be a valid value.
HashEntry::HashEntry() : key_(-1), value_(-1), status_(EMPTY)
{
	
}

void HashEntry::remove()
{
	key_=-1;
	value_=-1;
	status_=REMOVED;
}

int HashEntry::getKey()
{
	return key_;
}

int HashEntry::getValue()
{
	return value_;
}

Status HashEntry::getStatus()
{
	return status_;
}

void HashEntry::setKey(int key)
{
	key_=key;
}
void HashEntry::setValue(int value)
{
	value_=value;
}

void HashEntry::setStatus(Status status)
{
	status_=status;
}