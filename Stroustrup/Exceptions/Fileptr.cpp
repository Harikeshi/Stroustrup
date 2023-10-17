#include <cstdio>

class File_ptr {

	std::FILE* p;
public:
	File_ptr(const char* n, const char* a) : p{ fopen(n,a) }
	{
		if (p == nullptr) throw std::runtime_error{ "File_ptr: Can't open file. " };
	}


};