#include<iostream>
#include<cstdlib>
using namespace std;
int n;
int father;
int root;
int tree[3000000][2];
int array[3000000];
void bfs(){
	int head;
	int tail;
	head = tail = 0;
	tail++;
	array[head] = 0;
	int temp;
	while(head<tail){
		temp = array[head++];
		cout<<temp<<" ";
		for(int i=0;i<=1;i++)
		{
			if(tree[temp][i]!=-1)
				array[tail++] = tree[temp][i];
		}	
	}
}

int main(){

	int max=0;
	cin>>n;
	for(int i=0;i<=2999999;i++)
		tree[i][0] = tree[i][1] = -1;
	for(int i=1;i<=n-1;i++)
	{	
		cin>>father;
		if(tree[father][0]==-1){
			//cout<<i<<" is "<<father<<"'s left child! "<<endl;
			tree[father][0] = i;
		}
		else{
			//cout<<i<<" is "<<father<<"'s right child! "<<endl;
			tree[father][1] = i;
		}
	}
	bfs();
}
