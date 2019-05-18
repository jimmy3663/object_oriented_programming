#ifndef HUMAN_HPP
#define HUMAN_HPP
//#include "monster.hpp"
//#include "job.hpp"

#include <iostream>
#include <string>
#include <vector>
#include <utility>

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
	virtual void action(Monster *m);
	void SetHealth(int h){Health=h;}
	int GetHealth(){return Health;}
	int GetPower(){return Power;}
	int GetRow(){return Row;}
	int GetColoumn(){return Coloumn;}
	int GetIndex(){return Index;}
	Human *Getnext(){return next;}
	void SetRow(int r){Row =r;}
	void SetColoumn(int c){Coloumn=c;}


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
	string GetIndex(){return Index;}
	void SetHealth(int h){Health = h;}
	void SetRow(int r){Row = r;}
	void SetColoumn(int c){Coloumn=c;}
	Monster *Getnext(){return next;}
	Monster *Getprev(){return prev;}
	~Monster();
};

Human::~Human(){}

void Human::action(Monster *m){
	int hit=0;
	Monster *tmp = m;
	//cout<<m->GetIndex()<<endl;
	while(m!=NULL){
		if(m->GetRow() == Row){
			//cout<<"in Row "<<endl;
			if(m->GetColoumn() == Coloumn +1){
				cout<<Index<<" Hit "<<m->GetIndex()<<endl;
				m->SetHealth(m->GetHealth()-Power);
				hit=1;
				break;
			}
			else if(m->GetColoumn() == Coloumn-1){
				cout<<Index<<" Hit "<<m->GetIndex()<<endl;
				m->SetHealth(m->GetHealth()-Power);
				hit=1;
				break;
			}
		}
		else if((m->GetColoumn() == Coloumn )){
			//cout<<"in coloumn"<<endl;
			if(m->GetRow() == Row+1){
				cout<<Index<<" Hit "<<m->GetIndex()<<endl;
				m->SetHealth(m->GetHealth()-Power);
				hit=1;
				break;
			}
			else if(m->GetRow() == Row-1){
				cout<<Index<<" Hit "<<m->GetIndex()<<endl;
				m->SetHealth(m->GetHealth()-Power);
				hit=1;
				break;
			}
		}
		m = m->Getnext();
	}

	m=tmp;
	int move = 0;
	if(hit==0){
		while(m!=NULL){
			if(m->GetRow() == Row){
				if(m->GetColoumn() > Coloumn){
					cout<<Index<<" move "<<endl;
					Coloumn++;
				}
				else if(m->GetColoumn() < Coloumn){
					cout<<Index<<" move "<<endl;
					Coloumn--;
				}

				move = 1;
				break;
			}
			else 
				m = m->Getnext();
		}

		m=tmp;

		pair <string, int> p;
		vector <pair <string, int> > v;
		if(move == 0){
			int r=0, c=0;

			while(m!=NULL){
				if(m->GetRow() > Row)
					r = m->GetRow() - Row;
				else 
					r = Row - m->GetRow();
				if(m->GetColoumn() > Coloumn)
					c = m->GetColoumn() - Coloumn;
				else 
					c = Coloumn - m->GetColoumn();

				p=make_pair(m->GetIndex() , r+c);
				v.push_back(p);
				m= m->Getnext();
			}

			int small = v[0].second;
			vector <string> name; 
			int cnt=0;
			for(int i=1; i<v.size(); i++){
				if(small > v[i].second){
					small = v[i].second;
					name.push_back(v[i].first);
					cnt++;
				}
			}
			if(cnt==0)
				name.push_back(v[0].first);

			m = tmp;
			pair <string, int> p2;
			vector < pair<string, int> > v2;
			for(int i=0; i< name.size() ; i++){
				while(m!=NULL){
					if(m->GetIndex() == name[i]){
						if(m->GetRow() > Row)
							r = m->GetRow() - Row;
						else 
							r = Row - m->GetRow();
						
						p2 = make_pair(m->GetIndex(), r);
						v2.push_back(p2);
					}
					m=m->Getnext();
				}
				m=tmp;
			}

			small = v2[0].second;
			string target;
			cnt=0;
			for(int i=1; i<v2.size() ; i++){
				if(small > v2[i].second){
					target = v2[i].first;
					cnt++;
				}
			}

			if(cnt==0){
				target = v2[0].first;
			}
			m=tmp;
			while(m!=NULL){
				if(m->GetIndex() == target){
					if(m->GetColoumn() > Coloumn){
						cout<<"Human move coloumn++"<<endl;
						Coloumn++;
						break;
					}
					else if(m->GetColoumn() < Coloumn){
						cout<<"HUman move coloumn --"<<endl;
						Coloumn--;
						break;
					}
					else{
						if(m->GetRow() > Row){
							cout<<"Human move Row ++"<<endl;
							Row++;
							break;
						}
						else if(m->GetRow() < Row){
							cout<<"Humna move Row --"<<endl;
							Row --;
							break;
						}
					}
				}
				m=m->Getnext();
			}


		}

	}
}

