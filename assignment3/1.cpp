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
		vector<int> hd;
		vector<string> md;
		Human *h = hl.GetHead();
		Monster *m = ml.GetHead();


		cout<<"######## Results of Round "<<i<<" ########"<<endl;
		i++;
		int hcnt=0;
		int mcnt=0;
		int hsize=hl.GetSize();
		int msize=ml.GetSize();
		int i=0;

		if(hl.GetHead()!=NULL){
			while(1){
				if(i == hsize)
					break;
				h->action(ml.GetHead());
				h = h ->Getnext();
				i++;
			}
		}

		i=0;
		if(ml.GetHead()!=NULL){
			while(1){
				if(i == msize)
					break;

				m->action(hl.GetHead());
				m = m->Getnext();
				i++;
			}
		}

		for(int j=0; j<hl.CheckDied(hl.GetHead()).size();j++){
			hd.push_back(hl.CheckDied(hl.GetHead())[j]);
		}

		for(int j=0; j<ml.CheckDied(ml.GetHead()).size();j++){
			md.push_back(ml.CheckDied(ml.GetHead())[j]);
		}		

		hl.DeleteList(h);
		ml.DeleteList(m);
		
			
		if(hl.GetHead()==NULL && ml.GetHead() != NULL){
			
			cout<<"<Human>"<<endl;
			cout<<"<Monster>"<<endl;
			ml.Print();

			for(int j=0; j<hd.size() ;j++){
				cout<<"Human "<<hd[j]<<" has died"<<endl;
			}
			for(int j=0; j<md.size() ;j++){
				cout<<"Monster "<<md[j]<<" has died"<<endl;
			}

			cout<<endl<<"######## Final result of battle #######"<<endl;
			cout<<"Human has been defeated"<<endl;
			break;
		}
		else if(hl.GetHead() != NULL && ml.GetHead() == NULL){
			cout<<"<Human>"<<endl;
			hl.Print();
			cout<<"<Monster>"<<endl;

			for(int j=0; j<hd.size() ;j++){
				cout<<"Human "<<hd[j]<<" has died"<<endl;
			}
			for(int j=0; j<md.size() ;j++){
				cout<<"Monster "<<md[j]<<" has died"<<endl;
			}

			cout<<endl<<"######## Final result of battle #######"<<endl;
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

			for(int j=0; j<hd.size() ;j++){
				cout<<"Human "<<hd[j]<<" has died"<<endl;
			}
			for(int j=0; j<md.size() ;j++){
				cout<<"Monster "<<md[j]<<" has died"<<endl;
			}
			cout<<endl;
		}


	}
	
}