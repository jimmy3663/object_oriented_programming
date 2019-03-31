#include <iostream>

using namespace std;

void asterisk(int num){ // printing diamond asterisk function 
	int a;
	a=num/2;

	for(int i=1; i<=a+1; i++){ // from the top to middle row 
		for(int j=i; j<a+1; j++)
			cout<<" ";
		for(int k=1; k<(i*2);k++)
			cout<<"$";

		cout<<endl;
	}

	for(int i=a; i>=1; i--){ // from middle to bottom row 
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
	cin>>num; //num is input number between 5 ~ 29 
	
	if(num<5) // exception case 
		cout<<"input should be bigger than 4"<<endl;
	else if(num%2==0) // exception case 
		cout<<"input should be odd number"<<endl;
	else 
		asterisk(num);

}