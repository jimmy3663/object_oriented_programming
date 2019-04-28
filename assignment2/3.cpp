#include <iostream>
#include <math.h>

using namespace std;

double rectangle(int width, int height){
	double result; 
	result= width*height;

	return result;
}

double triangle(int width, int height){
	double result;
	result = width*height/2.0;

	return result;
}
double diamond(int width, int height){
	double result;
	result = width*height/2.0;

	return result;
}

int main(){
	double (*Figurearea[3])(int,int);
	int width;
	int height;
	
	cout<<"width: ";
	cin>>width;
	cout<<"height: ";
	cin>>height;

	Figurearea[0]=rectangle;
	Figurearea[1]=triangle;
	Figurearea[2]=diamond;

	cout<<"Area of rectangle: "<<Figurearea[0](width,height)<<endl;
	cout.setf(ios::fixed);
	cout.precision(1);
	cout<<"Area of triangle: "<<Figurearea[1](width,height)<<endl;
	cout<<"Area of diamond: "<<Figurearea[2](width, height)<<endl;

}