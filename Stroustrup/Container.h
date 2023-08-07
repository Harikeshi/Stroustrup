#pragma once

class Container {

public:
	virtual double& operator[](int i) = 0; // чисто виртуальная функция
	virtual int size() const = 0; // константная функция-член
	virtual ~Container() {} // Виртуальный диструктор
};

#include <iostream>

void use(Container& c) {

	const int sz = c.size();

	for (int i = 0; i != sz; ++i) std::cout << c[i];
}