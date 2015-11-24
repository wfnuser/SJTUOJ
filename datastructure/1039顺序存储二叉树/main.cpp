#include<iostream>
#include<cstdlib>

using namespace std;

void postorder(int a[],int b[],int root){
	if(a[root]==-1) return;
	//if(a[root*2]==-1 && a[root*2+1]==-1)
		//cout<<a[root]<<" ";
	postorder(a,b,root*2);
	postorder(a,b,root*2+1);	
	cout<<a[root]<<" ";
}

int main(){
	int n;
	int a[300000];//编号
	int b[300000];//序号
	int ser;
	int root;

	cin>>n;
	cin>>ser;
	a[1] = ser;
	b[ser] = 1;
	cin>>a[2];
	b[a[2]] = 2;
	cin>>a[3];
	b[a[3]] = 3;

	for(int i=2;i<=n;i++)
	{
		cin>>ser;
		root = b[ser];
		cin>>a[root*2];
		b[a[root*2]] = root*2;
		cin>>a[root*2+1];
		b[a[root*2+1]] = root*2+1;
	}
	
	for(int i=1;i<=n;i++){
		cout<<b[i]<<" ";
	}
	cout<<endl;

	postorder(a,b,1);	
}

