#ifndef HUMAN_HPP
#define HUMAN_HPP
//#include "monster.hpp"
//#include "job.hpp"

#include <iostream>
#include <string>

using namespace std;

class Monster;

class Human{
friend class HumanList;
private: 
	int Health;
	int Power; 
	int Row, Coloumn;
	int Index;
	Human *prev, *next;
public:
	Human(int h, int p, int row, int col, int in, Human *pr, Human *n): Health(h), Power(p), Row(row), Coloumn(col), Index(in), prev(pr), next(n){}
	~Human();
	void action(Monster *m);
	void SetHealth(int h){Health=h;}
	int GetHealth(){return Health;}
	int GetPower(){return Power;}
	int GetRow(){return Row;}
	int GetColoumn(){return Coloumn;}
	Human *Getnext(){return next;}

};

class Monster{
friend class MonsterList;
private:
	int Health;
	int Power;
	int Row, Coloumn;
	string Index;
	Monster *prev, *next;
public:
	Monster(int h, int p, int row, int col, string in, Monster *pr, Monster *n): Health(h), Power(p), Row(row), Coloumn(col), Index(in), prev(pr), next(n){}
	void action(Human *h);
	int GetHealth(){return Health;}
	int GetPower(){return Power;}
	int GetRow(){return Row;}
	int GetColoumn(){return Coloumn;}
	void SetHealth(int h){Health = h;}
	Monster *Getnext(){return next;}
	~Monster();
};

Human::~Human(){}

void Human::action(Monster *m){

	if(m->GetRow() == (Row + 1) || m->GetRow() == (Row-1) || m->GetRow() == Row){
		m->SetHealth(m->GetHealth()-Power);
		cout<<"Human hit!!"<<endl;
	}
	else if(m->GetColoumn() == (Coloumn+1) || m->GetColoumn() == (Coloumn-1) || m->GetColoumn() == Coloumn){
		m->SetHealth(m->GetHealth()-Power);
		cout<<"Human Hit!!"<<endl;
	}
	else {
		cout<<"HUman Moving"<<endl;
		if(m->GetRow() - Row == 0){
			Row++;
		}
		else if(m->GetColoumn() - Coloumn == 0){
			Coloumn ++;
		}
		else {
			Row++;
		}
	}
}

class Peasant:public Human{
public:
	Peasant(int h, int p, int r, int c, int in, Human *pr, Human *n):Human(h, p, r, c, in, pr, n){}

};

class Sword:public Human{
public:
	Sword(int h, int p, int r, int c, int in, Human* pr, Human *n):Human(h, p, r, c, in, pr, n){}
};

class Archer:public Human{
public:
	Archer(int h, int p, int r, int c, int in, Human* pr, Human *n):Human(h, p, r, c, in, pr, n){}
	void action(Monster *m);
};

class Warlock:public Human{
	private: int mana;
public:
	Warlock(int h, int p, int r, int c, int in, Human* pr, Human *n, int m):Human(h, p, r, c, in, pr, n){mana = m;}
	void action(Monster *m);
};



class HumanList{
private:
	Human *HeadNode;
	Human *TailNode; 
public:
	HumanList();
	~HumanList();
	void pushback(int);
	void Print();
	void DeleteList(Human *h);
	Human *GetHead(){return HeadNode;}
};

HumanList::HumanList(){
	HeadNode=NULL;
}
HumanList::~HumanList(){}

void HumanList::pushback(int index){
	Human *newNode =NULL;
	if(index == 0)
		newNode = new Peasant(5,5,index, 0, index+1, NULL, NULL);
	else if(index == 1 || index == 2)
		newNode = new Sword(10, 10, index, 0, index+1, NULL, NULL);
	else if(index == 3)
		newNode = new Archer(7, 10, index, 0, index+1, NULL, NULL);
	else if(index == 4)
		newNode = new Warlock(3, 10, index, 0, index+1, NULL, NULL, 1);
	

	Human *current=NULL;
	Human *pre = NULL;

	if(HeadNode == NULL)
		HeadNode = TailNode = newNode;
	else{
		current=HeadNode;
		while(current!=NULL){
			pre = current;
			current=current->next;
		}
		if(current==NULL){
			pre->next = newNode;
			newNode->prev = pre;
			TailNode = newNode;
		}
	}
}

void HumanList::Print(){
	Human *current = HeadNode;

	while(current!=NULL){
		cout<<current->Index<<endl;
		current=current->next;
	}
}

void HumanList::DeleteList(Human *h){
	cout<<h->Index<<" died"<<endl;
	if(h == HeadNode){
		HeadNode = h->next;
		delete h;
	}
	else if(h==TailNode){
		TailNode = h->prev;
		delete h;
	}
	else{
		h->prev->next = h->next;
		h->next->prev = h->prev;
		delete h;
	}
}

////////////////////////////////////////////////////////////////////////////////

Monster::~Monster(){}

void Monster::action(Human *h){
	if(h->GetRow() <= Row + 1 && h->GetRow() >= Row -1){
		cout<<"MOnster Hit!!"<<endl;
		h->SetHealth(h->GetHealth()-Power);
	}
	else if(h->GetColoumn()<=Coloumn+1 && h->GetColoumn() >= Coloumn-1){
		cout<<"Monster Hit!!"<<endl;
		h->SetHealth(h->GetHealth()-Power);
	}
	else{
		cout<<"MOnster Move!!"<<endl;
		if(h->GetRow() - Row == 0){
			Row++;
		}
		else if(h->GetColoumn() - Coloumn == 0){
			Coloumn ++;
		}
		else {
			Row++;
		}
	}
}

class MonsterList{
private:
	Monster *HeadNode;
	Monster *TailNode;
public:
	MonsterList();
	~MonsterList();
	void pushback(string, int);
	void Print();
	Monster *GetHead(){return HeadNode;}
	void DeleteList(Monster *m);

};

MonsterList::MonsterList(){
	HeadNode=NULL;
}
MonsterList::~MonsterList(){}
void MonsterList::pushback(string a, int in){
	Monster *newNode = new Monster(20, 7, in, 4, a, NULL, NULL);
	Monster *current = NULL;
	Monster *pre = NULL;

	if(HeadNode == NULL)
		HeadNode = TailNode = newNode;
	else{
		current=HeadNode;
		while(current!=NULL){
			pre = current;
			current = current->next;
		}
		if(current == NULL){
			pre->next = newNode;
			newNode -> prev = pre;
			TailNode = newNode;
		}
	}
}

void MonsterList::Print(){
	Monster *current = HeadNode;

	while(current!=NULL){
		cout<<current->Index<<endl;
		current=current->next;
	}
}

void MonsterList::DeleteList(Monster *m){
	cout<<m->Index<<" died"<<endl;

	if(m == HeadNode){
		HeadNode = m -> next;
		delete m;
	}
	else {
		m->prev->next = m->next;
		m->next->prev = m->prev;
		delete m;
	}
}



#endif