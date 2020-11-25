// Honor Pledge:
// I pledge that I have neither given nor 
// received any help on this assignment.
// Clark Otte
#include "HashTableArray.h"
#include "HashTableChaining.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <vector>
int main()
{
	// Get the file name for input
	std::string inputFile;
	std::cout<<"Enter input file name"<<std::endl;
	std::cin>>inputFile;
	
	//open file, check for errors
	std::ifstream inStream;
	inStream.open(inputFile.c_str());
	if(inStream.fail())
	{
		std::cout<<"Input file opening failed" << std::endl;
		exit(1);
	}
	
	int inputInt(0);
	std::vector<int> data;
	while(inStream>>inputInt)
	{
		data.push_back(inputInt);
	}
	inStream.close();
	
	int size(0);
	std::cout<<"Enter Size of Hash Table"<<std::endl;
	std::cin>>size;
	
	std::cout<<"Welcome to Blue IV's Can of Who Hash!\n"<<std::endl;
	int input(0);
	while(input!=4)
	{
		std::cout<<"1) Linear Probing\n2) Quadratic Probing\n3) Separate Chaining\n4) Quit Program\n"<<std::endl;
		std::cout<<"Please enter your choice: "<<std::endl;
		std::cin>>input;
		if(input==1)
		{
			HashTableArray h(size);
			h.setProbe(linear);
			for(int i=0; i<data.size(); i+=2)
			{
				h.insert(data[i], data[i+1]);
			}
			h.print();
			
			int secondInput(0);
			while(secondInput!=4)
			{
				std::cout<<"1) Search For Entry\n2) Remove Entry\n3) Print Hash Table\n4) Return to Main Menu"<<std::endl;
				std::cout<<"Please enter your choice: "<<std::endl;
				std::cin>>secondInput;
				if(secondInput==1)
				{
					std::cout<<"Search (Please Enter a Key): "<<std::endl;
					int thirdInput(0);
					int result(0);
					std::cin>>thirdInput;
					result = h.search(thirdInput);
					
					if(result !=-1)
						std::cout<<"Key: "<<thirdInput<<" Value: "<<result<<std::endl;
					else
						std::cout<<"Key "<<thirdInput<<" Not found"<<std::endl;
				}
				else if(secondInput==2)
				{
					std::cout<<"Remove (Please Enter a Key): "<<std::endl;
					int thirdInput(0);
					std::cin>>thirdInput;
					h.remove(thirdInput);
				}
				else if(secondInput==3)
				{
					h.print();
				}
				else if(secondInput==4)
				{
					
				}
				else
				{
					std::cout<<"Invalid Input"<<std::endl;
				}
			}
		}
		else if(input==2)
		{
			HashTableArray h(size);
			h.setProbe(quadratic);
			for(int i=0; i<data.size(); i+=2)
			{
				h.insert(data[i], data[i+1]);
			}
			h.print();
			
			int secondInput(0);
			while(secondInput!=4)
			{
				std::cout<<"1) Search For Entry\n2) Remove Entry\n3) Print Hash Table\n4) Return to Main Menu"<<std::endl;
				std::cout<<"Please enter your choice: "<<std::endl;
				std::cin>>secondInput;
				if(secondInput==1)
				{
					std::cout<<"Search (Please Enter a Key): "<<std::endl;
					int thirdInput(0);
					int result(0);
					std::cin>>thirdInput;
					result = h.search(thirdInput);
					
					if(result !=-1)
						std::cout<<"Key: "<<thirdInput<<" Value: "<<result<<std::endl;
					else
						std::cout<<"Key "<<thirdInput<<" Not found"<<std::endl;
				}
				else if(secondInput==2)
				{
					std::cout<<"Remove (Please Enter a Key): "<<std::endl;
					int thirdInput(0);
					std::cin>>thirdInput;
					h.remove(thirdInput);
				}
				else if(secondInput==3)
				{
					h.print();
				}
				else if(secondInput==4)
				{
					
				}
				else
				{
					std::cout<<"Invalid Input"<<std::endl;
				}
			}
		}
		else if(input==3)
		{
			HashTableChaining h(size);
			for(int i=0; i<data.size(); i+=2)
			{
				h.insert(data[i], data[i+1]);
			}
			h.print();
			
			int secondInput(0);
			while(secondInput!=4)
			{
				std::cout<<"1) Search For Entry\n2) Remove Entry\n3) Print Hash Table\n4) Return to Main Menu"<<std::endl;
				std::cout<<"Please enter your choice: "<<std::endl;
				std::cin>>secondInput;
				if(secondInput==1)
				{
					std::cout<<"Search (Please Enter a Key): "<<std::endl;
					int thirdInput(0);
					int result(0);
					std::cin>>thirdInput;
					result = h.search(thirdInput);
					
					if(result !=-1)
						std::cout<<"Key: "<<thirdInput<<" Value: "<<result<<std::endl;
					else
						std::cout<<"Key "<<thirdInput<<" Not found"<<std::endl;
				}
				else if(secondInput==2)
				{
					std::cout<<"Remove (Please Enter a Key): "<<std::endl;
					int thirdInput(0);
					std::cin>>thirdInput;
					h.remove(thirdInput);
				}
				else if(secondInput==3)
				{
					h.print();
				}
				else if(secondInput==4)
				{
					
				}
				else
				{
					std::cout<<"Invalid Input"<<std::endl;
				}
			}
		}
		else if(input==4)
		{
			
		}
		else
		{
			std::cout<<"Invalid Input"<<std::endl;
		}
	}
	
	return 0;
}