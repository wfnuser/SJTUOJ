#include<iostream>
#include<cstdlib>

using namespace std;

int heap[100000][2];
int newheap[100000][2];
int index[100000];

void refresh(int n){
	for(int i=0;i<=n-1;i++){
		newheap[i][0] = heap[i][0];
		newheap[i][1] = heap[i][1];
	}
}

void adjust(int max){
	int pos = 0;
	int less;
	int tmp;
	while(pos*2+1<=max){
		less = 10000000;
		if(pos*2+2<=max)
			less = newheap[pos*2+2][0];
		if(less<newheap[pos*2+1][0]||(less==newheap[pos*2+1][0]&&newheap[pos*2+2][1]<newheap[pos*2+1][1])){
			newheap[pos*2+2][0] = newheap[pos][0];
			newheap[pos][0] = less;	
			pos = pos*2+2;
		}
		else{
			less = newheap[pos*2+1][0];
			newheap[pos*2+1][0] = newheap[pos][0];
			newheap[pos][0] = less;
			pos = pos*2+1;
		}		
	}
}

void find(int base,int n){
	int tmp;
	int root;
	root = newheap[0][0];
	int max = n-1;
	while(root<=base){
		newheap[0][0]=newheap[max][0];
		newheap[0][1]=newheap[max][1];
		max--;
		adjust(max);		
		root = newheap[0][0];	
	}
	cout<<root;
}

int main(){
	int n;
	//int heap[100000][2];
	cin>>n;
	int pos;
	int tmp;
	for(int i=0;i<=n-1;i++)
	{
		cin>>heap[i][0];
		heap[i][1] = i;
		pos = i;
		index[pos] = i;
		while(pos>0){
			if(heap[pos][0]<heap[(pos-1)/2][0]){
				tmp = heap[pos][0];
				heap[pos][0] = heap[(pos-1)/2][0];
				heap[(pos-1)/2][0] = tmp;
				index[heap[pos][1]] = (pos-1)/2;
				index[heap[(pos-1)/2][1]] = pos;
				tmp = heap[pos][1];
				heap[pos][1] = heap[(pos-1)/2][1];
				heap[(pos-1)/2][1] = tmp;
				pos = (pos-1)/2;
			}
			else
				break;
		}
	}
	//cout<<heap[0][0]<<heap[0][1];
	int base;	
	string cmd;
	int a,b;
	while(cin>>cmd){
		if(cmd[0] == f){cin>>base;refresh(n);find(base,n);cout<<endl;}
		else{
			cin>>a>>b;
			
			
			
		}
	}

}
