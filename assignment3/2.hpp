#ifndef _2_HPP
#define _2_HPP
#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

class CacheNode{
friend class CacheManager;
private:
	string Word;
	int Timestamp;
	CacheNode *NextNode;
	CacheNode(string w, int ts, CacheNode *n) : Word(w), Timestamp(ts), NextNode(n){}
};

class CacheManager{
private:
	CacheNode *HeadNode;
	CacheNode *TailNode;
	int cnt; 
	int time;

public:
	CacheManager();
	int Hit(string w, int);
	void Push(string, int);
	void Insert(string, int, int);
	void Del();
	void Print(string, int);
	int GetTS();
	int GetCNT();
	int Minimum();
	~CacheManager();
};

CacheManager::CacheManager(){
	HeadNode = TailNode = NULL;
	cnt = 1;
	time =1;
}

CacheManager::~CacheManager(){}

int CacheManager::GetTS(){return time;}
int CacheManager::GetCNT(){return cnt;}


void CacheManager::Push(string w, int ts){
	CacheNode *newNode = new CacheNode(w, ts, NULL);
	CacheNode *current= NULL;
	CacheNode *prev = NULL;

	if(HeadNode == NULL){
		cout<<"Miss ";
		HeadNode = newNode;
	}

	else{
		current=HeadNode;
		while(current!=NULL){
			string temp1 = current->Word;
			string temp2 = w;

			for(int i=0; i<temp1.size(); i++){
				temp1[i]=toupper(temp1[i]);
			}
			for(int i=0; i<temp2.size(); i++){
				temp2[i] = toupper(temp2[i]);
			}

			if(temp1==temp2){
				current -> Timestamp = ts;
				cout<<"Hit ";
				break;
			}
			else{
				prev=current;
				current= current->NextNode;
			}
		}
		if(current==NULL){
			cout<<"Miss ";
			prev->NextNode = newNode;
			cnt++;
		}
	} 

	time++;
}

int CacheManager::Minimum(){
	CacheNode *current = HeadNode;
	int min=current->Timestamp;
	if(HeadNode==NULL)
		return 0;

	while(current!=NULL){
		if(current->Timestamp<min){
			min=current->Timestamp;
		}
		current = current->NextNode;
	}
	return min;
}

void CacheManager::Insert(string w, int ts, int min){
	CacheNode *newNode = new CacheNode(w, ts, NULL);
	CacheNode *current = HeadNode;
	CacheNode *prev = NULL;


	//cout<<"min: "<<min<<endl;

	if(HeadNode == NULL){
		HeadNode=newNode;
	}
	else{
		current=HeadNode;
		while(current!=NULL){
			string temp1 = current->Word;
			string temp2 = w;

			for(int i=0; i<temp1.size(); i++){
				temp1[i]=toupper(temp1[i]);
			}
			for(int i=0; i<temp2.size(); i++){
				temp2[i] = toupper(temp2[i]);
			}

			if(temp1==temp2){
				current -> Timestamp = ts;
				cout<<"Hit ";
				break;
			}

			else{
				if(current->Timestamp == min){
					cout<<"Miss ";
					if(current==HeadNode){
						HeadNode = newNode;
						newNode->NextNode = current->NextNode;
					}
					else{
						prev->NextNode=newNode;
						newNode->NextNode = current->NextNode;
					}
					break;
				}
			}
			prev=current;
			current=current->NextNode;
		}
	}
	time++;
}

void CacheManager::Print(string w, int ts){
	CacheNode *current=HeadNode;

	/*if(HeadNode == NULL){
		cout<<"Miss ";
	}

	else {
		CacheNode *current = HeadNode;
		while(current!=NULL){
			string temp1 = current->Word;
			string temp2 = w;

			for(int i=0; i<temp1.size(); i++){
				temp1[i]=toupper(temp1[i]);
			}
			for(int i=0; i<temp2.size(); i++){
				temp2[i] = toupper(temp2[i]);
			}

			if(temp1==temp2){
				cout<<"Hit ";
				break;
			}
			else{
				cout<<"Miss ";
				break;
			}
			current=current->NextNode;
		}
	}*/

	while(current!=NULL){
		cout<<current->Word<<": "<<current->Timestamp<<" ";
		current = current->NextNode;
	}
	cout<<endl;
}

#endif


