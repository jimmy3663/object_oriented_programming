#include <iostream>
#include <time.h>

using namespace std;

int main(){
	srand(time (NULL));
	int col;
	int row;

	cout<<"Enter the coloum : ";
	cin>>col;
	cout<<"Enter the row : ";
	cin>>row;

	int **arr =new int *[col];

	for(int i=0; i<col ; i++){
		arr[i] =new int [row];
	}

	for(int i=0; i<col ; i++){
		for(int j=0; j<row; j++){
			int num = rand() % 65;
			arr[i][j]=num;
		}
	}

	cout<<"<Orignal>"<<endl;

	for(int i=0; i<col ; i++){
		for(int j=0; j<row; j++)
			cout<<arr[i][j]<<" ";
		cout<<endl;
	}
	cout<<endl;

	int **nu = new int *[row];
	for(int i=0; i<row; i++){
		nu[i] = new int [col];
	}

	for(int i=0; i<row ; i++){
		for(int j=0; j<col ; j++){
			nu[i][j] = arr[j][i];
		}
	}

	cout<<"<Transposed>"<<endl;

	for(int i=0; i<row; i++){
		for(int j=0; j<col ; j++)
			cout<<nu[i][j]<<" ";
		cout<<endl;
	}
}