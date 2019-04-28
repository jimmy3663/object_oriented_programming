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
	vector <string> v;
	vector <string> store;
	vector <string> result;
	string s;
	while(!in.eof()){
		getline(in,s);
		v.push_back(s);
	}


	for(int i=0; i<v.size(); i++){
		vector <int> space;
		space.push_back(0);
		for(int j=0; j<v[i].length();j++){

			if(v[i][j]==' ')
				space.push_back(j+1);
		}

		space.push_back(v[i].length());

		for(int k=0; k<space.size(); k++){
			if(k==space.size()-1)
				break;
			store.push_back(v[i].substr(space[k],space[k+1]-space[k]));
		}
	}

	sort(store.begin(),store.end(),NoCaseLess);

	ofstream outFile("result7.txt");
	for(int i=0; i<store.size(); i++){
		outFile<<store[i]<<endl;
	}
}