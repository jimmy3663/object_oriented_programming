#ifndef _1_HPP
#define _1_HPP

class Human{
friend class HumanList;

private: 
	int Health;
	int Power; 
	int Row, Coloumn;
	int Index;
	Human *prev, *next;
	Human(int h, int p, int row, int col, int in, Human *pr, Human *n): Health(h), Power(p), Row(row), Coloumn(col), Index(in), prev(pr), next(n){}
public:
	void action(Monster *m);

};

class Monster{
friend class MonsterList;
private:
	int Health;
	int Power;
	int Row, Coloumn;
	int Index;
	Monster *prev, *next;
	Monster(int h, int p, int row, int col, int in, Monster *pr, Monster *n): Health(h), Power(p), Row(row), Coloumn(col), Index(in), prev(pr), next(n){}
public:
	void action(Human *h);
};

class HumanList{
private:
	Human *HeadNode;
public:
	HumanList();
	~HumanList();
	void pushback(int, int, int, int, int);

};

HumanList::HumanList(){
	HeadNode=NULL;
}
HumanList::~HumanList(){}
void HumanList::pushback(int h, int p, int r, int c, int in){
	Human *newNode = new Human(h, p, r, c, in, NULL, NULL);
	Human *current=NULL;
	Human *pre = NULL;
	if(HeadNode == NULL)
		HeadNode = newNode;
	else{
		current=HeadNode;
		while(current!=NULL){
			pre = current;
			current=current->next;
		}
		if(current==NULL){
			pre->next = newNode;
			newNode->prev = pre;
		}
	}
}

class MonsterList{
private:
	Monster *HeadNode;
public:
	MonsterList();
	~MonsterList();
	void pushback(int, int, int, int, int);
};

MonsterList::MonsterList(){
	HeadNode=NULL;
}
MonsterList::~MonsterList(){}
void MonsterList::pushback(int h, int p, int r, int c, int in){
	Monster *newNode = new Monster(h, p, r, c, in,NULL, NULL);
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

/*void Human::action(Monster *m){
	int hit=0;
	HumanList *human;

	if((Human->Index) == 1 || (Human->Index) == 2){
		if(m->Row >=(Human->Row)-1 && m->Row <= (Human->Row) +1){
			m->Health -= Human->Power;
		}
		else if(m->Coloumn >= (Human->Coloumn)-1 && m->Coloumn <= (Human->Coloumn)+1){
			m->Health -= Human->Power;
		}
		
	}
}*/


#endif 

