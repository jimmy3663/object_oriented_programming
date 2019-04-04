#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main(){
	string f; //function string 
	vector <vector <int> > v; // id and grade list 
	int a=0; 
	int id; 
	int c;// id 
	int b;// score 

	for(int i=0; i<6; i++){
		vector <int> value (2);
		v.push_back(value);
	}

	while(1){
		cout<<"#Enter Function :";
		cin>>f; // function 

		if(f=="End"){ // if f is end then exit 
			cout<<"END"<<endl;
			break;
		}

		else if(f=="Append"){ // if f is Append add id and score 
			cin>>b;
			cin>>c;

			v[a][0]=b; // add id to list
			v[a][1]=c; // add score to list 
			a++;

			for(int i=0; i<a; i++){
				cout<<v[i][0]<<" ";
			}
			cout<<endl;

			for(int i=0; i<a; i++){
				cout<<v[i][1]<<" ";
			}
			cout<<endl;
		}

		else if(f=="Search"){ // if f is Search 
		//	cout<<"id? "<<endl;
			cin>>id; 
			for(int i=0 ; i<a+1; i++){
				if(v[i][0]==id){ 
					cout<<v[i][0]<<endl;
					cout<<v[i][1]<<endl;
				}
			}
		}

		else if(f=="Sort"){ // if f is Sort 
			cin>>f;
			if(f=="ID"){
				for(int i=0; i<a; i++){
					for(int j=i; j<a;j++){
						if(v[i][0]>v[j][0]){
							swap(v[i][0],v[j][0]); // swap v[i][0] and swap v[j][0]
							swap(v[i][1],v[j][1]);
						}
					}
				}
			}

			for(int i=0; i<a; i++)
				cout<<v[i][0]<<" ";
			cout<<endl;

			for(int i=0; i<a; i++)
				cout<<v[i][1]<<" ";
			cout<<endl;
		}

		else if(f=="Delete"){ // if f is Delete 
			cin>>id;
			for(int i=0; i<a; i++){
				if(v[i][0]==id){
					v.erase(v.begin()+i); // erasing list when id is same as input 
				}
			}	


			for(int i=0; i<a; i++){
				if(v[i][0]==0) // when list is earsed, it remain as 0 
					i++; // so if id is 0 then skip printing
				else 
					cout<<v[i][0]<<" ";
			}
			cout<<endl;
			for(int i=0; i<a; i++){ // works same as above 
				if(v[i][1]==0)
					i++;
				else
					cout<<v[i][1]<<" ";
			}
			cout<<endl;

		}

	}


}