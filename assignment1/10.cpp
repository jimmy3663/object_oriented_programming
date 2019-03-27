#include <iostream>

using namespace std;

int main(){
	
	int n;
	cout<<"Enter the size of Magic square: ";
	cin>>n;
	int arr[n][n];
	
	memset(arr,0,sizeof(arr));

	int i=0;
	int j = n/2;

	for(int num=1; num<n*n;num++){
		arr[i][j]=num;

		if(num%n==0){
			i++;
		}
		else{
			i--;
			j++;
			
			if(i<0)
				i=n-1;
			if(j>n-1)
				j=0;
		}
	}

	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}

}