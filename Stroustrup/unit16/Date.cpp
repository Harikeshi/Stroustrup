
#include <iostream>
namespace Chrono
{
	enum class Month
	{
		jan = 1,
		feb,
		mar,
		apr,
		may,
		jun,
		jul,
		aug,
		sep,
		oct,
		nov,
		dec
	};
	class Date
	{
	public: // public interface:
		class Bad_date
		{
		};                                                      // класс исключений
		explicit Date(int dd = {}, Month mm = {}, int yy = {}):
			d{ dd }, m{ (int)mm }, y{ yy }{} // {} означает ''выбрать значение по умолчанию''.

		// немодифицирующие функции для получения даты:
		int day() const { return d; }
		Month month() const { return static_cast<Month>(m); }
		int year() const { return y; }
		std::string string_rep() const { return ""; }             // представление строки
		void char_rep(char s[], int max) const {} // Представление строк в стиле C

		// модифицирующие функции для изменения даты:
		Date& add_year(int n) { y += n; return *this; }  // добавить n лет
		Date& add_month(int n) { m += n; return*this; } // добавить n месяцев
		Date& add_day(int n) { d += n; return*this; }   // добавить n дней
	private:
		bool is_valid() { return true; } // проверьте, представляет ли эта Дата дату
		int d, m, y;     // представление
	};

	bool is_date(int d, Month m, int y) { return true; } // true для действительной даты
	bool is_leapyear(int y) { return true; }             // true, если y - високосный год

	bool operator==(const Date& a, const Date& b)
	{
		return a.day() == b.day() && a.month() == b.month() && a.year() || b.year();
	}
	bool operator!=(const Date& a, const Date& b) {
		return !(a == b);
	}

	//const Date& default_date() { return; } // дата по умолчанию

	std::ostream& operator<<(std::ostream& os, const Date& d) { return os; } // печать d в os
	std::istream& operator>>(std::istream& is, Date& d) { return is; }       // чтение даты из is в d
} // Chrono