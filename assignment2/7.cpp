#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <functional>

using namespace std;

namespace
{
   struct case_insensitive_less : public std::binary_function< char,char,bool >
    {
        bool operator () (char x, char y) const
        {
            return toupper( static_cast< unsigned char >(x)) < 
                   toupper( static_cast< unsigned char >(y));
        }
    };

    bool NoCaseLess(const string &a, const string &b)
    {
        return std::lexicographical_compare( a.begin(),a.end(),
                b.begin(),b.end(), case_insensitive_less() );
    }

}

int main(){

	ifstream in("words.txt");
	vector <int> space;
	int filesize=0;

	in.seekg(0,ios::end);
	filesize=in.tellg();
	in.seekg(0,ios::beg);
	char *s = new char[filesize];

	in.read(&s[0],filesize);

	int spcnt=0;
	int enter=0;

	for(int i=0; i<filesize; i++){
		if(s[i]>32&&s[i]<127)
			continue;
		else{
			if(s[i]==13)
				enter++;
			spcnt++;
			space.push_back(i);
		}
	}

	spcnt=space.size()-enter;

	char **store = new char*[spcnt];

	for(int i=0; i<spcnt+1; i++){
		store[i]= new char;
	}

	int col=0;
	int row=0;
	for(int i=0; i<filesize; i++){
		if(s[i]>32&&s[i]<127){
			store[col][row++]=s[i];
		}
		else if(s[i]==32||s[i]==10){
			col++;
			row=0;
		}
	}

	vector <char*> v;

	for(int i=0; i<col+1;i++){
		v.push_back(store[i]);
	}

	sort(v.begin(),v.end(),NoCaseLess);
	ofstream outFile("words.txt");
	for(int i=0; i<v.size(); i++){
		outFile<<v[i]<<endl;
	}

}