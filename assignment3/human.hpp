#ifndef HUMAN_HPP
#define HUMAN_HPP

#include <iostream>
#include <string>
#include <vector>
#include <utility>

using namespace std;

class Monster; // pre declaration for Human class member fucntion 

class Human{ // Human class 
friend class HumanList;
private: 
	int Health; // human health 
	int Power;  // human power 
	int Row, Coloumn; // human row and coloumn 
	int Index; // human index 
	Human *prev, *next; // next node , previous node 
public:
	Human(int h, int p, int row, int col, int in, Human *pr, Human *n): Health(h), Power(p), Row(row), Coloumn(col), Index(in), prev(pr), next(n){} // constructor 
	~Human(); // destructor 
	virtual void action(Monster *m); // action function for moving and attacking 
	void SetHealth(int h){Health=h;} // access private variable and modify human health 
	int GetHealth(){return Health;} // access private variable and return health 
	int GetPower(){return Power;} // get return power 
	int GetRow(){return Row;} // get return row 
	int GetColoumn(){return Coloumn;} // get return coloumn 
	int GetIndex(){return Index;} // get return index 
	Human *Getnext(){return next;} // get return next 
	void SetRow(int r){Row =r;} // modify row 
	void SetColoumn(int c){Coloumn=c;} // modify coloumn 


};

class Monster{ 
friend class MonsterList;
private:
	int Health; // monster health 
	int Power; // monster power 
	int Row, Coloumn; // monster row and coloumn 
	string Index; // monster index 
	Monster *prev, *next; // next node and previous node 
public:
	Monster(int h, int p, int row, int col, string in, Monster *pr, Monster *n): Health(h), Power(p), Row(row), Coloumn(col), Index(in), prev(pr), next(n){} // constructor 
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
	~Monster(); // destrcutor 
};

Human::~Human(){} // human destructor 

void Human::action(Monster *m){ // human action function 
	int hit=0; // if human hit then 1 if not 0 
	Monster *tmp = m; // tmp for monster's head node 
	//cout<<m->GetIndex()<<endl;
	while(m!=NULL){ // if monster node is not null 

/////////////// Human's attack range ///////////////////

		if(m->GetRow() == Row){ //  hit monster first which is on the same row 
			if(m->GetColoumn() == Coloumn +1){ 
				m->SetHealth(m->GetHealth()-Power);
				hit=1;
				break;
			}
			else if(m->GetColoumn() == Coloumn-1){
				m->SetHealth(m->GetHealth()-Power);
				hit=1;
				break;
			}
		}
		else if((m->GetColoumn() == Coloumn )){
			//cout<<"in coloumn"<<endl;
			if(m->GetRow() == Row+1){
				m->SetHealth(m->GetHealth()-Power);
				hit=1;
				break;
			}
			else if(m->GetRow() == Row-1){
				m->SetHealth(m->GetHealth()-Power);
				hit=1;
				break;
			}
		}
		m = m->Getnext();
	}

//////////////////////////////////////////////////////

	m=tmp;
	int move = 0;
	if(hit==0){ // if human didn't hit 

///////////////////// verify which monster is the cloest ////////////////////

		while(m!=NULL){
			if(m->GetRow() == Row){ // move first to monster which is on the same row 
				if(m->GetColoumn() > Coloumn){
					Coloumn++;
				}
				else if(m->GetColoumn() < Coloumn){
					Coloumn--;
				}

				move = 1;
				break;
			}
			else 
				m = m->Getnext();
		}

		m=tmp; // monster's head node 

		pair <string, int> p; // pair for monster's index and distance between human and monster 
		vector <pair <string, int> > v;
		if(move == 0){ // if there is no monster on the same row 
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

				p=make_pair(m->GetIndex() , r+c); // make pair with monster's index and distance between human and monster 
				v.push_back(p); // store in vector 
				m= m->Getnext(); 
			}

			int small = v[0].second; // variable for smallest distance fram first vector 
			vector <string> name;  // get monster's index 
			int cnt=0;

///////////// identify which monster has closet distance ///////////////

			for(int i=1; i<v.size(); i++){
				if(small > v[i].second){
					small = v[i].second;
					name.push_back(v[i].first);
					cnt++;
				}
			}
			if(cnt==0)// if there are no monsters which has same smallest distance 
				name.push_back(v[0].first); 

			m = tmp; // monster's head node 
			pair <string, int> p2; // make pair with monster's index and distance between human's row and monster's row 
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
			string target; // get monster which has closest distance between humans's row and monster's row 
			cnt=0;
			for(int i=1; i<v2.size() ; i++){
				if(small > v2[i].second){
					target = v2[i].first;
					cnt++;
				}
			}

			if(cnt==0){ // if only one monster 
				target = v2[0].first;
			}

//////////////////////////////////////////////////////////////////////////////

			m=tmp; // monster's head node 
			while(m!=NULL){

///////////////// Human moving depend on monster's location ///////////
				if(m->GetIndex() == target){
					if(m->GetColoumn() > Coloumn){
						Coloumn++;
						break;
					}
					else if(m->GetColoumn() < Coloumn){
						Coloumn--;
						break;
					}
					else{
						if(m->GetRow() > Row){
							Row++;
							break;
						}
						else if(m->GetRow() < Row){
							Row --;
							break;
						}
					}
				}
/////////////////////////////////////////////////////////////////////////
				m=m->Getnext();
			}


		}

	}
}

