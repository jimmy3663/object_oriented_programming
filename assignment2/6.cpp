#include <iostream>
#include <vector>

using namespace std;

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
	
	cout<<"Input: ";
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

	for(int i=0; i<spcnt+1; i++){
		if(i==space.size()+1)
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
	cout<<"Ouput: "<<cnt4<<endl;
}