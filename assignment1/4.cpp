#include <iostream>

using namespace std;

int main(){
	int a, b, c;

	int max=0; // maximum 
	int min=0; // minimum 

	cout<<"input a, b, c: ";
	cin>>a;
	cin>>b;
	cin>>c;

	for(int i=-30; i<=30; i++){
		int tmp = a*i*i + b*i + c;
		if(max<tmp) // if tmp is bigger than max 
			max=tmp; // max is tmp
	}

	for(int i=-30; i<=30; i++){
		int tmp= a*a*i + b*i + c;
		if(min>tmp) // if minimum is smaller than tmp 
			min=tmp; // them minimum is tmp 
	}

	cout<<"max : "<<max<<endl;
	cout<<"min : "<<min<<endl;

}