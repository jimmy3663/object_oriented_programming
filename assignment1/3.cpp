#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main(){
	string f;
	vector <vector <string> > v;
	int a=0;
	string id;
	string c;
	string b;

	for(int i=0; i<6; i++){
		vector <string> value (2);
		v.push_back(value);
	}

	while(1){
		cout<<"#Enter Function :";
		cin>>f;

		if(f=="End"){
			cout<<"END"<<endl;
			break;
		}

		else if(f=="Append"){
			cin>>b;
			cin>>c;

			v[a][0]=b;
			v[a][1]=c;
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

		else if(f=="Search"){
			cout<<"id? "<<endl;
			cin>>id;
			for(int i=0 ; i<a+1; i++){
				if(v[i][0]==id){
					cout<<v[i][0]<<endl;
					cout<<v[i][1]<<endl;
				}
			}
		}

		else if(f=="Sort"){
			//cout<<v[0][0]<<endl;
			//cout<<v[1][0]<<endl;
			for(int i=0; i<a; i++){
				for(int j=i; j<a;j++){
					if(v[i][0]>v[j][0]){
						swap(v[i][0],v[j][0]);
						swap(v[i][1],v[j][1]);
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

		else if(f=="Delete"){
			//cout<<"ID? ";
			cin>>id;
			for(int i=0; i<a; i++){
				if(v[i][0]==id){
					v[i][0]="";
					v[i][1]="";
				}
			}	
			for(int i=0; i<a; i++)
				cout<<v[i][0]<<" ";
			cout<<endl;
			for(int i=0; i<a; i++)
				cout<<v[i][1]<<" ";
			cout<<endl;

		}

	}


}