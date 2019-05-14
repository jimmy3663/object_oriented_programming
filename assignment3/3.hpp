#ifndef _3_HPP
#define _3_HPP
#include <string>
#include <iostream>
#include <time.h>
#include <vector>

using namespace std;

class Neuron{
friend class NeList;
	private : 
		int value;
		string op;
		Neuron *RightNeuron;
		Neuron *DownNeuron;
		Neuron(int v, string o, Neuron *r, Neuron *d): value(v), op(o), RightNeuron(r), DownNeuron(d){}
};

class NeList{
	private :
		Neuron *HeadNeuron;
		int size;

	public:
		NeList();
		~NeList();
		void Insert(int);
		void Print();
		void Conbreak();
		int Getsize();
		void Cal();
		string sym(string);
		int oper(int, int, string);
};

NeList::NeList(){
	HeadNeuron=NULL;
	size=0;
}
NeList::~NeList(){}

int NeList::Getsize(){return size;}


void NeList::Insert(int n){
	Neuron *prev =NULL;
	Neuron *current =NULL;
	Neuron *newNu;

	if(n == 0)
		newNu = new Neuron(9, "add", NULL, NULL);
	else if(n==1)
		newNu = new Neuron(0, "mul", NULL, NULL);
	else if(n==2)
		newNu = new Neuron(6, " ", NULL , NULL);
	else if(n==3)
		newNu = new Neuron(5, "div", NULL, NULL);
	else if(n==4)
		newNu = new Neuron(3, "sub", NULL , NULL);
	else if(n==5)
		newNu = new Neuron(2," ", NULL , NULL);
	else if(n==6)
		newNu = new Neuron(1, "add", NULL , NULL);
	else if(n==7)
		newNu = new Neuron(7, "div", NULL, NULL);
	else if(n==8)
		newNu = new Neuron(4, " ", NULL, NULL);

	if(HeadNeuron == NULL)
		HeadNeuron = newNu;
	else{
		if(n==3 || n==6){
			current = HeadNeuron;
			while(current!=NULL){
				//cout<<"in while"<<endl;
				prev = current; 
				current = current->DownNeuron;
			}

			if(current==NULL)
				prev->DownNeuron=newNu;
		}
		else{
			current = HeadNeuron;
			if(n>=3){
			//	cout<<"bigger than 2"<<endl;
				while(current!=NULL){
					prev=current;
					current= current->DownNeuron;
				}
				if(current==NULL){
					current = prev;
					while(current!=NULL){
						prev = current;
						current = current->RightNeuron;
					}
					if(current==NULL)
						prev->RightNeuron=newNu;
				}
			}
			else{
				//cout<<"no bigger than 2 "<<endl;
				while(current!=NULL){
					prev =current;
					current= current->RightNeuron;
				}
				if(current==NULL)
					prev->RightNeuron=newNu;
			}
		}

	}
	size++;
}

void NeList::Conbreak(){
	Neuron *current = HeadNeuron;
	Neuron *tmp = NULL;
	vector <int> v;
	srand(1);

	for(int i=0; i<9; i++){
		int hit = 0;
		int breakcon = rand()%10;
	//	cout<<"break : "<<breakcon<<endl;
		if(breakcon == 0){
			if(current->RightNeuron!=NULL){
				current->RightNeuron=NULL;
				hit =1;
				//size--;
			}
		}
		if(hit == 1){
			if(current->DownNeuron==NULL){
			//	cout<<"continue"<<endl;
				continue;
			}
			else
				current = current->DownNeuron;
		}
		if(i==2)
			current=HeadNeuron->DownNeuron;
		else if(i==5)
			current=HeadNeuron->DownNeuron->DownNeuron;
		else
			current=current->RightNeuron;
	}

	current=HeadNeuron;

	for(int i=0; i<9; i++){
		int hit = 0;
		int breakcon = rand()%10;
		//cout<<"break : "<<breakcon<<endl;
		if(breakcon == 0){
			if(current->RightNeuron!=NULL){
				current->RightNeuron=NULL;
				hit =1;
			}
		}
		if(hit == 1){
			if(current->DownNeuron==NULL){
			//	cout<<"continue"<<endl;
				continue;
			}
			else
				current = current->DownNeuron;
		}
		if(i==2)
			current=HeadNeuron->DownNeuron;
		else if(i==5)
			current=HeadNeuron->DownNeuron->DownNeuron;
		else
			current=current->RightNeuron;
	}

}

int NeList::oper(int v1, int v2, string op){
	int result;
	if(op=="add")
		return result = v1 + v2;
	else if(op == "sub")
		return result = v1 - v2;
	else if(op == "mul")
		return result = v1*v2;
	else if(op == "div")
		return result = v1 / v2;
	else 
		return 0;
}

string NeList::sym(string op){
	string result;
	if(op=="add")
		return result = "+";
	else if(op == "sub")
		return result = "-";
	else if(op == "mul")
		return result = "*";
	else if(op == "div")
		return result = "/";
	else 
		return NULL;
}

void NeList::Cal(){
	Neuron *current = HeadNeuron;
	int result;
	Neuron *second = HeadNeuron->DownNeuron;
	Neuron *third = HeadNeuron->DownNeuron->DownNeuron;
	cout<<current->value;
	while(1){
		if(current->RightNeuron!=NULL){
			result=oper(current->value, current->RightNeuron->value, current->op);
			cout<<sym(current->op)<<current->RightNeuron->value;
			current->RightNeuron->value=result;
			current=current->RightNeuron;
		}
		else if(current->RightNeuron==NULL){
			cout<<"="<<current->value<<endl;
			break;
		}
	}

	cout<<second->value;
	while(1){
		if(second->RightNeuron!=NULL){
			result=oper(second->value, second->RightNeuron->value, second->op);
			cout<<sym(second->op)<<second->RightNeuron->value;
			second->RightNeuron->value=result;
			second=second->RightNeuron;
		}
		else if(second->RightNeuron==NULL){
			cout<<"="<<second->value<<endl;
			break;
		}
	}

	cout<<third->value;
	while(1){
		if(third->RightNeuron!=NULL){
			result=oper(third->value, third->RightNeuron->value, third->op);
			cout<<sym(third->op)<<third->RightNeuron->value;
			third->RightNeuron->value=result;
			third=third->RightNeuron;
		}
		else if(third->RightNeuron==NULL){
			cout<<"="<<third->value<<endl;
			break;
		}
	}
	

}

void NeList::Print(){
	Neuron *current =HeadNeuron;

	int i=0;
	
	for(int i=0; i<9; i++){
		
		if(i==3){
			current=HeadNeuron->DownNeuron;
			cout<<endl;
		}
		else if(i == 6){
			current=HeadNeuron->DownNeuron->DownNeuron;
			cout<<endl;
		}
		if(current==NULL){
			continue;
		}
		else{
			cout<<current->value<<": "<<current->op<<" ";
			current= current->RightNeuron;
		}
	}
	cout<<endl;
}

#endif