#include <iostream>
class MWindow
{

public:
	virtual void draw() { std::cout << "draw().MWindow" << std::endl; }

};


class Window_with_border : public virtual MWindow
{
protected:
	void own_draw() { std::cout << "draw().border" << std::endl; }
public:
	void draw() override;

};

class Window_with_menu:public virtual MWindow
{
protected:
	void own_draw() { std::cout << "draw().menu" << std::endl; }
public:
	void draw() override;

};

class Clock : public Window_with_border, public Window_with_menu
{
protected:
	void own_draw() { std::cout << "draw().clock" << std::endl; }
public:
	void draw() override;


};

void Window_with_border::draw() {
	MWindow::draw();
	own_draw();
}

void Window_with_menu::draw() {
	MWindow::draw();
	own_draw();
}

void Clock::draw() {
	MWindow::draw();
	Window_with_border::draw();
	Window_with_menu::draw();
	own_draw();
}

