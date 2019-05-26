#ifndef JOB_CPP
#define JOB_CPP

#include "human.hpp"

class Peasant:public Human{
	/*int Health;
	int Power;
	int Row, Coloumn;
	int Index;*/
public:
	Peasant(int h, int p, int r, int c, int in, Human *pr, Human *n):Human(h, p, r, c, in, pr, n){}
	/*	SetHealth(h);
		SetPower(p);
		SetRow(r);
		SetColoumn(c);
		SetIndex(in);
		Setprev();
		Setnext();
	}*/
};

class Sword: Human{
public:
	Sword(int index):Human(10, 10, index, 0, index+1, NULL, NULL){}
};

class Archer: Human{
public:
	Archer(int index):Human(7, 10, index, 0, index+1, NULL, NULL){}
};

class Warlock: Human{
public:
	Warlock(int index):Human(3, 10, index, 0, index+1, NULL, NULL){}
};

#endif