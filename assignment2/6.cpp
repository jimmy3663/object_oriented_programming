#include <iostream>
#include <vector>

using namespace std;

/*int main(){
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

}*/
int comp(char* a, char *b) {
  if(a && b) { // check for non null pointers
    while(*a != '\0' && *b != '\0' && *a == *b) { a++; b++; }
    if(*a == '\0' && *b == '\0') { return 0; }
  }  
  return -1;
}

int main(){
	char *input = new char;
	int cnt=0;
	int cnt2=0;
	int spcnt=0;
	vector <int> space;
	while(1){
		char ch;
		ch = cin.get();

		if(ch=='\n'){
			break;
		}

		input[cnt]=toupper(ch);
		cnt++;
	}
	space.push_back(0);
	for(int i=0; i<cnt; i++){
		if(input[i]==' '){
			spcnt++;
			space.push_back(i);
		}
	}
	space.push_back(cnt);
	
	char **store = new char *[spcnt+1];
	for(int i=0; i<spcnt+1; i++){
		store[i]= new char;
	}

	for(int i=0; i<space.size(); i++){
		if(i==space.size()-1)
			break;
		for(int j=space[i]; j<space[i+1]; j++){	
			store[i][j-space[i]]=input[j];
		}
		space[i+1]++;
	}
	

	int cnt4=0;
	for(int i=0; i<spcnt+1; i++){
		int cnt3=0;
		for(int j=i+1; j<spcnt+1; j++){
			if(!comp(store[i],store[j])){
				cnt3=1;
			}
		}
		if(cnt3!=1)
			cnt4++;
	}
	cout<<cnt4<<endl;
}