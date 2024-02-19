class C1 {
};

void f1();

namespace N {
	class C2 {};
	void f2() {}

	class C {
		int x;
		
	public:
		friend class C1;
		friend void f1();

		friend class C3;
		friend void f3();
		friend class C4;
		friend void f4();
	};

	class C3 {
		friend class C;
		int y;
	};
	void f3() { C x; x.x = 1; }
} // namespace N

class C4 {};
// void f4() { N::C x; x.x = 1; }
// void f1() { N::C x; x.x = 2; }