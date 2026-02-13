#include "Serializer.hpp"
#include <stdint.h>
#include <iostream>

int main()
{
	Data d = {1, "Loli Panoli", 3};
	uintptr_t s = Serializer::serialize(&d);
	std::cout << "Serialized: " << s << std::endl;
	Data* ds = Serializer::deserialize(s);
	std::cout << "Deserialized: " << ds->name << std::endl;
	return 0;
}
