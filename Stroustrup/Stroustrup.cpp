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
#include <iostream>
#include <vector>

string ass(int (*f)(std::vector<string>), std::vector<string>v, int ans)
{
	return  f(v) == ans ? "true" : "false";
}

void test(std::vector<std::vector<string>>v, int (*f)(std::vector<string>), std::vector<int>ans) {
	int i = 0;
	for (auto x : v) {
		cout << ass(f, x, ans[i]) << endl;
		++i;
	}
}

int f(std::vector<string> v)
{
	int last = atoi(v[0].substr(0, 2).c_str()) * 360 + atoi(v[0].substr(3, 2).c_str()) * 60 + atoi(v[0].substr(6, 2).c_str());

	int count = 1;
	cout << last << endl;

	for (int i = 1; i < v.size(); ++i)
	{

		int curr = atoi(v[i].substr(0, 2).c_str()) * 360 + atoi(v[i].substr(3, 2).c_str()) * 60 + atoi(v[i].substr(6, 2).c_str());

		cout << curr << endl;
		if (curr <= last)
		{
			++count;
		}

		last = curr;

	}

	return count;
}


int main()
{
	std::vector<std::vector<string>> v
	{
		{ "00:00:00","00:01:11","02:15:59","23:59:58","23:59:59" },
		{ "12:00:00","23:59:59","00:00:00" },
		{"00:00:00","00:00:00","00:00:00","00:00:00"},
		{"00:00:00"},
		{ "00:01:11", "00:00:00","00:01:11","00:01:11", "00:00:00","00:01:11", "00:00:00"},
		{"23:59:59","00:00:00"},
		{"00:00:00","23:59:59"}
	};
	std::vector<int>a{ 1,2,4,1,5,2,1 };

	test(v, f, a);

	//test();
	//File_ptr p("C:\\Users\\sshch\\Source\\Repos\\Harikeshi\\Stroustrup\\Stroustrup\\test.txt","r");
	//test1();
	////vector<int> v(10,12);
	//cout << "end";
}

