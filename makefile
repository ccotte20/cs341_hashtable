# Honor Pledge:
# I pledge that I have neither given nor 
# received any help on this assignment.
# Clark Otte
A5.exe: driver.o HashTableChaining.o HashTableArray.o HashEntry.o DoubleLinkedList.o LinkedList.o LinkedNode.o Node.o
	g++ driver.o HashTableChaining.o HashTableArray.o HashEntry.o DoubleLinkedList.o LinkedList.o LinkedNode.o Node.o -o A5.exe

driver.o: driver.cpp
	g++ -c driver.cpp -o driver.o

HashTableChaining.o: HashTableChaining.cpp
	g++ -c HashTableChaining.cpp -o HashTableChaining.o

HashTableArray.o: HashTableArray.cpp
	g++ -c HashTableArray.cpp -o HashTableArray.o

HashEntry.o: HashEntry.cpp
	g++ -c HashEntry.cpp -o HashEntry.o

DoubleLinkedList.o: DoubleLinkedList.cpp
	g++ -c DoubleLinkedList.cpp -o DoubleLinkedList.o

LinkedList.o: LinkedList.cpp
	g++ -c LinkedList.cpp -o LinkedList.o

LinkedNode.o: LinkedNode.cpp
	g++ -c LinkedNode.cpp -o LinkedNode.o

Node.o: Node.cpp
	g++ -c Node.cpp -o Node.o
	
clean:
	rm -f driver.o HashTableChaining.o HashTableArray.o HashEntry.o DoubleLinkedList.o LinkedList.o LinkedNode.o Node.o A5.exe