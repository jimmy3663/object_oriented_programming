#include <iostream>

using namespace std;

void asterisk(int num){
	int a;
	a=num/2;

	for(int i=1; i<=a+1; i++){
		for(int j=i; j<a+1; j++)
			cout<<" ";
		for(int k=1; k<(i*2);k++)
			cout<<"$";

		cout<<endl;
	}

	for(int i=a; i>=1; i--){
		for(int j=a+1;j>i;j--)
			cout<<" ";
		for(int k=1; k<(i*2);k++)
			cout<<"$";

		cout<<endl;
	}

}



int main(){
	int num;

	cout<<"input odd number between 5~29 : ";
	cin>>num;
	
	if(num<5)
		cout<<"input should be bigger than 4"<<endl;
	else if(num%2==0)
		cout<<"input should be odd number"<<endl;
	else
		asterisk(num);

}