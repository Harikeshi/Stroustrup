// Stroustrup.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
//#include "complex.h"
//#include "vector.h"
#include "Tree/trees.cpp"
#include "Tree/Tree.cpp"

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
//#include "Exceptions/vector.cpp"


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

#include <string>
void testc(int (*f)(std::vector<int>, int a), std::vector<std::vector<int>> v, std::vector<int>ask, std::vector<int>ans)
{
	for (int i = 0; i < v.size(); ++i) {
		std::cout << ((f(v[i], ask[i]) == ans[i]) ? "true" : "false") << " " + to_string(f(v[i], ask[i])) + " " + to_string(ans[i]) << std::endl;
	}
}

int C(std::vector<int>v, int a)
{
	int res = 1;
	int maxres = 0;

	// По кажд

	for (int i = 0; i < v.size() - 1; ++i)
	{
		int t = v[i];
		for (int j = i + 1; j < v.size(); ++j)
		{
			// сравниваем с предыдущим
			if (t == v[j]) ++res; // Если одинаковые то прибавляем результат
			else if (v[j] > a) break;
			else if (v[j] >= t + a)
			{
				t = v[j];
				res++;
			}


		}
		if (res > maxres) maxres = res;
		res = 1;
	}
	return maxres;
}

string ident(string arg) {
	return arg;
}

#include "unit17/Tracer.cpp"



void ftrac(const std::vector<int>& v) {
	Tracer tr{ "in f()\n" };
	for (auto x : v) {
		Tracer tr{ std::string{"v loop "} + std::to_string(x) + '\n' }; // §25.2.5.1 // ...
	}
}

struct Work {

	Work(int a = 0) :b{ a } {}
	int b;

public:
	friend ostream& operator<<(ostream& os, Work& w) { return os << w.b; }

};


class MyClass {

private:
	int a;
	int b;
public:
	explicit MyClass(int a = 0, int b = 0) :a{ a }, b{ b }
	{

	}
	int gets() { return b; }
	int geta();// { return a; }

};


inline int MyClass::geta() { return a; }

void fg(MyClass m) {
	cout << m.geta() << endl;
}


#include <set>
#include <unordered_map>
#include <vector>
#include <map>


class Shape {

public:
	virtual void draw() { cout << "Draw S" << endl; }
	virtual ~Shape() { cout << "~Shape" << endl; }
};

class Circle :Shape {
public:
	void draw() { cout << "Draw Circle" << endl; }
	~Circle() { cout << "~Circle" << endl; }
};

struct S1 {
	int a, b;
};
template<class T>
struct Handle {
	T* p;
	Handle(T* pp = new T{}) :p{ pp } {}
	// ...
};

class Cector {


public:
	explicit Cector() {}
};

class D2 {
public:
	D2(int) {}
};

class D1 :D2 {
public:
	D1() :D2{ 1 } {}
};


class DD {

	int a;
public:
	DD(int i) { a = i; }
	DD() :DD{ 1 } { }

	void print() {
		cout << a << endl;
	}
};

class Circles {

public:
	static const int i = 1;
	//static const float b = 1.0;
};

template <class T>
class Matr1 {
	//array<int, 2>dim;
	int c, r;
	T* elem;
public:
	Matr1(int a, int b) :c{ a }, r{ b }, elem{ new T[a * b] }
	{
		cout << "const" << endl;
	}

	Matr1(const Matr1& m) :c{ m.c }, r{ m.r }, elem{ new T[c * r] }
	{
		uninitialized_copy(m.elem, m.elem + m.size(), elem);
		cout << "copy const" << endl;
	}

	Matr1() :elem{ new T }, c{ 0 }, r{ 0 } {}
	Matr1(Matr1&& m) noexcept :elem{ m.elem }, c{ m.c }, r{ m.r }
	{
		m.elem = nullptr; m.c = 0; m.r = 0; cout << "move const" << endl;
	}

	Matr1& operator=(const Matr1& m)
	{
		// ver. 1
		/*if (r != m.r || c != m.c) throw runtime_error("bad size in copy =");
		copy(m.elem, m.elem + m.size(), elem);
		*/

		// ver. 2
		Matr1 tmp{ m };
		swap(tmp, *this);

		cout << "copy oper" << endl;
		return *this;
	}

	Matr1& operator=(Matr1&& m) noexcept {
		swap(elem, m.elem);
		swap(c, m.c);
		swap(r, m.r);
		cout << "move oper" << endl;

		return *this;
	}

	virtual ~Matr1() { cout << "~" << r << endl; delete[]elem; }


	int size() const;

};

template<class T>
Matr1<T> ident(Matr1<T> m) {
	return m;
}

