#include <iostream>
#include <string>

using namespace std;

int CMPandCAT(char *src1, char *src2, char *copy_result){
	int result;
	if(src1 > src2)
		result=1;
	else if(src1 < src2)
		result=-1;
	else 
		result=0;

	int cnt1=0, cnt2=0;
	int k=0;
	
	while(src1[k]!=0){
		cnt1++;
		k++;
	}
	k=0;
	while(src2[k]!=0){
		cnt2++;
		k++;
	}

	if(result == 1){
		for(int i=0; i<cnt1+cnt2; i++){
			if(i<cnt1)
				copy_result[i]=src1[i];
			else if(i>=cnt1)
				copy_result[i]=src2[i-cnt1];
		}
	}

	else if(result == -1){
		for(int i=0; i<cnt1+cnt2; i++){
			if(i<cnt2)
				copy_result[i]=src2[i];
			else if(i>=cnt2)
				copy_result[i]=src1[i-cnt2];
		}
	}
	else{
		for(int i=0; i<cnt1+cnt2; i++){
			if(i<cnt1)
				copy_result[i]=src1[i];
			else if(i>=cnt1)
				copy_result[i]=src2[i-cnt1];
		}
	} 
		
	//cout<<copy_result<<endl;
	return result;
}
int main(){
	//char a[1000];
	//char b[1000];
	char *a = new char;
	char *b = new char;
	char *copy_result= new char;

	cout<<"Input string "<<endl<<endl;
	cout<<"src1 : ";
	cin>>a;
	cout<<"Src2 : ";
	cin>>b;
	cout<<"------------------------------"<<endl;
	cout<<"Output string "<<endl<<endl;
	cout<<"Return Value : "<<CMPandCAT(a,b,copy_result)<<endl;
	cout<<"Copy result : "<<copy_result<<endl;

}