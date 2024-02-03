#include <iostream>
#include <string>

struct Tracer {

	std::string mess;

	Tracer(const std::string& s) :mess{ s }
	{
		std::clog << mess;
	}
	~Tracer()
	{
		std::clog << "~" << mess;
	}
};
