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
int main()
{

	//std::vector<int>v{ 5, 3, 2, 4, 6, 1 };
	std::vector<int>v{ 1,1,2,2,3,3};
	/*int n, b;
	std::vector<int>v;
	cin >> n >> b;
	for (int i = 0; i < n; ++i) {
		int temp;
		cin >> temp;
		v.push_back(temp);
	}*/

	int res = 0;
	int maxres = 0;

	int b = 1;
	for (int i = 0; i < v.size() - 1; ++i) {
		int t = 1;

		for (int j = i + 1; j < v.size(); ++j)
		{
			if (v[j] >= t&&v[j]<=b) {
				t = v[j];
				res++;
			}
		}
		if (res > maxres) maxres = res;
		res = 0;
	}

	cout << maxres << endl;




















	//test();
	//File_ptr p("C:\\Users\\sshch\\Source\\Repos\\Harikeshi\\Stroustrup\\Stroustrup\\test.txt","r");
	//test1();
	////vector<int> v(10,12);
	//cout << "end";
}

