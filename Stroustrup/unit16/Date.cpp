class Date {
	int d, m, y;
public:
	explicit Date(int dd);
	// ...
};
Date::Date(int dd) :d{ dd }, m{ 0 }, y{ 0 } {

	/* ... */
}	// OK

#include <iostream>
class X
{

public:
	explicit X() { std::cout << "X" << std::endl; }
	explicit X(int a, int b) {}
};
