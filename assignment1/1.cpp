#include <iostream>

using namespace std; 

void asterisk(int num){
	int a;

	a=num/2;

	for(int i= 0; i<a; i++){
		for(int j=0; j<num+2; j++){
			if(i==0){
				//cout<<j;
				if(j==0)
					cout<<"$";
				else if(j==a+1)
					cout<<"$";
				else if(j==num+1)
					cout<<"$";
				else 
					cout<<" ";
			}
			else{
				//cout<<j;
				if(i==j)
					cout<<"$";
				else if(j==a+1)
					cout<<"$";
				else if(j==num+1-i)
					cout<<"$";
				else 
					cout<< " ";
			}
		}
		cout<<endl; 
	}

	for(int i=0; i<num+2; i++){
		if(i==a+1)
			cout<<"$";
		else 
			cout<<" ";
	}
	cout<<endl;

	a=num/2;
	int b;
	b=a-1;

	for(int i=0; i<a; i++){
		for(int j=0; j<num+2; j++){
			if(i==a-1){
				//cout<<j;
				if(j==0)
					cout<<"$";
				else if(j==a+1)
					cout<<"$";
				else if(j==num+1)
					cout<<"$";
				else 
					cout<<" ";
			}
			else{
				//cout<<j;
				if(j==b-i)
					cout<<"$";
				else if(j==a+1)
					cout<<"$";
				else if(j==a+3+i)
					cout<<"$";
				else 
					cout<<" ";
			}
		}
		cout<<endl;
	}

}

int main(){
	int a;
	cout<< "input odd number between 5 ~ 29 :";
	cin>>a;

	if(a%2==0)
		cout<<"input should be odd number!"<<endl;
	if(a<5)
		cout<<"input should be bigger than 4"<<endl;

	asterisk(a);



}