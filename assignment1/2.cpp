#include <iostream>

using namespace std;

int main(){
	int init = 20000;
	int f = 720;
	int af= 80;
	int td;
	int tmp;
	int cf;

	cout<< "Initial Balance : 20000"<<endl;
	while(1){
		cout<< "Entering each travel distance : ";
		cin>> td;

		if(td==-1){
			cout<<"Program Exit"<<endl;
			break;
		}
		if(td<41){
			cout<<"Fare : "<< f<<endl;
			cf=init-f;
			init =cf; 
			cout<<"Current balance: "<<cf<<endl;
		}
		else {
			tmp = (td-40)/8;
			tmp = tmp*af;
			cout<<"Fare : "<<tmp<<endl;
			tmp = tmp + f;
			cf= init-tmp;
			init=cf;
			cout<<"Current balance: " <<cf<<endl;
		}
		

	}


}