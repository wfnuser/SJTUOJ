#include<iostream>
#include<cstdio>

using namespace std;

struct Node{
	int num;
	Node *next;	
}*linklist;

int main(){
	int tmp;
	Node *head;
	Node *tail;
	Node *pos;
	head = tail = pos = new Node;
	for(int i=0;i<=5;i++)
	{
		cin>>tmp;
		tail->next = new Node;
		tail->num = tmp;
		tail = tail->next;
	}			
	while(pos->next != NULL)
	{
		cout<<pos->num<<" ";
		pos = pos->next;
	}
}
