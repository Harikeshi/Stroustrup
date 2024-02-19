#include <iostream>

class String
{
	static const int short_max = 15;
	size_t sz;
	char* ptr;

	union {
		int space;
		char ch[short_max + 1];
	};

public:
	String();

	/*explicit*/ String(const char* p);

	String(const String& s);
	String& operator=(const String& s);

	String(String&& s);
	String& operator=(String&& s);

	~String() { if (short_max < sz) delete[]ptr; }


	char& operator[](int i) { return ptr[i]; }
	char& operator[](int i) const { return ptr[i]; }

	char& at(int i) { check(i); return ptr[i]; }
	char& at(int i) const { check(i); return ptr[i]; }

	String& operator+=(char c);

	const char* c_str() { return ptr; }
	const char* c_str() const { return ptr; }

	int size() const { return sz; }
	int capacity() const
	{
		return (sz <= short_max) ? short_max : sz + space;
	}

	void check(int i)const
	{
		if (i < 0 || sz <= i) throw std::out_of_range("String::at()");
	}

private:
	// Вспомогательные функции
	void copy_from(const String& x);
	void move_from(String& x);

};

char* expand(const char* ptr, int n) // расширение в свободное хранилище
{
	char* p = new char[n];
	strcpy(p, ptr);
	return p;
}

void String::copy_from(const String& x) {

	if (x.sz <= short_max) {
		memcpy(this, &x, sizeof(x));
		ptr = ch;
	}
	else {
		ptr = expand(x.ptr, x.sz + 1);
		sz = x.sz;
		space = 0;
	}
}

void String::move_from(String& x) {
	if (x.sz <= short_max) {
		memcpy(this, &x, sizeof(x));
		ptr = ch;
	}
	else {
		ptr = x.ptr;
		sz = x.sz;
		space = x.space;
		x.ptr = x.ch;
		x.sz = 0;
		x.ch[0] = 0;
	}
}

String::String() :sz{ 0 }, ptr{ ch } { ch[0] = 0; }

String::String(const char* p)
	:sz{ strlen(p) },
	ptr{ (sz <= short_max) ? ch : new char[sz + 1] },
	space{ 0 }
{
	strcpy(ptr, p);
}

String::String(const String& x) {
	copy_from(x);
}

String::String(String&& x) {
	move_from(x);
}

String& String::operator=(const String& x) {
	if (this == &x) return *this;
	char* p = (short_max < sz) ? ptr : 0;
	copy_from(x);
	delete[]p;

	return *this;
}

String& String::operator=(String&& x) {
	if (this == &x) return *this;
	if (short_max < sz) delete[]ptr;
	move_from(x);
	return *this;
}

String& String::operator+=(char c) {
	if (sz == short_max) // расширить до длины строки
	{
		int n = sz + sz + 2; // удвоение из-за \0
		ptr = expand(ptr, n);
		space = n - sz - 2;
	}
	else if (short_max < sz) {
		if (space == 0) {
			int n = sz + sz + 2;
			char* p = expand(ptr, n);
			delete[]ptr;
			ptr = p;
			space = n - sz - 2;
		}
		else {
			--space;
		}
		ptr[sz] = c;
		ptr[++sz] = 0;

		return *this;
	}
}

std::ostream& operator<<(std::ostream& os, const String& s) {
	return os << s.c_str();
}

std::istream& operator>>(std::istream& is, String& s) {
	s = "";
	is >> std::ws;
	char ch = ' ';
	while (is.get(ch) && isspace(ch)) {
		s += ch;
	}

	return is;
}

bool operator ==(const String& a, const String& b) {
	if (a.size() != b.size()) return false;
	for (int i = 0; i != a.size(); ++i) {
		if (a[i] != b[i]) return false;
	}

	return true;
}

bool operator!=(const String& a, const String& b) {
	return !(a == b);
}

char* begin(String& x) {
	return (char*)x.c_str();
}

char* end(String& x) {
	return (char*)x.c_str() + x.size();
}

const char* begin(const String& x) {
	return x.c_str();
}

const char* end(const String& x) {
	return x.c_str() + x.size();
}

String& operator+=(String& a, const String& b) {

	for (auto x : b) {
		a += x;
	}
	return a;
}

String& operator+(const String& a, const String& b) {
	String s{ a };
	s += b;

	return s;
}

String operator"" _s(const char* p, size_t)
{
	return String{ p };
}