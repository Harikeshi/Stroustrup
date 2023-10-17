// Stroustrup.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
//#include "complex.h"
//#include "vector.h"
#include "Tree/trees.cpp"

using namespace std;

struct some_error {};



int todo()
{
	if (false) {
		return 1;
	}
	else {
		throw some_error{};
	}
}

void test() {

	try {
		auto r = todo();
		cout << 0 << endl;
	}
	catch (some_error) {
		cout << -1 << endl;
	
	}
}


#include "Exceptions/Fileptr.cpp"

int main()
{

	test();
	File_ptr p("test.txt","r");

}