class Peasant:public Human{
public:
	Peasant(int h, int p, int r, int c, int in, Human *pr, Human *n):Human(h, p, r, c, in, pr, n){}
	//void action(Monster *m);
};


class Sword:public Human{
public:
	Sword(int h, int p, int r, int c, int in, Human* pr, Human *n):Human(h, p, r, c, in, pr, n){}
	//void action(Monster *m);
};


class Archer:public Human{
public:
	Archer(int h, int p, int r, int c, int in, Human* pr, Human *n):Human(h, p, r, c, in, pr, n){}
	void action(Monster *m);
};

void Archer::action(Monster *m){
	//cout<<GetRow()<<endl;
	int hit=0;
	Monster *tmp = m;
	while(m!=NULL){
		if(m->GetRow() == GetRow() && m->GetColoumn() <= GetColoumn() +2 && m->GetColoumn() >= GetColoumn()-2){
			cout<<"Archer Hit "<<m->GetIndex()<<endl;
			m->SetHealth(m->GetHealth()-GetPower());
			hit=1;
			break;
		}
		m=m->Getnext();
	}
	m = tmp;
	if(hit==0){
		while(m!=NULL){
			if((m->GetRow() <= (GetRow() + 1) )&& (m->GetRow() >= (GetRow() -1) )&& (m->GetColoumn() <= (GetColoumn()+1) )&& (m->GetColoumn() >= GetColoumn()-1)){
				cout<<"Archer Hit!!"<<m->GetIndex()<<endl;
				m->SetHealth(m->GetHealth()-GetPower());
				hit =1;
				break;
			}
			else if( (m->GetColoumn()== GetColoumn()) && (m->GetRow()==GetRow()+2)){
				cout<<"Archer Hit!!"<<m->GetIndex()<<endl;
				m->SetHealth(m->GetHealth()-GetPower());
				hit =1;
				break;
			}
			else if((m->GetColoumn() == GetColoumn() )&& (m->GetRow() == GetRow()-2)){
				cout<<"Archer Hit!!"<<m->GetIndex()<<endl;
				m->SetHealth(m->GetHealth()-GetPower());
				hit =1;
				break;
			}
			else if( (m->GetRow() == GetRow() )&& ( m->GetColoumn() == GetColoumn()+2 )){
				cout<<"Archer Hit!!"<<m->GetIndex()<<endl;
				m->SetHealth(m->GetHealth()-GetPower());
				hit=1;
				break;
			}
			else if( (m->GetRow() == GetRow()) && (m->GetColoumn() == GetColoumn()-2)){
				cout<<"Archer Hit!!"<<m->GetIndex()<<endl;
				m->SetHealth(m->GetHealth()-GetPower());
				hit=1;
				break;
			}
			m= m->Getnext();
		}
	}

	m=tmp;
	int move = 0;
	if(hit==0){
		while(m!=NULL){
			if(m->GetRow() == GetRow()){
				if(m->GetColoumn() > GetColoumn()){
					cout<<"Human hit 0 coloumn++"<<endl;
					SetColoumn(GetColoumn()+1);
				}
				else if(m->GetColoumn() < GetColoumn()){
					cout<<"Human hit 0 coloumn--"<<endl;
					SetColoumn(GetColoumn()-1);
				}

				move = 1;
				break;
			}
			else 
				m = m->Getnext();
		}

		m=tmp;

		pair <string, int> p;
		vector <pair <string, int> > v;
		if(move == 0){
			int r=0, c=0;

			while(m!=NULL){
				if(m->GetRow() > GetRow())
					r = m->GetRow() - GetRow();
				else 
					r = GetRow() - m->GetRow();
				if(m->GetColoumn() > GetColoumn())
					c = m->GetColoumn() - GetColoumn();
				else 
					c = GetColoumn() - m->GetColoumn();

				p=make_pair(m->GetIndex() , r+c);
				v.push_back(p);
				m= m->Getnext();
			}

			int small = v[0].second;
			vector <string> name; 
			int cnt=0;
			for(int i=1; i<v.size(); i++){
				if(small > v[i].second){
					small = v[i].second;
					name.push_back(v[i].first);
					cnt++;
				}
			}
			if(cnt==0)
				name.push_back(v[0].first);

			m = tmp;
			pair <string, int> p2;
			vector < pair<string, int> > v2;
			for(int i=0; i< name.size() ; i++){
				while(m!=NULL){
					if(m->GetIndex() == name[i]){
						if(m->GetRow() > GetRow())
							r = m->GetRow() - GetRow();
						else 
							r = GetRow() - m->GetRow();
						
						p2 = make_pair(m->GetIndex(), r);
						v2.push_back(p2);
					}
					m=m->Getnext();
				}
				m=tmp;
			}

			small = v2[0].second;
			string target;
			cnt=0;
			for(int i=1; i<v2.size() ; i++){
				if(small > v2[i].second){
					target = v2[i].first;
					cnt++;
				}
			}

			if(cnt==0){
				target = v2[0].first;
			}
			m=tmp;
			while(m!=NULL){
				if(m->GetIndex() == target){
					if(m->GetColoumn() > GetColoumn()){
						cout<<"Human move coloumn++"<<endl;
						SetColoumn(GetColoumn()+1);
						break;
					}
					else if(m->GetColoumn() < GetColoumn()){
						cout<<"HUman move coloumn --"<<endl;
						SetColoumn(GetColoumn()-1);
						break;
					}
					else{
						if(m->GetRow() > GetRow()){
							cout<<"Human move Row ++"<<endl;
							SetRow(GetRow()+1);
							break;
						}
						else if(m->GetRow() < GetRow()){
							cout<<"Human move Row --"<<endl;
							SetRow(GetRow()-1);
							break;
						}
					}
				}
				m=m->Getnext();
			}


		}

	}
}

