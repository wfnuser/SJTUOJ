#include<iostream>
#include<cstdlib>

using namespace std;

int main(){
	int n;
	int a[100]={0};
	int father;
	int tree[100]={-1};
	int root;
	int max;

	cin>>n;
	a[0] = 0;
	
	for(int i=0;i<=99;i++)
		tree[i] = -1;
	tree[0] = 0;

	for(int i=1;i<=n-1;i++)
	{	
		cin>>father;
		root = a[father];
		//cout<<"the father is: "<<root<<endl;
		if(tree[root*2+1]==-1)
		{	
			tree[root*2+1] = i;
			a[i] = root*2+1;
			if(max<a[i]) max=a[i];
		}
		else{
			tree[root*2+2] = i;
			a[i] = root*2+2;
			if(max<a[i]) max = a[i];
		}
	}
	for(int i=0;i<=max;i++)
	{
		if(tree[i]!=-1) cout<<tree[i]<<" ";
	}
	//cout<<endl;
}
