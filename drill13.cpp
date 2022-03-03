#include "./GUI/Simple_window.h"
#include "./GUI/Graph.h"

#include <string>
#include <iostream>

using namespace Graph_lib;

int main()
{
	Point t1(100,100);
	Simple_window win(t1,800,1000,"My Window");
	win.resize(800,1000);
	win.wait_for_button();


	Lines grid;
	int x_size = 800;
	int y_size = 800;
	for (int i = 100; i<=x_size; i+=100) 
	{
        grid.add(Point(i,0),Point(i,y_size));
        grid.add(Point(0,i),Point(x_size,i));
    }

    win.attach(grid);
    win.wait_for_button();

    Vector_ref<Graph_lib::Rectangle> vr;
    for (int i = 0; i<8; ++i) 
    {
        vr.push_back(new Graph_lib::Rectangle(Point(i*100,i*100),101,101));
        vr[vr.size()-1].set_fill_color(Color::red);
        win.attach(vr[vr.size()-1]);
     }
     win.wait_for_button();

     Image pic1 (Point(200,0),"pics_and_txt/LeBron.jpg");
     pic1.set_mask(Point(200,0),200,200);
     win.attach(pic1);
     Image pic2 (Point(500,200),"pics_and_txtLeBron.jpg");
     pic2.set_mask(Point(200,0),200,200);
     win.attach(pic2);
     Image pic3(Point(100,500),"pics_and_txt/LeBron.jpg");
     pic3.set_mask(Point(200,0),200,200);
     win.attach(pic3);

     win.wait_for_button();

     Image mv(Point(0,0),"pics_and_txt/LeBron.jpg");
     mv.set_mask(Point(110,70),100,100);
     win.attach(mv);
     win.wait_for_button();

     int x = 0;
     int y = 0;
     int gx = 0;
     int gy = 0;

     while(true)
     {
     	x = randint(8);

     	y = randint(8);

     	gx= 100*x - mv.point(0).x;

     	gy = 100*y - mv.point(0).y;

     	mv.move(gx,gy);

     	win.wait_for_button();
     }

	return 0;
}