class Warlock:public Human{
	private: int mana;
public:
	Warlock(int h, int p, int r, int c, int in, Human* pr, Human *n, int m):Human(h, p, r, c, in, pr, n){mana = m;}
	void action(Monster *m);
};

void Warlock::action(Monster *m){
	cout<<GetIndex()<<" move"<<endl;
	SetColoumn(GetColoumn()+1);
}

class HumanList{
private:
	Human *HeadNode;
	Human *TailNode; 
	int size;
public:
	HumanList();
	~HumanList();
	void pushback(int);
	void Print();
	void DeleteList(Human *h);
	int GetSize(){return size;}
	Human *GetHead(){return HeadNode;}
	Human *GetTail(){return TailNode;}
};

HumanList::HumanList(){
	HeadNode=NULL;
	size=0;
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

	if(HeadNode == NULL){
		HeadNode = TailNode = newNode;
		size++;
	}
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
			size++;
		}
	}
}

void HumanList::Print(){
	Human *current = HeadNode;

	while(current!=NULL){
		cout<<current->Index<<" HP: "<<current->Health<<" Row : "<<current->Row<<" Coloumn : "<<current->Coloumn<<endl;
		current=current->next;
	}
}

void HumanList::DeleteList(Human *hu){

	Human *h = HeadNode;
	if(size == 1){
		HeadNode = NULL;
		delete h;
	}
	else{
		while(h!=NULL){
			if(h->Health<=0){
				cout<<h->Index<<" died"<<endl;
				if(h == HeadNode){
					h->next->prev = NULL;
					HeadNode = h->next;
					size--;
					delete h;
				}
				else if(h==TailNode){
					h->prev->next = NULL;
					TailNode = h->prev;
					size--;
					delete h;
				}
				else{
					h->prev->next = h->next;
					h->next->prev = h->prev;
					size--;
					delete h;
				}
			}
			h = h->next;
		}
	}
	//cout<<"HeadNOde: "<<HeadNode->Index<<endl;
}

////////////////////////////////////////////////////////////////////////////////

Monster::~Monster(){}

