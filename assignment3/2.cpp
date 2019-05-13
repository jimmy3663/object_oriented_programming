#include "2.hpp"
#include <fstream>
#include <iostream>
#include <vector>
#include <string>

using namespace std;


int main(){
	
	vector <string> v;
	ifstream in("Sentences.txt");
	int fs;
	in.seekg(0, ios::end);
	fs = in.tellg();
	in.seekg(0, ios::beg);

	char *s =new char[fs+1];

	for(int i=0; i<fs+1; i++){
		s[i] = '\0';
	}

	in.read(&s[0], fs+1);

	char *result = strtok(s,". ");
	
	while(result!=NULL){
		string w(result);
		result= strtok(NULL, ". ");
		v.push_back(w);
	}
	
	CacheManager cm;

	int min;
	for(int i=0; i<v.size(); i++){
		if(cm.GetCNT()<5){
			cm.Push(v[i], cm.GetTS());
			min = cm.Minimum();
		}
		else{
			cm.Insert(v[i],cm.GetTS(),min);
			min = cm.Minimum();
		}
		
		cm.Print(v[i], cm.GetTS());
	}

	

}