#pragma once

#include <initializer_list>
#include<algorithm>


class Vector {

private:
	double* elem;
	int sz;
public:
	Vector(int s) :elem{ new double[s] }, sz{ s }
	{
		for (int i = 0; i != s; ++i) elem[i] = 0;
	}

	// Конструктор со списком инициализации
	Vector(std::initializer_list<double>);

	~Vector()
	{
		delete[]elem;
	}

	void push_back(double);

	double& operator[](int);
	int size();
};

Vector::Vector(std::initializer_list<double> lst) :elem{ new double[lst.size()] }, sz{(int)lst.size()}
{
	std::copy(lst.begin(), lst.end(), elem);
}

double& Vector::operator[](int i) { return elem[i]; }
int Vector::size() { return sz; }