class Peasant:public Human{ // child class Peasant 
public:
	Peasant(int h, int p, int r, int c, int in, Human *pr, Human *n):Human(h, p, r, c, in, pr, n){}

};


class Sword:public Human{ // child class Sword 
public:
	Sword(int h, int p, int r, int c, int in, Human* pr, Human *n):Human(h, p, r, c, in, pr, n){}

};


class Archer:public Human{ // child class archer 
public:
	Archer(int h, int p, int r, int c, int in, Human* pr, Human *n):Human(h, p, r, c, in, pr, n){}
	void action(Monster *m); //Human action member fucntion overloading 
};

void Archer::action(Monster *m){// overloading fucntion 
	int hit=0;
	Monster *tmp = m;

///////////////////////////// Archer's hit range //////////////////////////////
	while(m!=NULL){
		if(m->GetRow() == GetRow() && m->GetColoumn() <= GetColoumn() +2 && m->GetColoumn() >= GetColoumn()-2){
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
				m->SetHealth(m->GetHealth()-GetPower());
				hit =1;
				break;
			}
			else if( (m->GetColoumn()== GetColoumn()) && (m->GetRow()==GetRow()+2)){
				m->SetHealth(m->GetHealth()-GetPower());
				hit =1;
				break;
			}
			else if((m->GetColoumn() == GetColoumn() )&& (m->GetRow() == GetRow()-2)){
				m->SetHealth(m->GetHealth()-GetPower());
				hit =1;
				break;
			}
			else if( (m->GetRow() == GetRow() )&& ( m->GetColoumn() == GetColoumn()+2 )){
				m->SetHealth(m->GetHealth()-GetPower());
				hit=1;
				break;
			}
			else if( (m->GetRow() == GetRow()) && (m->GetColoumn() == GetColoumn()-2)){
				m->SetHealth(m->GetHealth()-GetPower());
				hit=1;
				break;
			}
			m= m->Getnext();
		}
	}
