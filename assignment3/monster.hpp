#ifndef MONSTER_HPP
#define MONSTER_HPP
#include "human.hpp"
#include <iostream>
#include <string>

using namespace std;

//class Human;
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

void Monster::action(Human *h){
	if(h->GetRow() <= Row + 1 && h->GetRow() >= Row -1){
		h->SetHealth(h->GetHealth()-Power);
	}
	else if(h->GetColoumn()<=Coloumn+1 && h->GetColoumn() >= Coloumn-1){
		h->SetHealth(h->GetHealth()-Power);
	}
	else{
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
public:
	MonsterList();
	~MonsterList();
	void pushback(string, int);
	void Print();
	Human *GetHead(){return HeadNode;}
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
		HeadNode = newNode;
	else{
		current=HeadNode;
		while(current!=NULL){
			pre = current;
			current = current->next;
		}
		if(current == NULL){
			pre->next = newNode;
			newNode -> prev = pre;
		}
	}
}

void MonsterList::Print(){
	Monster *current = HeadNode;

	while(current!=NULL){
		cout<<current->Health<<": "<<current->Index<<endl;
		current=current->next;
	}
}


#endif