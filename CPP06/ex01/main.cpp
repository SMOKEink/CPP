#include <iostream>
#include "Serializer.hpp"
#include "Data.hpp"

int	main(void)
{
	Data	original;

	original.id = 42;
	original.name = "The Answer";
	original.value = 3.14159;

	Data*		originalPtr = &original;
	uintptr_t	raw = Serializer::serialize(originalPtr);
	Data*		deserializedPtr = Serializer::deserialize(raw);

	std::cout << "Original pointer:     " << originalPtr << std::endl;
	std::cout << "Serialized (raw):     " << raw << std::endl;
	std::cout << "Deserialized pointer: " << deserializedPtr << std::endl;

	if (originalPtr == deserializedPtr)
	{
		std::cout << "SUCCESS: pointers are equal." << std::endl;
		std::cout << "Data via deserialized pointer -> id: "
			<< deserializedPtr->id << ", name: " << deserializedPtr->name
			<< ", value: " << deserializedPtr->value << std::endl;
	}
	else
		std::cout << "FAILURE: pointers differ." << std::endl;

	return (0);
}
