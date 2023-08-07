#pragma once

class complex {
private:
	double re, im;

public:
	complex(double r, double i) :re{ r }, im{ i } {}
	complex(double r) :re{ r }, im{ 0 } {}
	complex() :re{ 0 }, im{ 0 } {}


	// Простые операции должны быть встраиваемые.
	// const означает что функции не меняют аргументы.
	double real()const { return re; }
	void real(double r) { re = r; }
	double imag()const { return im; }
	void imag(double i) { im = i; }

	complex& operator+=(complex z) { re += z.re; im += z.im; return *this; }
	complex& operator-=(complex z) { re -= z.re; im -= z.im; return *this; }

	complex& operator*=(complex);
	complex& operator/=(complex);

	void print();

};


complex& complex::operator*=(complex z) { re *= z.re; im *= z.im; return *this; }
complex& complex::operator/=(complex z) { re /= z.re; im /= z.im; return *this; }

// Аргументы, передаваемые по значению, копируются. Можем модифицировать без воздействия на аргумент.
complex operator+(complex a, complex b) { return a += b; }
complex operator- (complex a, complex b) { return a -= b; }
complex operator*(complex a, complex b) { return a *= b; }
complex operator/ (complex a, complex b) { return a /= b; }

bool operator==(complex a, complex b) { return a.real() == b.real() && a.imag() == b.imag(); }
bool operator!=(complex a, complex b) { return !(a == b); }


void complex::print() {}
