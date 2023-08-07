#include <vector>

struct Point {
	double x, y;
};

class Shape {

public:
	virtual Point center() const = 0;
	virtual void move(Point to) = 0;

	virtual void draw() const = 0;
	virtual void rotate(int angle) = 0;

	virtual ~Shape() {}
};


void rotate_all(std::vector<Shape*>& v, int angle)
{
	for (auto p : v)
		p->rotate(angle);
}

class Circle :public Shape {
public:
	Circle(Point p, int rr) { x = p; r = rr; }
	
	Point center() { return x; }
	void move(Point to) { x = to; }

	void draw()const;
	void rotate(int angle) {}
private:
	Point x;
	int r;
};

class Smiley :public Circle {
public:
	Smile()
};

