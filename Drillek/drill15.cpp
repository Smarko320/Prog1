#include "Graph.h"
#include "Simple_window.h"

double one(double x){return 1;}

double slope(double x){return x/2;}

double square(double x){return x*x;}

double sloping_cos(double x){return cos(x)+slope(x);}

int main(){

	constexpr int xmax=600;
	constexpr int ymax=600;
	Simple_window win{Point{100,100},xmax,ymax,"Function graphs"};

	constexpr int x_orig=xmax/2;
	constexpr int y_orig=ymax/2;
	Point orig{x_orig,y_orig};
	constexpr int r_min=-10;
	constexpr int r_max=11;
	constexpr int n_points=400;
	constexpr int x_scale=20;
	constexpr int y_scale=20;
	constexpr int xlength=xmax-40;
	constexpr int ylength=ymax-40;

	Axis x {Axis::x,Point{20,y_orig},xlength,xlength/x_scale,"one notch==1"};
	Axis y {Axis::y,Point{x_orig,ylength+20},ylength,ylength/y_scale,"one notch==1"};

	x.set_color(Color::red);
	y.set_color(Color::red);

	Function s1{one,r_min,r_max,orig,n_points,x_scale,y_scale};
	Function s2{slope,r_min,r_max,orig,n_points,x_scale,y_scale};
	Function s3{square,r_min,r_max,orig,n_points,x_scale,y_scale};
	Function s4{[] (double x) {return cos(x)+slope(x);},r_min,r_max,orig,n_points,x_scale,y_scale};
	Function s5{sloping_cos,r_min,r_max,orig,n_points,x_scale,y_scale};

	Text t1{Point{100,y_orig-40},"one"};
	Text t2{Point{100,y_orig+y_orig/2-20},"x/2"};
	Text t3{Point{x_orig-100,20},"x*x"};

	s4.set_color(Color::blue);

	win.attach(x);
	win.attach(y);
	win.attach(s1);
	win.attach(s2);
	win.attach(s3);
	win.attach(s4);
	win.attach(s5);
	win.attach(t1);
	win.attach(t2);
	win.attach(t3);

	win.wait_for_button();
}
