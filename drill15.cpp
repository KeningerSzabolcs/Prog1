#include "./GUI/Simple_window.h"
#include "./GUI/Graph.h"

double one(double x) {return 1;}
double slope(double x) {return x/2;}
double square(double x) {return x*x;}
double sloping_cos(double x) { return cos(x) + slope(x);}



int main()
try{
	const int x_win  = 600;
	const int y_win = 600;

	const int x_orig = 300;
	const int y_orig = 300;
	const Point orig(x_orig,y_orig);

	const int range_min = -10;
	const int range_max = 11;

	const int point = 400;

	const int x_scale = 20;
	const int y_scale = 20;

	const int xlength = 400;
    const int ylength = 400;


	Point t1(600,50);

	Simple_window win(t1,x_win,y_win,"Function graph");


	 Axis x(Axis::x,Point(100,y_orig),xlength,xlength/x_scale,"1 == 20 pixels");
    x.set_color(Color::red);
    win.attach(x);
    Axis y(Axis::y,Point(x_orig,500),ylength,ylength/y_scale,"1 == 20 pixels");
    y.set_color(Color::red);
    win.attach(y);
    win.wait_for_button();

    Function f(one,range_min,range_max,orig,point,x_scale,y_scale);
    win.attach(f);
    win.wait_for_button();

    Function f2(slope,range_min,range_max,orig,point,x_scale,y_scale);
    win.attach(f2);
    win.wait_for_button();

    Text t(Point(100,y_orig+4*y_scale),"x/2");
    win.attach(t);
    win.wait_for_button();

    Function f3(square,range_min,range_max,orig,point,x_scale,y_scale);
    win.attach(f3);
    win.wait_for_button();

    Function f4(cos,range_min,range_max,orig,point,x_scale,y_scale);
    f4.set_color(Color::blue);
    win.attach(f4);
    win.wait_for_button();

    Function f5(sloping_cos,range_min,range_max,orig,point,x_scale,y_scale);
    win.attach(f5);
    win.wait_for_button();

}
catch (exception& e) {
    cerr << "exception: " << e.what() << endl;
    keep_window_open();
}
catch (...) {
    cerr << "exception\n";
    keep_window_open();
}