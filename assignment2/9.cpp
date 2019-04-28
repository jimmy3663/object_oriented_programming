#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

int main(){
	ifstream in("numbers.txt");

	vector <int> v;
	string s;
	while(!in.eof()){
		getline(in,s);
		int tmp = stoi(s);
		v.push_back(tmp);
	}

	int l=0;
	while(1){
		int sum = v[l]+v[l+2];
		l=l+2; 
		v.push_back(sum);

		if(l+3>v.size())
			break;
		
	}

	ofstream outFile("result9.txt");
	for(int i=0; i<v.size(); i++){
		outFile<<v[i]<<endl;
	}
}