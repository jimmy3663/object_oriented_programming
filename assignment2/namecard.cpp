#include <iostream>
#include "4.hpp"
#include <string>

using namespace std;

Namecard::Namecard(){
	//m_Name={,};
	//m_Phonenumber={,};
	//m_Address={,};
	m_Age=0;
}

Namecard::~Namecard(){
		//m_Name=0;
		//m_Phonenumber=0;
		//m_Address=0;
		//m_Age=0;
}

void Namecard::SetName(char *name){
	strcpy(m_Name, name);
}
void Namecard::SetPhonenumber(char *phonenumber){
	strcpy(m_Phonenumber, phonenumber);
}
void Namecard::SetAddress(char *address){
	strcpy(m_Address,address);
}
void Namecard::SetAge(int age){
	m_Age = age;
}
char *Namecard::GetName(){return m_Name;}
char *Namecard::GetPhonenumber(){return m_Phonenumber;}
char *Namecard::GetAddress(){return m_Address;}
int Namecard::GetAge(){return m_Age;}
