#include <iostream>
#include <string>
#include <stack>
#include <vector>

using namespace std;

struct op{
	int pri;
	string oper;
};

stack <int> num;
stack <op> o;

void cal(){
	int a,b,result;
	string s;

	b= num.top();
	num.pop();
	a=num.top();
	num.pop();

	s=o.top().oper;

	if(s=="+")
		result = a+b;
	else if(s=="-")
		result = a-b;
	else if(s=="*")
		result = a*b;
	else if(s=="/")
		result = a/b;

	num.push(result);

}

int main(){
	string input;
	cout<<"Input : ";
	cin>>input;
	vector <int> notnum;
	vector <int>  num;
	notnum.push_back(0);
	for(int i=0; i<input.size();i++){
		if(input[i]=='+'||input[i]=='-'||input[i]=='*'||input[i]=='/'||input[i]=='('||input[i]==')')
			notnum.push_back(i);
	}
	notnum.push_back(input.size());
	

	for(int i=0; i<notnum.size()-1;i++){
		string tmp;
		for(int j=notnum[i];j<notnum[i+1];j++){
			tmp+=input[j];
		}
		notnum[i+1]++;
		num.push_back(stoi(tmp));
	}
	
	for(int i=0; i<num.size() ;i++)
		cout<<num[i]<<endl;

}