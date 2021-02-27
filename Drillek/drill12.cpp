#include "Simple_window.h"
#include "Graph.h"

int main(){
	//----1-----
	using namespace Graph_lib;
	Point tl {100,100};
	Simple_window win{tl,600,400,"My window"};
	
	//-----2------
	Axis xa {Axis::x, Point{10,300}, 280, 10, "x axis"}; 
	win.attach(xa);                                             
	//win.set_label("Canvas #2");      
	
	
	//-----3------
	Axis ya {Axis::y, Point{20,290}, 280, 10, "y axis"};
	ya.set_color(Color::cyan);  
	ya.label.set_color(Color::dark_red);      
	win.attach(ya);
	
	//----4-----
	Function sine {sin,0,110,Point{20,150},1000,50,50};           
	win.attach(sine);
	
	//----5----
	sine.set_color(Color::blue);     
	Polygon poly;                           
	poly.add(Point{300,200});      
	poly.add(Point{350,100});
	poly.add(Point{400,200});
	poly.set_color(Color::blue);
	poly.set_style(Line_style::dash);
	win.attach(poly);
	
	//---6---
	Rectangle r {Point{220,220}, 100, 50};      
	win.attach(r); 
	
	
	//---7----
	Closed_polyline poly_rect;
	poly_rect.add(Point{150,50});
	poly_rect.add(Point{200,50});
	poly_rect.add(Point{200,100});
	poly_rect.add(Point{100,100});
	poly_rect.add(Point{50,75});
	win.attach(poly_rect);
	
	
	//----7.7----
	r.set_fill_color(Color::red);       
	poly.set_style(Line_style(Line_style::dash,4)); 
	poly_rect.set_style(Line_style(Line_style::dash,2));
	poly_rect.set_fill_color(Color::green);
	
	
	//---8----
	Text t {Point{150,150}, "Hello, graphical world!"};
	win.attach(t);
	t.set_font(Font::courier_bold);
	t.set_font_size(20);
	
	
	//---9----
	Image ii {Point{220,350},"image.jpg"};
	win.attach(ii);
	
	
	//---10---
	Circle c {Point{150,200},50};
	//Ellipse e {Point{100,200}, 75,25};
	//e.set_color(Color::dark_red);
	Mark m {Point{150,200},'x'};
	ostringstream oss;
	oss << "screen size: " << x_max() << "*" << y_max()
	          << "; window size: " << win.x_max() << "*" << win.y_max();
	Text sizes {Point{100,20},oss.str()};
	win.attach(c);
	win.attach(m);
	
	
	
	
	win.wait_for_button();

	return 0;
}
