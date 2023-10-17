#pragma once

#include <initializer_list>
#include<algorithm>

template<class T>
class Vector {

private:
	T* elem;
	int sz;
public:
	Vector(int s) :elem{ new T[s] }, sz{ s }
	{
		for (int i = 0; i != s; ++i) elem[i] = 0;
	}

	// Конструктор со списком инициализации
	Vector(std::initializer_list<T> lst) :elem{ new T[lst.size()] }, sz{ (int)lst.size() }
	{
		std::copy(lst.begin(), lst.end(), elem);
	}


	~Vector()
	{
		delete[]elem;
	}

	// Конструктор копирования Vector v1 = v2; при инициализации
	Vector(const Vector& v) :elem{ new T[v.size()] }, sz{ v.size() }
	{
		for (int i = 0; i != sz; ++i) elem[i] = v[i];
	}

	// Копируещее присваивание v1=v2; при операции присваивания
	Vector& operator=(const Vector& v)
	{
		T* p = new T[v.size()];
		for (int i = 0; i != v.size(); ++i)
		{
			p[i] = v.elem[i];
		}
		delete[]elem;
		elem = p;
		sz = v.sz;
		return *this;
	}
	// Конструктор перемещения
	Vector(Vector&&v):elem{v.elem}, sz{v.sz}
	{
		v.elem = nullptr;
		v.sz = 0;
	}

	Vector& operator=(Vector&& v)
	{

	}


	void push_back(T);

	//T& operator[](int);
	//int size();

	T& operator[](int i) { return elem[i]; }
	int size() { return sz; }
};