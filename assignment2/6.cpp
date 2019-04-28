#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
	string input;
	vector <string> v;
	vector <int> space;
	vector <int> same;
	cout<<"input : ";
	getline(cin,input);
	
	space.push_back(0);

	for(int i=0; i<input.size();i++){
		input[i]= toupper(input[i]);
	}
	//string result = input.substr(4);

	for(int i=0; i<input.size(); i++){
		if(input[i]==' '){
			space.push_back(i+1);
		}
	}
	space.push_back(input.size());

	int word=0;
	for(int i =0; i<space.size(); i++){
		v.push_back(input.substr(space[i],space[i+1]-space[i]));
		
	}
	v.pop_back();
	for(int i=0; i<v.size(); i++){
		int cnt2=0;
		for(int j=i+1; j<v.size(); j++){
			int cnt1=0;
			for(int k=0; k<v[i].length(); k++){
				if(v[i].length()==v[j].length()){
					if(v[i][k]==v[j][k])
						cnt1++;	
					if(cnt1 == v[i].length())
						cnt2++; // 같은 수 
				}
			}

		}
		if(cnt2>0)
			same.push_back(cnt2);
	}
		
	int total=0;
	for( int i=0; i<same.size(); i++){
		total +=same[i];
	}
	cout<<"Output: "<<v.size()-total<<endl;

}