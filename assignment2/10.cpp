#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

int main(int argc, char* argv[]){
	
	ifstream in1(argv[1]);
	ifstream in2(argv[2]);

	vector <string> v1;
	vector <string> v2;
	string temp1;
	while(!in1.eof()){
		getline(in1, temp1);
		v1.push_back(temp1);
	}
	string temp2;
	while(!in2.eof()){
		
		getline(in2,temp2);
		v2.push_back(temp2);
	}

	/*for(int i=0; i<v1.size(); i++)
		cout<<v1[i]<<endl;
	for(int i=0; i<v2.size() ; i++)
		cout<<v2[i]<<endl;*/

	int dif=0;
	if(v1.size() != v2.size())
		cout<<"The two files are different."<<endl;
	else{
		for(int i=0; i<v1.size(); i++){
			for(int j=0; j<v1[i].length(); j++){
				if(v1[i][j]!=v2[i][j]){
					dif=1;
				}
			}
		}
	}

	if(dif==0)
		cout<<"The two files are same."<<endl;
	else 
		cout<<"The two files are different."<<endl;
}