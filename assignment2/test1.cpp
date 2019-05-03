#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

int main(){
	vector <string> input;	// given input
	string a = "1 Kim 89";
	string b = "2 Moon 100";
	string c = "3 Chan 78";

	input.push_back(a);
	input.push_back(b);
	input.push_back(c);

	for(int i = 0; i < input.size(); i++)
	{
		int num, score;
		string name;

		stringstream ss;	ss.str(input[i]);

		ss >> num;
		ss >> name;
		ss >> score;

		cout << num <<endl;//<< " " << name << " " << score << endl;
		// 이후 필요한 자료 구조에 저장하여 활용한다.
	}
}


