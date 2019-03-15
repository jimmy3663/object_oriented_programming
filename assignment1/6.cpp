#include <iostream>
#include <math.h>

using namespace std;

int main(){
	int num;
	cin>>num;
	
	int **arr=new int*[num];
	int *ans=new int[num];

	for(int i=0; i<num; i++){
		arr[i] = new int [6];
	}

	for(int i=0; i<num; i++){
		for(int j=0; j<6; j++){
			cin>>arr[i][j];
		}
	}

	for(int i=0; i<num; i++){
			int a;
			a=pow(arr[i][0]-arr[i][3],2);
			int b;
			b=pow(arr[i][1]-arr[i][4],2);
			double c;
			c= sqrt(a+b);
			
			if(c==arr[i][2]+arr[i][5])
				cout<<"1"<<endl;
			else if(c>arr[i][2]+arr[i][5])
				cout<<"0"<<endl;
			else 
				cout<<"2"<<endl;
	}


}