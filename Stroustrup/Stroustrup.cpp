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

class X {
private:
	int m;

public:
	X(int i = 0) :m{ i } {}
	int mf(int i) {
		int old = m;
		m = i;
		return old;
	}

};

int user(X var, X* ptr) {
	int x = var.mf(7);
	cout << x << endl;
	int y = ptr->mf(9);
	cout << y << endl;

	return 0;
}


int main()
{

	X x{ 1 };
	X y{ 2 };

	X z = x;
	cout << z.mf(0) << endl;

	//test();
	//File_ptr p("C:\\Users\\sshch\\Source\\Repos\\Harikeshi\\Stroustrup\\Stroustrup\\test.txt", "r");
	//test1();
	//vector<int> v(10,12);

}

