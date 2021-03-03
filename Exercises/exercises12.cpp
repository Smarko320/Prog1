#include "Simple_window.h"
#include "Graph.h"

int main()try{
	using namespace Graph_lib;
	Point tl{100,100};
	Simple_window win1{tl,600,800,"exercises1"};
	
	//---1.feladat---
	Polygon poly;
	poly.add(Point(300,200));
	poly.add(Point(400,200));
	poly.add(Point(400,500));
	poly.add(Point(300,500));
	poly.set_color(Color::red);
	win1.attach(poly);
	Rectangle rec{Point{150,150},100,50};
	win1.attach(rec);
	rec.set_color(Color::blue);
	rec.move(0,150);
	poly.move(0,150);
	
	win1.wait_for_button();
	
	
	
	//---2.feladat---
	Simple_window win2{tl,600,800,"exercises2"};
	Rectangle rec2{Point{150,150},100,30};
	Text t{Point{170,175},"Howdy"};
	win2.attach(rec2);
	win2.attach(t);
	rec2.move(0,150);
	t.move(0,150);
	
	win2.wait_for_button();
	
	//---4.feladat---
	Simple_window win3{tl,600,800,"exercises4"};
	Rectangle re1{Point{200,200},100,100};
	win3.attach(re1);
	re1.set_fill_color(Color::white);
	Rectangle re2{Point{300,300},100,100};
	win3.attach(re2);
	re2.set_fill_color(Color::white);
	Rectangle re3{Point{200,300},100,100};
	win3.attach(re3);
	re3.set_fill_color(Color::red);
	Rectangle re4{Point{300,200},100,100};
	win3.attach(re4);
	re4.set_fill_color(Color::red);
	Rectangle re5{Point{400,200},100,100};
	win3.attach(re5);
	re5.set_fill_color(Color::white);
	Rectangle re6{Point{400,300},100,100};
	win3.attach(re6);
	re6.set_fill_color(Color::red);
	Rectangle re7{Point{400,400},100,100};
	win3.attach(re7);
	re7.set_fill_color(Color::white);
	Rectangle re8{Point{300,400},100,100};
	win3.attach(re8);
	re8.set_fill_color(Color::red);
	Rectangle re9{Point{200,400},100,100};
	win3.attach(re9);
	re9.set_fill_color(Color::white);
	
	win3.wait_for_button();
	
	
	//---5.feladat---
	Simple_window win4{tl,900,1000,"exercises5"};
	Rectangle rec3{Point{100,100},700,850};
	win4.attach(rec3);
	Rectangle rec4{Point{75,75},750,900};
	win4.attach(rec4);
	rec4.set_color(Color::red);
	rec4.set_style(Line_style(Line_style::solid,24));
	
	win4.wait_for_button();
	
	//---6/1.feladat---
	Simple_window win5{tl,600,400,"exercises6"};
	Rectangle rec5{Point{0,0},1000,1000};
	win5.attach(rec5);
	
	win5.wait_for_button();
	
	//Nem lesz látható az alakzat mert az ablak hatótávolságán kívülre esik, hogy látható legyen az ablak szélével megkell nagyobbítani manuálisan a képernyőt
	
	
	//----6/2.feladat----
	Simple_window win6{tl,2000,2000,"exercises6"};
	Rectangle rec6{Point{200,200},600,300};
	win6.attach(rec6);
	win6.wait_for_button();
	
	//Nem tudunk olyan nagy ablakot kérni ami nagyobb a képernyőnknél mert a program a mi képernyőnkre igazítja az ablakot
	
	
	//---7.feladat---
	Simple_window win7{tl,600,800,"exercises7"};
	Rectangle rec7{Point{200,400},200,200};
	Polygon poly2;
	poly2.add(Point{200,400});
	poly2.add(Point{400,400});
	poly2.add(Point{300,300});
	Rectangle ajto{Point{280,520},40,80};
	Rectangle ablak1{Point{240,440},40,40};
	Rectangle ablak2{Point{320,440},40,40};
	Polygon kemeny;
	
	kemeny.add(Point{200,300});
	kemeny.add(Point{200,400});
	kemeny.add(Point{250,350});
	kemeny.add(Point{250,300});
	
	win7.attach(rec7);
	win7.attach(poly2);
	win7.attach(ajto);
	win7.attach(ablak1);
	win7.attach(ablak2);
	win7.attach(kemeny);
	
	win7.wait_for_button();
	
	
	//---8.feladat----
	Simple_window win8{tl,700,800,"exercises8"};

	Circle kor4{Point{250,220},75};
	win8.attach(kor4);
	kor4.set_color(Color::yellow);
	kor4.set_style(Line_style(Line_style::solid,12));
	Circle kor5{Point{450,220},75};
	win8.attach(kor5);
	kor5.set_color(Color::green);
	kor5.set_style(Line_style(Line_style::solid,12));
	
	Circle kor1{Point{150,150},75};
	win8.attach(kor1);
	kor1.set_color(Color::blue);
	kor1.set_style(Line_style(Line_style::solid,12));
	Circle kor2{Point{350,150},75};
	win8.attach(kor2);
	kor2.set_color(Color::black);
	kor2.set_style(Line_style(Line_style::solid,12));
	Circle kor3{Point{550,150},75};
	win8.attach(kor3);
	kor3.set_color(Color::red);
	kor3.set_style(Line_style(Line_style::solid,12));
	
	win8.wait_for_button();
	//---9.feladat---
	Simple_window win9{tl,700,800,"badge"};
	Image badge{Point{100,100},"image.jpg"};
	win9.attach(badge);
	Text badgetxt{Point{150,75},"badge"};
	win9.attach(badgetxt);
	
	win9.wait_for_button();
	
	
	return 0;
}catch(exception& e){
cerr<<"exception: "<<e.what();
return 1;

}
