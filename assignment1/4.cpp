#include <iostream>

using namespace std;

int main(){
	int a, b, c;

	int max=0;
	int min=0;

	cout<<"input a, b, c: ";
	cin>>a;
	cin>>b;
	cin>>c;

	/*float answer;

	b= b*b;
	float tmp;
	tmp = b/(4*a);
	answer= c-tmp;
	if(a>0)
		cout<<"minimum is : "<<answer<<endl;
	else 
		cout<<"maximum is : "<<answer<<endl;*/

	for(int i=-30; i<=30; i++){
		int tmp = a*i*i + b*i + c;
		if(max<tmp)
			max=tmp;
	}

	for(int i=-30; i<=30; i++){
		int tmp= a*i*i + b*i + c;
		if(min>tmp)
			min=tmp;
	}

	cout<<"max : "<<max<<endl;
	cout<<"min : "<<min<<endl;

}