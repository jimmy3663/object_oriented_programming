#include <iostream>
#include <map>

using namespace std;

int main(){
	int h,m;

	map <int, string> time;

	time[1] = "one";
    time[2] = "two";
    time[3] = "three";
    time[4] = "four";
    time[5] = "five";
    time[6] = "six";
    time[7] = "seven";
    time[8] = "eight";
    time[9] = "nine";
    time[10] = "ten";
    time[11] = "eleven";
    time[12] = "twelve";
    time[13] = "thirteen";
    time[14] = "fourteen";
    time[15] = "quarter";
    time[16] = "sixteen";
    time[17] = "seventeen";
    time[18] = "eighteen";
    time[19] = "nineteen";
    time[20] = "twenty";
    time[21] = time[20] + " "+ time[1];
    time[22] = time[20] + " "+ time[2];
    time[23] = time[20] + " "+ time[3];
    time[24] = time[20] + " "+ time[4];
    time[25] = time[20] + " "+ time[5];
    time[26] = time[20] + " "+ time[6];
    time[27] = time[20] + " "+ time[7];
    time[28] = time[20] + " "+ time[8];
    time[29] = time[20] + " "+ time[9];
    time[30] = "half";

	cin>>h;
	cin>>m;

	if(m==0)
		cout<<time[h]<<" o' clock"<<endl;
	else if(m<30){
		if(m==15)
			cout<<time[15]<<" past "<<time[h]<<endl;
		else 
			cout<<time[m]<<" mintues past"<<time[h]<<endl;
	}
	else if(m>30){
		if(m==45)
			cout<<time[60-m]<<" left "<<time[h]<<endl;
		else 
			cout<<time[60-m]<<" mintues to "<<time[h]<<endl;
	}
	else 
		cout<<time[h]<< " and "<<time[m]<<endl;


}