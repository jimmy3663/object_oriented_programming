#include <iostream>
#include <math.h>

using namespace std;

int main(){
	int num;
	cin>>num;
	
	int **arr=new int*[num]; // double array 

	for(int i=0; i<num; i++){
		arr[i] = new int [6]; // making array 
	}

	for(int i=0; i<num; i++){
		for(int j=0; j<6; j++){
			cin>>arr[i][j]; // putting value to array 
		}
	}

	for(int i=0; i<num; i++){
			int a; 
			a=pow(arr[i][0]-arr[i][3],2); // pow is square root 
			int b;
			b=pow(arr[i][1]-arr[i][4],2);
			double c;
			c= sqrt(a+b); // sqrt is square 
			
			if(c==arr[i][2]+arr[i][5]) // if c is equal to arr[i][2]+arr[i][5] 
				cout<<"1"<<endl;
			else if(c>arr[i][2]+arr[i][5])// if c is bigger than arr[i][2]+arr[i][5] 
				cout<<"0"<<endl;
			else if(arr[i][0]==arr[i][3] && arr[i][1] == arr[i][4] && arr[i][2]==arr[i][5])
				// if all element is same 
				cout<<"-1"<<endl;
			else // if c is smaaller than arr[i][2]+arr[i][5] 
				cout<<"2"<<endl;
	}


}