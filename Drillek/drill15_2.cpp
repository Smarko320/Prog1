#include "std_lib_facilities.h"

struct Person{
private:
	string first_name;
	string last_name;
	int a;
public:
	Person(){}
	Person(string ff,string ll, int aa);	
	
	string fname() const {return first_name;}
	string lname() const {return last_name;}
	int age() const {return a;}
	
};

Person::Person(string ff,string ll, int aa):first_name(ff),last_name(ll),a(aa){
	if(aa<0 || aa>150){error("Invalid Age.");}
	string nn=ff+ll;
	for(char c:nn){
		if(c==';' || c==':' || c=='"' || c=='[' || c==']' || c=='*' || c=='&' || c=='^' || c=='%' || c=='$' || c=='#' || c=='@' || c=='!'){
			error("Invalid name.");
		}
	}
}

ostream& print_person(ostream& os, Person p){
	os<<"Name: "<<p.fname()<<" "<<p.lname()<<" age: "<<p.age()<<endl;
	return os;
}

istream& read_person(istream& is, Person& p){
	string f;
	string l;
	int a;
	is>>f>>l>>a;
	p=Person(f,l,a);
	return is;
}


int main(){

	Person p("Goofy","Something",63);
	print_person(cout,p);

	Person p1;
	read_person(cin,p1);
	print_person(cout,p1);
	
	vector<Person> v;
	for(Person p; read_person(cin,p);){
		if(p.fname()=="end"){break;}
		v.push_back(p);
	}
	for(Person p:v){
		print_person(cout,p);
	}

	return 0;
}
