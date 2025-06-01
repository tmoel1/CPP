#include <string>
#include <iostream>

int main ()
{
	std::string myString; //declare
	myString = "HI THIS IS BRAIN"; //define

	std::string* myStringPointer; //declare
	myStringPointer = &myString; //define

	std::string& myStringReference = myString; //must declare and define simultaneously

	//print addresses
	std::cout << &myString << std::endl; 
	std::cout << myStringPointer << std::endl;
	std::cout << &myStringReference << std::endl;
	//print values
	std::cout << myString << std::endl;
	std::cout << *myStringPointer << std::endl;
	std::cout << myStringReference << std::endl;

	return 0;
}