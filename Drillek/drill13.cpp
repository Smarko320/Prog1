#include "Simple_window.h"
#include "Graph.h"

int main(){
	using namespace Graph_lib;
	Point tl {100,100};
	Simple_window win{tl,800,1000,"My window"};
	//2. feladat
	int x_size = 800;
	int y_size = 800;
	int x_grid = 100;
	int y_grid = 100;
	
	Lines grid;
	for(int x=x_grid; x<x_size; x+=x_grid)
		grid.add(Point{x,0},Point{x,y_size});
	for(int y=y_grid; y<y_size; y+=y_grid)
		grid.add(Point{0,y},Point{x_size,y});
	win.attach(grid);
	
	//3. feladat
	Rectangle rec1{Point{0,0},100,100};
	rec1.set_fill_color(Color::red);
	win.attach(rec1);
	
	Rectangle rec2{Point{100,100},100,100};
	rec2.set_fill_color(Color::red);
	win.attach(rec2);
	
	Rectangle rec3{Point{200,200},100,100};
	rec3.set_fill_color(Color::red);
	win.attach(rec3);
	
	Rectangle rec4{Point{300,300},100,100};
	rec4.set_fill_color(Color::red);
	win.attach(rec4);
	
	Rectangle rec5{Point{400,400},100,100};
	rec5.set_fill_color(Color::red);
	win.attach(rec5);
	
	Rectangle rec6{Point{500,500},100,100};
	rec6.set_fill_color(Color::red);
	win.attach(rec6);
	
	Rectangle rec7{Point{600,600},100,100};
	rec7.set_fill_color(Color::red);
	win.attach(rec7);
	
	Rectangle rec8{Point{700,700},100,100};
	rec8.set_fill_color(Color::red);
	win.attach(rec8);
	
	//4.fealadat
	
	Image i1 {Point{0,300},"image.jpg"};
	i1.set_mask(Point{200,200},200,200);
	win.attach(i1);
	
	Image i2 {Point{0,500},"image.jpg"};
	i2.set_mask(Point{200,200},200,200);
	win.attach(i2);
	
	Image i3 {Point{200,500},"image.jpg"};
	i3.set_mask(Point{200,200},200,200);
	win.attach(i3);
	
	Image i4 {Point {0,0},"image.jpg"};
	i4.set_mask(Point{0,0},100,100);
	win.attach(i4);
	
	win.wait_for_button();
	
	for(int i=0;i<=8;i++){
		for (int j=0;j<=8;j++){
			i4.move(100,0);
			win.wait_for_button();
		}
		i4.move(-700,100);
		win.wait_for_button();
	}
	
	
	return 0;
}
