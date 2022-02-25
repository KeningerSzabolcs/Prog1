#include "./GUI/Simple_window.h"
#include "./GUI/Graph.h"

#include <string>
#include <iostream>

using namespace Graph_lib;

int main()
{	
try{
Point t1(100,100);
Simple_window win {t1,600,400,"My window"};
win.resize(600,400);
win.wait_for_button();

Axis xa(Axis::x,Point(20,330),300,10,"some axis");
    win.attach(xa);
    win.set_label("Canvas #2");
    win.resize(600,400);
    win.wait_for_button();

Axis ya(Axis::y,Point(20,330),280,30,"other axis");
    ya.set_color(Color::cyan);
    ya.label.set_color(Color::dark_red);
    win.attach(ya);
    win.set_label("Canvas #3");
    win.resize(600,400);
    win.wait_for_button();

    Function cosine(cos,0,100,Point(20,175),100,10,10);
    win.attach(cosine);
    win.set_label("Canvas #4");
    win.resize(600,400);
    win.wait_for_button();
}catch (exception& e){
	cerr << "exception: " << e.what() << '\n';
	return 1;
}catch(...){
	cerr << "error\n";
	return 2;
}

	
}