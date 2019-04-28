#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <utility>
#include <string>

using namespace std;

int main(){
	string date;
	string time;
	string dest;
	int year=0, month=0, day=0;


	
	cout<<"Regular format "<<endl;
	cout<<"Destination name: [Minute]"<<endl;
	cout<<"--------------------------------------"<<endl;

	ifstream in("flight_time.txt");
	string s; 
	vector <string> v;
	while(!in.eof()){
		getline(in,s);
		//cout<<s;
		v.push_back(s);
	}

	
	cout<<"flight_time.txt"<<endl;
	for(int i=0; i<v.size(); i++){
		cout<<v[i]<<endl;
	}
	cout<<"---------------------------------------"<<endl;

	cout<< "- Input form users"<<endl;
	cout<<"Departure data : ";
	cin>>date;
	cout<<"Departure time : ";
	cin>>time ;
	cout<<"Destination : ";
	cin>>dest;
	cout<<"----------------------------------------"<<endl;

	cout<<"- Result screen"<<endl;
	cout<<"Departure date : "<<date<<endl;
	cout<<"Departure time : "<<time<<endl;
	cout<<"Destination : "<<dest<<endl<<endl<<endl<<endl;;


	string y;
	for(int i=0; i<4; i++){
		y[i]=date[i];
	}
	string m;
	for(int i=5; i<7;i++){
		m[i-5]=date[i];
	}
	string d;
	for(int i=8; i<10; i++){
		d[i-8]=date[i];
	}
	
	year=atoi(y.c_str());
	month = atoi(m.c_str());
	day = atoi(d.c_str());

	string h;
	for(int i=0; i<2;i++){
		h[i]=time[i];
	}
	string min;
	for(int i=3; i<5;i++){
		min[i-3]=time[i];
	}

	int hour = atoi(h.c_str());
	int minute = atoi(min.c_str());

	for(int i=0 ; i<v.size();i++){
		string tmp;
		for(int j=0; j<v[i].length()-7;j++){
			tmp[j]=v[i][j];
		}
		cout<<tmp<<endl;
	
		int cnt=0;
		if(tmp==dest)
			cout<<tmp<<endl;
		
	
	}



}