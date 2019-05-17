#include <iostream>
#include "human.hpp"
//#include "job.hpp"
//#include "monster.hpp"
#include <string>

using namespace std;

int main(){
	HumanList hl;
	MonsterList ml;
	
	for(int i=0; i<5; i++){
		hl.pushback(i);
		if(i==0)
			ml.pushback("A",i);
		else if(i == 1)
			ml.pushback("B",i);
		else if(i ==2)
			ml.pushback("C",i );
		else if(i==3)
			ml.pushback("D", i );
		else if(i==4)
			ml.pushback("E", i );

	}

	Human *h = hl.GetHead();
	Monster *m = ml.GetHead();
	int i=0;
	while(1){
		h->action(m);
		m->action(h);

		if(h->GetHealth()<=0)
			hl.DeleteList(h);
		if(m->GetHealth()<=0)
			ml.DeleteList(m);

		h=h->Getnext();
		m=m->Getnext();
		i++;
		if(hl.GetHead() == NULL || ml.GetHead() == NULL)
			break;
		hl.Print();
		ml.Print();
	}

	
}