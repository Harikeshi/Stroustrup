#include <xmemory>
template<class T, class A = std::allocator<T>>
class vector
{
private:
	T* elem;
	T* space; // конец последовательности элементов, начало области памяти для расширений
	T* last; // конец выделенной памяти
	A alloc;
public:
	using size_type = unsigned int; // тип для размера

	explicit vector(size_type n, const T& val = T(), const A & = A());
	vector(const vector& a); // копирующий конструктор
	vector& operator=(const vector& a); // копирующее присваивание

	vector(vector&& a); // перемещающий конструктор
	vector& operator=(const vector&& a); // перемещающее присваивание

	~vector();

	size_type size() const { return space - elem; }
	size_type capacity() const { return last - elem; }
	void reserve(size_type n); // увеличение емкости до n

	void resize(size_type n, const T & = {});// увеличение размера до n
	void push_back(const T&);
	// ..



};

struct Some_error
{

};

template <class For, class T>
void uninitialized_fill_my(For beg, For end, const T& x)
{
	For p;
	try
	{
		for (p = beg; p != end; ++p)
			::new(static_cast<void*>(&*p)) T(x); // Конструируем копию x в *p
	}
	catch (Some_error)
	{
		for (For q = beg; q != p; ++q)
			(&*q)->~T();
		throw;
	}
}



// реализация конструктора page 397
template <class T, class A>
vector<T, A>::vector(size_type n, const T& val, const A& a)
	:alloc{ a } // копия аллокатора
{
	elem = alloc.allocate(n);

	try {
		uninitialized_fill_my(elem, elem + n, val);
		space = last = elem + n;
	}
	catch (Some_error) {
		alloc.deallocate(elem, n);
		throw; // Повторная генерация
	}
}
