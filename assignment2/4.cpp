#include <iostream>
#include <string>
#include "namecard.cpp"

using namespace std;

int main(){
	Namecard A;

	char name[10] = "stinssu";
	char phonenumber[15] = "01031234938";
	char address[20] ="Seoul";
	int age = 24;
	A.SetName(name);
	A.SetPhonenumber(phonenumber);
	A.SetAddress(address);
	A.SetAge(age);

	cout<<"name : "<<A.GetName()<<endl;
	cout<<"Pheone Number: "<<A.GetPhonenumber()<<endl;
	cout<<"Address: "<<A.GetAddress()<<endl;
	cout<<"Age: "<<A.GetAge()<<endl;

	return 0;
}