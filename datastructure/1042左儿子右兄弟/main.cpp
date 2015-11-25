#include<iostream>
#include<cstdlib>

using namespace std;

int que[1000000];
int temp[20000][3];

void preorder(int root){
	cout<<root<<" ";
	int pos = temp[root][0];
	if(pos!=0){
		preorder(pos);
		while(temp[pos][1]!=0){
			preorder(temp[pos][1]);
			pos = temp[pos][1];
		}
	}
	return;
}

void postorder(int root){
	//cout<<root<<" ";
	int pos = temp[root][0];
	if(pos!=0){
		postorder(pos);
		while(temp[pos][1]!=0){
			postorder(temp[pos][1]);
			pos = temp[pos][1];
		}
	}
	cout<<root<<" ";
	return;
}
	
int main(){
	int n;
	cin>>n;
	int x,cx,sx;
	int head;
	int tail;
	for(int i=0;i<=n-1;i++){
		cin>>x>>cx>>sx;
		temp[x][0] = cx;
		temp[x][1] = sx;
		if(cx!=0)
			temp[cx][2] = x;
		if(sx!=0)
			temp[sx][2] = temp[x][2];
	}
	tail++;
	int root = 1;
	int pos = root;
	while(temp[pos][2]!=0){
		pos = temp[pos][2];
	}
	root = pos;
	que[head] = root;
	int num=0;
	///preorder///
	preorder(root);
	cout<<endl;
	///postorder///
	head = 0;
	que[head] = root;
	tail = head+1;
	postorder(root);
	///bfs///
	cout<<"\n";
	head = 0;
	que[head] = root;
	tail = head+1;
	while(head<tail){
		cout<<que[head]<<" ";
		pos = temp[que[head]][0];
		//cout<<pos<<endl;
		//cin>>num;
		if(pos==0){head++;continue;}
		else{que[tail++] = pos;}
		while(temp[pos][1]!=0){
			que[tail++] = temp[pos][1];
			pos = temp[pos][1];
		}	
		head++;
	}	
	cout<<endl;
}
