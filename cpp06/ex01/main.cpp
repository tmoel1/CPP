#include "Serializer.hpp"
#include <iostream>

int main()
{
	// declare and populate a Data struct
	Data myData;
	myData.id = 42;
	myData.name = "Test";

	Data* originalPtr = &myData;

	// print original state
	std::cout << "Address before: " << originalPtr << std::endl;
	std::cout << "Data before: id=" << originalPtr->id << ", name=" << originalPtr->name << std::endl;

	// perform the round trip (ptr -> int -> ptr)
	uintptr_t raw = Serializer::serialize(originalPtr);
	Data* deserializedPtr = Serializer::deserialize(raw);

	// print deserialized state
	std::cout << "Address after: " << deserializedPtr << std::endl;
	std::cout << "Data after: id=" << deserializedPtr->id << ", name=" << deserializedPtr->name << std::endl;

	return 0;
}