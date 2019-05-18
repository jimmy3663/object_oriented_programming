#include "3.hpp"
#include <iostream>
#include <string>
#include <time.h>
#include <vector>

using namespace std; 

int main(){
	NeList list;
	vector <int> v;
	srand(1);

	for(int i=0; i<9; i++){
		list.Insert(i);
	}
	
	list.Conbreak();
	list.Cal();
}