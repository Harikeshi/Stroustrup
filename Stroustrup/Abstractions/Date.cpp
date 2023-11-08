struct Date {
	int d, m, y;

	void init(int dd, int mm, int yy);
	void add_year(int n);
	void add_month(int n);
	void add_day(int n);
};

void Date::init(int dd, int mm, int yy) {
	d = dd;
	m = mm;
	y = yy;
}

void Date::add_year(int n) {
	y += n;
}

void Date::add_month(int n) {
	m += n;
}

void Date::add_day(int n) {
	d += n;
}
