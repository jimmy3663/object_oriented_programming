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
 	
// 	transform(str.begin(), str.end(), str.begin(), tolower);
 	for(int i=0; i<str.size(); i++){
 		for(int j=i; j<str.size(); j++){
 			if(str[i]>str[j]){
 				swap(str[i], str[j]);

 			}
 		}
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

 	c=0;

 	/*string *arr = new string [str.size()];

 	for(int i=0; i<str.size(); i++){
 		for(int j=i; j<str.size(); j++){
 			if(str[i] == arr[j])
 				continue; 
 			else 
 				arr[i] = str[i];
 		}
 	}*/

 	while(str[c] !='\0'){
 		y = str[c] - 'a';

 		if(str[c]==' '){
 			c++;
 			continue;
 		}

 		if(count[y]>0){
 			f= count[y]/total;
 			char t = toupper(str[c]);
 			char q = tolower(str[c]);
 			cout<<t<<"("<<q<<")"<<" "<<f<<endl;
 		}

 		c++;
 		a++;
 	}  


}
