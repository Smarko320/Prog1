#include "std_lib_facilities.h"

template<typename A>
void print(const A& a){
	for(auto& au : a){
		cout<<au<<" ";
	}
	cout<<'\n';
}

template<typename A>
void inc(A& a, int n){
	for(auto& au : a){
		au=au+n;
	}
}

template<typename Iter1, typename Iter2>
Iter2 my_copy(Iter1 f1, Iter1 e1, Iter2 f2){
	for(Iter1 i=f1; i!=e1; i++){
		*f2++ = *i;
	}
	return f2;
}

int main(){

	constexpr int size=10;

	int arrey[size]{0,1,2,3,4,5,6,7,8,9};
	cout<<"int array: ";
	print(arrey);

	vector<int> v(size);
	copy(arrey, arrey+size, v.begin());
	cout<<"vector: ";
	print(v);

	list<int> l(size);
	copy(arrey, arrey+size, l.begin());
	cout<<"list: ";
	print(l);

	array<int, size> arr;
	copy(arrey, arrey+size, arr.begin());
	cout<<"array: ";
	print(arr);

	array<int, size> arr2=arr;
	cout<<"array2: ";
	print(arr2);
	vector<int> v2=v;
	cout<<"vector2: ";
	print(v2);
	list<int> l2=l;
	cout<<"list2: ";
	print(l2);
	
	inc(arr2, 2);
	cout<<"inc. array: ";
	print(arr2);	
	inc(v2, 3);
	cout<<"inc. vector: ";
	print(v2);	
	inc(l2, 5);
	cout<<"inc. list: ";
	print(l2);	

	my_copy(arr2.begin(), arr2.end(), v2.begin());
	my_copy(l2.begin(), l2.end(), arr2.begin());
	cout<<"after copy array: ";
	print(arr2);
	cout<<"after copy vector: ";
	print(v2);
	cout<<"after copy list: ";
	print(l2);

	vector<int>::iterator it;
	it=find(v2.begin(),v2.end(),3);
	if(it != v2.end()){
		cout<<"A "<<distance(v2.begin(),it)<<" helyen van."<<endl;
	}
	else cout<<"Nem talaltam meg."<<endl;

	list<int>::iterator lit;
	lit=find(l2.begin(),l2.end(),27);
	if(lit!=l2.end()){
		cout<<"A "<<distance(l2.begin(),lit)<<" helyen van."<<endl;
	}
	else cout<<"Nem talaltam meg."<<endl;

	return 0;
}