void Monster::action(Human *h){
	
	int hit=0;
	Human *tmp = h;

	while(h!=NULL){
		if(h->GetRow() == Row){
			if(h->GetColoumn() <= Coloumn +1 && h->GetColoumn() >= Coloumn-1){// && h->GetRow() <= Row+1 && h->GetRow() >= Row-1){
				cout<<Index<<" Hit "<<h->GetIndex()<<endl;
				h->SetHealth(h->GetHealth()-Power);
				hit=1;
				break;
			}
		}
		h = h->Getnext();
	}
	cout<<"1"<<endl;
	h = tmp;
	if(hit==0){
		while(h!=NULL){
			if(h->GetRow() <= Row+1 && h->GetRow() >= Row-1 && h->GetColoumn() <= Coloumn +1 && h->GetColoumn() >= Coloumn-1){
				cout<<Index<<" Hit "<<h->GetIndex()<<endl;
				h->SetHealth(h->GetHealth()-Power);
				hit=1;
				break;
			}
			
			h=h->Getnext();
		}
	}

	
	h=tmp;
	int move = 0;
	if(hit==0){
		while(h!=NULL){
			if(h->GetRow() == Row){
				if(h->GetColoumn() > Coloumn){
					cout<<Index<<" move"<<endl;
					Coloumn++;
				}
				else if(h->GetColoumn() < Coloumn){
					cout<<Index<<" move"<<endl;
					Coloumn--;
				}

				move = 1;
				break;
			}
			else 
				h = h->Getnext();
		}

		cout<<"3"<<endl;
		h=tmp;

		pair <int, int> p;
		vector <pair <int, int> > v;


		if(move == 0){
			int r=0, c=0;
			
			while(h!=NULL){
				cout<<"4"<<endl;
				if(h->GetRow() > Row)
					r = h->GetRow() - Row;
				else 
					r = Row - h->GetRow();
				if(h->GetColoumn() > Coloumn)
					c = h->GetColoumn() - Coloumn;
				else 
					c = Coloumn - h->GetColoumn();

				p=make_pair(h->GetIndex() , r+c);
				v.push_back(p);
				h= h->Getnext();
			}

			cout<<"5"<<endl;
			int small = v[0].second;
			vector <int> name; 
			int cnt=0;
			for(int i=1; i<v.size(); i++){
				if(small > v[i].second){
					small = v[i].second;
					name.push_back(v[i].first);
					cnt++;
				}
			}

			if(cnt==0)
				name.push_back(v[0].first);

			h = tmp;
			pair <int, int> p2;
			vector < pair<int, int> > v2;
			for(int i=0; i< name.size() ; i++){
				while(h!=NULL){
					if(h->GetIndex() == name[i]){
						if(h->GetRow() > Row)
							r = h->GetRow() - Row;
						else 
							r = Row - h->GetRow();
						
						p2 = make_pair(h->GetIndex(), r);
						v2.push_back(p2);
					}
					h=h->Getnext();
				}
				h=tmp;
			}

			small = v2[0].second;
			int target;
			cnt=0;
			for(int i=1; i<v2.size() ; i++){
				if(small > v2[i].second){
					target = v2[i].first;
					cnt++;
				}
			}
			if(cnt==0){
				target = v2[0].first;
			}

			h=tmp;
			while(h!=NULL){
				if(h->GetIndex() == target){
					if(h->GetColoumn() > Coloumn){
						cout<<Index<<" move"<<endl;
						Coloumn++;
						break;
					}
					else if(h->GetColoumn() < Coloumn){
						cout<<Index<<" move"<<endl;
						Coloumn--;
						break;
					}
					else{
						if(h->GetRow() > Row){
							cout<<Index<<" move"<<endl;
							Row++;
							break;
						}
						else if(h->GetRow() < Row){
							cout<<Index<<" move"<<endl;
							Row --;
							break;
						}
					}
				}
				h=h->Getnext();
			}


		}

	}
}

class MonsterList{
private:
	Monster *HeadNode;
	Monster *TailNode;
	int size;
public:
	MonsterList();
	~MonsterList();
	void pushback(string, int);
	void Print();
	int GetSize(){return size;}
	Monster *GetHead(){return HeadNode;}
	Monster *GetTail(){return TailNode;}
	void DeleteList(Monster *m);

};

MonsterList::MonsterList(){
	HeadNode=NULL;
	size=0;
}
MonsterList::~MonsterList(){}
void MonsterList::pushback(string a, int in){
	Monster *newNode = new Monster(20, 7, in, 4, a, NULL, NULL);
	Monster *current = NULL;
	Monster *pre = NULL;

	if(HeadNode == NULL){
		HeadNode = TailNode = newNode;
		size++;
	}
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
			size++;
		}
	}
}

void MonsterList::Print(){
	Monster *current = HeadNode;

	while(current!=NULL){
		cout<<current->Index<<" HP: "<<current->Health<<" Row: "<<current->Row<<" Coloumn : "<<current->Coloumn<< endl;
		current=current->next;
	}
}

void MonsterList::DeleteList(Monster *mo){
	Monster *m = HeadNode;

	if(size == 1){
		HeadNode =NULL;
		delete m;
	}
	else{
		while(m!=NULL){
			if(m->Health <=0){
				cout<<m->Index<<" died"<<endl;
				if(m == HeadNode){
					m->next->prev = NULL;
					HeadNode = m -> next;
					size--;
					delete m;
				}
				else if(m == TailNode){
					m->prev->next = NULL;
					TailNode = m->prev;
					size--;
					delete m;
				}
				else {
					m->prev->next = m->next;
					m->next->prev = m->prev;
					size--;
					delete m;
				}
			}
			m=m->next;
		}
	}
}


#endif