#include<iostream>
#include<cstdlib>
using namespace std;
int n;
int a[3000000]={0};
int father;
int tree[10000000]={-1};
int root;
int main(){

	int max=0;
	cin>>n;
	a[0] = 0;
	
	for(int i=0;i<=9999999;i++)
		tree[i] = -1;
	tree[0] = 0;

	for(int i=1;i<=n-1;i++)
	{	
		cin>>father;
		root = a[father];
		//cout<<"the father is: "<<root<<endl;
		if(root*2+2<=9999999){
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
	}
	for(int i=0;i<=max;i++)
	{
		if(tree[i]!=-1) cout<<tree[i]<<" ";
	}
	//cout<<endl;
}
