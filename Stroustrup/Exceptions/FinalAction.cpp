
// Завершающие конструкции (Finally)

template<typename F>

struct Final_action
{
	Final_action(F f) :clean{ f } {}
	~Final_action() { clean(); }

	F clean;

};

template<typename F>
Final_action<F> finally(F f)
{
	return Final_action<F>(f);
}

// тест для finally()

void test1()
{

	int* p = new int{ 7 };
	int* buf = (int*)malloc(100 * sizeof(int));

	auto act1 = finally([&] {
		delete p;
		free(buf);
		cout << "Goodbye, Cruel world!\n";
		}
	);

	int var = 0;
	cout << "var =" << var << "\n";

	{
		var = 1;
		auto act2 = finally([&]
			{
				cout << "finally!\n";
				var = 7;
			}
		);

		cout << "test\n";
	}	
	cout << "var =" << var << "\n";
}