class none {
public:
	string s;
	string n;
	int i;
};

void vf() {

	none n;
	cout << n.i << endl;
	int i;
}

none n;

struct X {
	X(int a);
};
struct Y :X {
	X m{ 0 };
	Y(int a) :X{ a }, m{ a } {};
	Y() :X{ 0 } {};
};

class C1 {
	int a;
public:
	C1(int a) :a{ a } { cout << "C con-(" << a << ")" << endl; };
	C1() {

		C1{ 10 };
		cout << "C def-(" << a << ")" << endl;
	}
	~C1() {
		cout << "~C-(" << a << ")" << endl;
	}
};

class CC {

public:
	static const int a = 1;
};

struct B1 {
	B1() { cout << "B1 cons" << endl; }
	B1(const B1& x) { cout << "B1 copy" << endl; }
	~B1() { cout << "~B1" << endl; }
};
struct B2 {
	B2(int i) { cout << "B2 cons" << endl; }
	B2(const B2& x) { cout << "B2 copy" << endl; }
	~B2() { cout << "~B2" << endl; }
};

struct BB :B1, B2 {
	BB(int i) :B1{}, B2{ i }, b1{}, b2{ i }
	{
		cout << "BB cons" << endl;
	}
	BB(const BB& x) :B1{ x }, B2{ x }, b1{ x.b1 }, b2{ x.b2 } {
		cout << "BB copy" << endl;
	}
	~BB() { cout << "~BB" << endl; }
	B1 b1;
	B2 b2;
};

class cl {
public:
	int i;
	static string s;
};

string cl::s = "";

struct Bases {
	int b;
	Bases() {
		cout << "Bases" << endl;
	}
	Bases(const Bases& b) {
		cout << "Bases copy" << endl;
	}

	Bases& operator=(const Bases&) {
		cout << "Bases copy =" << endl;
	}
};

struct Derives : Bases {
	int d;
	Derives() {
		cout << "Derives" << endl;
	}
	Derives(const Derives& d) {
		cout << "Derives copy" << endl;
	}
};

void naive(Bases* b) {
	Bases b2 = *b;

}

class Dt {
	int i;
public:
	Dt() = default;
	Dt(const Dt& d);
};

struct Z {
	vector<int> elem;
	int my_favorite;
	int* largest;
	int operator[](int i) { return elem[i]; }
};

struct Cc {


	void operator,(const Cc& c) { cout << "." << endl; }
};


#include "complex.h"
#include "Ptr.cpp"
void cf() {

	complex a = complex{ 1, 3.1 };
	//user constructor(1)

	complex b{ 1.2, 2 };
	//user constructor(1.2)

	complex c{ b };
	//copy constructor(1.2)

	a = b + c;
	//copy constructor(1.2)
	//(1.2).operator+(1.2) = 2.4
	//copy constructor(2.4)
	//(1) move = (2.4)

	b = b + (c * a);
	//copy constructor(1)
	//(1.2).operator*(1) = 1.2
	//copy constructor(1.2)
	//(2.4).operator+(1.2) = 3.6
	//copy constructor(3.6)
	//(3.6) move = (3.6)

	c = a * b + complex(1, 2);
	//copy constructor(3.6)
	//(1).operator*(3.6) = 3.6
	//copy constructor(3.6)
	//user constructor(1)
	//(3.6).operator+(1) = 4.6
	//copy constructor(4.6)
	//(1.2) move = (4.6)
}
void сg(complex a, complex b)
{
	a = { 1, 2 };		// OK: правая часть присваивания
	//a += {1, 2};		// OK: правая часть присваивания
	//b = a + {1, 2};		// синтаксическая ошибка
	b = a + complex{ 1, 2 }; 	// OK
	//сg(a, { 1, 2 });		// OK: аргумент функции считается инициализатором
	//{a, b} = { b, a };		// синтаксическая ошибка
}

/*Библиотека*/
class Foo
{
public:
	Foo(int j) { i = new int[j]; cout << "constructor Foo" << endl; }
	virtual ~Foo() { /*delete i;*/ cout << "~Foo" << endl; }
private:
	int* i;
};

class Bar : public Foo
{
public:
	Bar(int j) :Foo{ j } { i = new char[j]; cout << "constructor Bar" << endl; }
	~Bar() { delete i; cout << "~Bar" << endl; }
private:
	char* i;
};


//#include "Friends.cpp"

int main()
{

	Ptr<char> p;
	p.operator->();
	auto c = complex{ 1 };

	Add a(c);


	a(c);

	

	//cf();

	//complex x = { 4,10e2 };

	//complex y{ x };
	//






}

template<class T>
int Matr1<T>::size() const
{
	return r * c;
}
