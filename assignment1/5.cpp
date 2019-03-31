#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

int main(){
	string str;
	float per;
	
	//string space=" ";

	cout<<"input: ";
	getline(cin,str);

   	double c = 0, count[26] = {0};
   	int x, y, total=0, a=0;
   	double f;
   	char w;

 	for(int i=0; i<str.size(); i++){
 		char tmp= tolower(str[i]);
 		str[i] = tmp;
 	}

   	while (str[c] != '\0') {
 
    	  if (str[c] >= 'a' && str[c] <= 'z') {
        	 x = str[c] - 'a';
         	count[x]++;
      	}
	    c++;
   	}

   		
 
 	for(int i=0; i<26; i++){
 		total = total + count[i];
 	}


 	for(int i=0; i<26; i++){
 		if(count[i]>0){
 			f = count[i]/total;
 			w = i+'a';
 			char t = toupper(w);
 			char q = tolower(w);

 			cout<<fixed;
 			cout.precision(6);
 			cout<<t<<"("<<q<<")"<<" "<<f<<endl;
 		}
 	}


}
