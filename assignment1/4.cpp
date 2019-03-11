#include <iostream>

using namespace std;

int main(){
	float a, b, c;
	cout<<"input a, b, c: ";
	cin>>a;
	cin>>b;
	cin>>c;

	float answer;

	b= b*b;
	float tmp;
	tmp = b/(4*a);
	answer= c-tmp;
	if(a>0)
		cout<<"minimum is : "<<answer<<endl;
	else 
		cout<<"maximum is : "<<answer<<endl;
}