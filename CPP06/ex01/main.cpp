#include <iostream>
#include "Serializer.hpp"
#include "Data.hpp"

int	main()
{
	Data	data;

	data.Nb = 42;
	data.Str = "C++";
	data.Double = 3.14159;

	Data*		ptr = &data;
	uintptr_t	raw = Serializer::serialize(ptr);
	Data*		deserializedPtr = Serializer::deserialize(raw);

	std::cout << "Original pointer:     " << ptr << std::endl;
	std::cout << "Serialized :     " << raw << std::endl;
	std::cout << "Deserialized pointer: " << deserializedPtr << std::endl;
	std::cout << std::endl;
	std::cout << "Data via deserialized pointer :" << std::endl;
	std::cout << "Nb: "<< deserializedPtr->Nb << std::endl;
	std::cout << "Str: " << deserializedPtr->Str << std::endl;
	std::cout << "Double: " << deserializedPtr->Double << std::endl;
}
