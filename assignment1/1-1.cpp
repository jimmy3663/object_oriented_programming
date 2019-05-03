#include <iostream>

using namespace std; 

void asterisk(int num){ // printing star asterisk function 
	int a;

	a=num/2; 

	for(int i= 0; i<a; i++){ // i is coloumn 
		for(int j=0; j<num; j++){ // j is row 
			if(i==0){
				if(j==0) // in first row condition 
					cout<<"$";
				else if(j==a)
					cout<<"$";
				else if(j==num-1)
					cout<<"$";
				else 
					cout<<" ";
			}
			else{
				if(i==j) // between first row to middle row condition 
					cout<<"$";
				else if(j==a)
					cout<<"$";
				else if(j==num-1-i)
					cout<<"$";
				else 
					cout<< " ";
			}
		}
		cout<<endl; 
	}

	for(int i=0; i<num; i++){ // middle row condition 
		if(i==a)
			cout<<"$";
		else 
			cout<<" ";
	}
	cout<<endl;

	for(int i=0; i<a; i++){ // after the middle row condition 
		for(int j=0; j<num; j++){
			if(i==a-1){
				if(j==0) // last row condition
					cout<<"$";
				else if(j==a)
					cout<<"$";
				else if(j==num-1)
					cout<<"$";
				else 
					cout<<" ";
			}
			else{
				if(j==a-i-1) //from middle to bottom row  
					cout<<"$";
				else if(j==a)
					cout<<"$";
				else if(j==a+i+1)
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
	cin>>a; // a is input number; 
	
	if(a<5) // input number should be bigger than 4 
		cout<<"input should be bigger than 4"<<endl;
	else if(a%2==0) // input number should be odd number 
		cout<<"input should be odd number!"<<endl;
	else
		asterisk(a);

}