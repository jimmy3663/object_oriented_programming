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

	
	int i=1;
	while(1){
		//cout<<"i: "<<i<<endl;
		cout<<"============= Round "<<i<<" ============="<<endl;
		i++;
		Human *h = hl.GetHead();
		Monster *m = ml.GetHead();
		int hcnt=0;
		int mcnt=0;
		int hsize=hl.GetSize();
		int msize=ml.GetSize();
		cout<<"hsize: "<<hsize<<endl;
		cout<<"msize: "<<msize<<endl;
		while(1){
			if(hcnt == hsize && mcnt == msize)
				break;
			cout<<"monster Index: "<<m->GetIndex()<<endl;
			if(hcnt < hsize){
				cout<<"why?"<<endl;
				h->action(ml.GetHead());
			}

			if(mcnt < msize){
				cout<<"Here"<<endl;
				m->action(hl.GetHead());

			}


			hl.DeleteList(h);
			ml.DeleteList(m);

			
			//else if(m->Getprev()->Getnext() ==NULL)
			//	break;

			/*if(h->Getnext() == NULL && m->Getnext() == NULL){
				cout<<i<<" round done"<<endl;
				break;
			}
			else{
				if(h->Getnext() == NULL && m->Getnext() !=NULL){
					m = m->Getnext();
				}
				else if(h->Getnext() != NULL && m->Getnext() == NULL){
					h = h->Getnext();
				}
				else {
					m = m->Getnext();
					h = h->Getnext();
				}
			}*/
			if(hcnt < hsize){
				h= h->Getnext();
				hcnt++;
			}
			if(mcnt<msize){
				m = m->Getnext();
				mcnt++;
			}
			cout<<"hcnt: "<<hcnt<<endl;
			cout<<"mcnt: "<<mcnt<<endl;

		}
		if(hl.GetHead()==NULL && ml.GetHead() != NULL){
			cout<<"<Human>"<<endl;
			cout<<"<Monster>"<<endl;
			ml.Print();
			cout<<"Human has been defeated"<<endl;
			break;
		}
		else if(hl.GetHead() != NULL && ml.GetHead() == NULL){
			cout<<"<Human>"<<endl;
			hl.Print();
			cout<<"<Monster>"<<endl;
			cout<<"Monster has been defeated"<<endl;
			break;
		}
		else if(hl.GetHead() == NULL && ml.GetHead() ==NULL){
			cout<<"<Human>"<<endl;
			cout<<"<Monster>"<<endl;
		}
		else{
			cout<<"<Human>"<<endl;
			hl.Print();
			cout<<"<Monster>"<<endl;
			ml.Print();
		}

	}
	
}