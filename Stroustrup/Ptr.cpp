template<class T>
class Ptr
{
	T* data;
public:




	T* operator->() { return data; }
	T& operator*() { return *data; }
	T& operator[](int i) { return data[i]; }
};
