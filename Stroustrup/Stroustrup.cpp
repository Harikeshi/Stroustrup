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
#include "Exceptions/FinalAction.cpp"
#include "Exceptions/vector.cpp"

#include <string>
void ya(string s)
{
	// 2+2
	// 11-22-33
	// 2023

	//string s;
	//cin >> s;
	double res = 0;
	size_t i = 0;
	string temp;

	if (isdigit(s[0]))
	{
		while (i < s.size() && isdigit(s[i]))
		{
			temp += s[i];
			i++;
		}
		res += stod(temp);
		--i;
	}

	for (; i < s.size() - 1; ++i)
	{
		// 11-22-33
		if (s[i] == '-' || s[i] == '+')
		{
			temp = "";
			temp += s[i++];

			while (i < s.size() && isdigit(s[i]))
			{
				temp += s[i];
				++i;
			}

			res += stod(temp);

			if (i < s.size() - 1)
				--i;
		}
	}

	cout << res;
}




int main()
{
	test();
	File_ptr p("C:\\Users\\sshch\\Source\\Repos\\Harikeshi\\Stroustrup\\Stroustrup\\test.txt", "r");
	test1();
	//vector<int> v(10,12);

}