///////////////////////////////////////////////////////////////////////////////
	m=tmp;
	int move = 0;
	if(hit==0){
		while(m!=NULL){
			if(m->GetRow() == GetRow()){
				if(m->GetColoumn() > GetColoumn()){
					SetColoumn(GetColoumn()+1);
				}
				else if(m->GetColoumn() < GetColoumn()){
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
						SetColoumn(GetColoumn()+1);
						break;
					}
					else if(m->GetColoumn() < GetColoumn()){
						SetColoumn(GetColoumn()-1);
						break;
					}
					else{
						if(m->GetRow() > GetRow()){
							SetRow(GetRow()+1);
							break;
						}
						else if(m->GetRow() < GetRow()){
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
	private: bool mana;
public:
	Warlock(int h, int p, int r, int c, int in, Human* pr, Human *n, bool m):Human(h, p, r, c, in, pr, n){mana = m;}
	void action(Monster *m);
};

void Warlock::action(Monster *m){
	int hit=0;
	Monster *tmp = m;
	while(m!=NULL){
		if(m->GetRow() == GetRow() && m->GetColoumn() <= GetColoumn() +1 && m->GetColoumn() >= GetColoumn()-1){
			m->SetHealth(m->GetHealth()-GetPower());
			hit=1;
			mana = false;
			break;
		}
		if(m->GetColoumn() == GetColoumn() && m->GetRow() <= GetRow() +1 && m->GetRow() >= GetRow()-1){
			m->SetHealth(m->GetHealth()-GetPower());
			hit=1;
			mana = false;
			break;
		}
		m=m->Getnext();
	}
	m = tmp;

	m=tmp;
	int move = 0;
	if(hit==0){
		mana = true;
		while(m!=NULL){
			if(m->GetRow() == GetRow()){
				if(m->GetColoumn() > GetColoumn()){
					SetColoumn(GetColoumn()+1);
				}
				else if(m->GetColoumn() < GetColoumn()){
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
						SetColoumn(GetColoumn()+1);
						break;
					}
					else if(m->GetColoumn() < GetColoumn()){
						SetColoumn(GetColoumn()-1);
						break;
					}
					else{
						if(m->GetRow() > GetRow()){
							SetRow(GetRow()+1);
							break;
						}
						else if(m->GetRow() < GetRow()){
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
	vector <int> CheckDied(Human *h);
};

HumanList::HumanList(){
	HeadNode=NULL;
	size=0;
}
HumanList::~HumanList(){}

vector <int> HumanList::CheckDied(Human *h){
	Human *current = HeadNode;
	vector <int> v;

	while(current!=NULL){
		if(current->Health<=0)
			v.push_back(current->Index);
		current=current->next;
	}

	return v;
}

void HumanList::pushback(int index){
	Human *newNode =NULL;
	if(index == 0)
		newNode = new Peasant(5,5,index, 0, index+1, NULL, NULL);
	else if(index == 1 || index == 2)
		newNode = new Sword(10, 10, index, 0, index+1, NULL, NULL);
	else if(index == 3)
		newNode = new Archer(7, 10, index, 0, index+1, NULL, NULL);
	else if(index == 4)
		newNode = new Warlock(3, 10, index, 0, index+1, NULL, NULL, true);
	

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
		cout<<current->Index<<endl;
		current=current->next;
	}
}

void HumanList::DeleteList(Human *hu){

	Human *h = HeadNode;
	if(size == 1){
		HeadNode = NULL;
		size--;
		delete h;
	}
	else{
		while(h!=NULL){
			if(h->Health<=0){
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
				h->SetHealth(h->GetHealth()-Power);
				hit=1;
				break;
			}
		}
		h = h->Getnext();
	}

	h = tmp;
	if(hit==0){
		while(h!=NULL){
			if(h->GetRow() <= Row+1 && h->GetRow() >= Row-1 && h->GetColoumn() <= Coloumn +1 && h->GetColoumn() >= Coloumn-1){
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
					Coloumn++;
				}
				else if(h->GetColoumn() < Coloumn){
					Coloumn--;
				}

				move = 1;
				break;
			}
			else 
				h = h->Getnext();
		}

		h=tmp;

		pair <int, int> p;
		vector <pair <int, int> > v;


		if(move == 0){
			int r=0, c=0;
			
			while(h!=NULL){
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
						Coloumn++;
						break;
					}
					else if(h->GetColoumn() < Coloumn){
						Coloumn--;
						break;
					}
					else{
						if(h->GetRow() > Row){
							Row++;
							break;
						}
						else if(h->GetRow() < Row){
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
	vector <string> CheckDied(Monster *m);

};

MonsterList::MonsterList(){
	HeadNode=NULL;
	size=0;
}
MonsterList::~MonsterList(){}

vector <string> MonsterList::CheckDied(Monster *m){
	Monster *current = HeadNode;
	vector <string> v;
	
	while(current!=NULL){
		if(current->Health<=0)
			v.push_back(current->Index);
		current=current->next;
	}

	return v;
}

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
		cout<<current->Index<< endl;
		current=current->next;
	}
}

void MonsterList::DeleteList(Monster *mo){
	Monster *m = HeadNode;

	if(size == 1){
		HeadNode =NULL;
		size--;
		delete m;
	}
	else{
		while(m!=NULL){
			if(m->Health <=0){
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