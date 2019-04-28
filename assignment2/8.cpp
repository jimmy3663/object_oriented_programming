#include <iostream>

using namespace std;

class Elevator{
	private :
		int e_floor; 
		int e_up;
		int e_down;
		int e_upcnt;
		int e_downcnt;
		double e_time;

	public :
		Elevator();
		~Elevator();
		void Init();
		void Up(int up);
		void Down(int down);
		void ShowInfo();
		int GetUp();
		int Getfloor();
		int GetDown();
};

Elevator::Elevator(){
}
Elevator::~Elevator(){}
int Elevator::GetUp(){return e_upcnt;}
int Elevator::GetDown(){return e_downcnt;}
int Elevator::Getfloor(){return e_floor;}

void Elevator::Init(){
	e_floor=1;
	e_downcnt=0;
	e_upcnt=0;
}

void Elevator::Up(int up){
	if(up>e_floor){
		e_upcnt+=up-e_floor;
		e_floor=up;
		cout<<"It's on the "<<e_floor<<" floor."<<endl;
	}
	else 
		cout<<"You can't go up to "<<up<<" floor."<<endl;

	cout<<endl;
}

void Elevator::Down(int down){
	if(down<e_floor){
		e_downcnt+=e_floor-down;
		e_floor=down;
		cout<<"It's on the "<<e_floor<<" floor."<<endl;

	}
	else 
		cout<<"You can't go down to "<<down<<" floor."<<endl;

	cout<<endl;
}

void Elevator::ShowInfo(){
	cout<<"Total up: "<<GetUp()<<endl;
	cout<<"Total down: "<<GetDown()<<endl;
	cout<<"Total time: "<<(GetUp()+GetDown())/2.0<<"s"<<endl;
}

int main(){
	Elevator el;

	el.Init();
	el.Up(7);
	el.Down(3);
	el.Down(5);
	el.Down(1);
	el.ShowInfo();

	return 0;

}
