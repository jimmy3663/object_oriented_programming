#include <iostream>

using namespace std;

int main(){
	int init = 20000; // initial value 
	int f = 720; // default fare 
	int af= 80; // additional fare 
	int td; // travel distance 
	int tmp;
	int cf; // current fare 
''
	cout<< "Initial Balance : 20000"<<endl; // initial balance 
	while(1){ // do untill input is -1 
		cout<< "Entering each travel distance : ";
		cin>> td;

		if(td==-1){ // if td is -1 stop 
			cout<<"Program Exit"<<endl;
			break;
		}
		if(td<41){ // if td is lower than 41 
			cout<<"Fare : "<< f<<endl;
			cf=init-f; // current fare is subration from initial value to fare 
			init =cf; // current fare is now initial value 
			cout<<"Current balance: "<<cf<<endl; 
		}
		else {
			if(td>40 && td<48) // 
				tmp = 1;
			else{
				tmp = (td-40)/8; //
				} 
			tmp = tmp*af;
			tmp = tmp + f; 
			cout<<"Fare : "<<tmp<<endl;
			cf= init-tmp;
			init=cf;
			cout<<"Current balance: " <<cf<<endl;
		}
		

	}


}