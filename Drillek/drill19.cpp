#include "std_lib_facilities.h"

template<typename T>
struct S {
private:

	T val;

public:

	explicit S(T vv = 0) : val{vv} {}

	S& operator = (const T&);
	T& get();
	const T& get() const;
	void set(T x){val=x;}
};

template<typename T>
T& S<T>::get(){
	return val;
}

template<typename T>
const T& S<T>::get() const {
	return val;
}

template<typename T>
ostream& operator<<(ostream& os, vector<T>& v){
	for(int i=0;i<v.size();i++){
		os<<v[i]<<" ";
	}
	return os;
}

template<typename T>
istream& operator>>(istream& is, vector<T>& v){
	char c = 0;
	is>>c;
	if(c!='{'){
		error("Invalid vector format");
		return is;
	}
	for(T val; is>>val;){
		v.push_back(val);
		is>>c;
		if(c=='}'){break;}
	}
	return is;
}

template<typename T>
void read_val(T& v){
	cin>>v;
}

int main(){

	S<int> s_int {12};
	S<char> s_char {'a'};
	S<double> s_double {1.2};
	S<string> s_string {"I love classes!"};
	S<vector<int>> s_vector {vector<int>{1,2,3,4,5}};

	cout<<s_int.get()<<endl;
	cout<<s_char.get()<<endl;
	cout<<s_double.get()<<endl;
	cout<<s_string.get()<<endl;
	cout<<s_vector.get()<<endl;

	int x;
	cout<<"Enter an intiger:"<<endl;
	read_val(x);
	s_int.set(x);

	char y;
	cout<<"Enter a character"<<endl;
	read_val(y);
	s_char.set(y);

	double z;
	cout<<"Enter a double"<<endl;
	read_val(z);
	s_double.set(z);

	string s;
	cout<<"Enter a string"<<endl;
	read_val(s);
	s_string.set(s);

	vector<int> v;
	cout<<"Enter a vector (format: {num,num,num,...}"<<endl;
	read_val(v);
	s_vector.set(v);
	

	cout<<s_int.get()<<endl;
	cout<<s_char.get()<<endl;
	cout<<s_double.get()<<endl;
	cout<<s_string.get()<<endl;
	cout<<s_vector.get()<<endl;

	return 0;
}
