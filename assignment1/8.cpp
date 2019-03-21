#include <iostream>
#include <string>

using namespace std;

string WARNINGS[] = {
"Must contain at least 6 more characters.",
"Must contain at least 1 digit.",
"Must contain at least 1 lowercase English character.",
"Must contain at least 1 uppercase English character.",
"Must contain at least 1 special character."};


void pwcal(string password){
	int cnt1=0;
	int cnt2=0;
	int cnt3=0;
	int cnt4=0;
	int cnt5=0;

	for(int i=0; i<password.size(); i++){
		if(password[i]>'a' && password[i]<'z')
			cnt1++;
		else if(password[i]>'A' && password[i]<'Z')
			cnt2++;
		else if(password[i]>'0' && password[i]<'9')
			cnt3++;
		else 
			cnt4++;
	}
	if(password.size()<6){
		cout<<WARNINGS[0]<<endl;
		cnt5++;
	}
	if(cnt1<1){
		cout<<WARNINGS[2]<<endl;
		cnt5++;
	}
	if(cnt2<1){
		cout<<WARNINGS[3]<<endl;
		cnt5++;
	}
	if(cnt3<1){
		cout<<WARNINGS[1]<<endl;
		cnt5++;
	}
	if(cnt4<1){
		cout<<WARNINGS[4]<<endl;
		cnt5++;
	}

	if(cnt5<1)
		cout<<"Thank you for signing up!"<<endl;

}

int main()
{
	string password;
	cin >> password;
	
	pwcal(password);


    return 0;
}
