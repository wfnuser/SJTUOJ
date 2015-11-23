#include<iostream>
#include<cstdlib>

using namespace std;


int a[10000];
int b[10000];


void qsort(int a[],int s,int e){
	if(s>=e) return;
	int pivot;
	pivot = a[s];
	int l=s,r=e;
	int temp;
	while(l<r){
		while(l<r&&a[r]<=pivot) r--;
			a[l] = a[r];
		while(l<r&&a[l]>=pivot) l++;
			a[r] = a[l];
	}
	a[l] = pivot;
	qsort(a,s,l-1);
	qsort(a,l+1,e);
}
int main(){
	int n,m;
	int i,j;
	cin>>n>>m;
	int sum=0;	

	for(i=0;i<=n-1;i++)
		cin>>a[i];
	for(j=0;j<=m-1;j++)
		cin>>b[j];

	qsort(a,0,n-1);
	qsort(b,0,m-1);

	int pos=0;
	int flag=0;
	//for(i=0;i<=n-1;i++)
	//	cout<<a[i]<<" ";
	//cout<<endl;
	//for(j=0;j<=m-1;j++)
	//	cout<<b[j]<<" ";
	//cout<<endl;
	for(i=0;i<=n-1;i++)
	{
		for(j=pos;j<=m-1;j++){
			if(b[j]<a[i]) {sum++;break;}
		}
		pos = j+1;
		if(pos>=m) break;
	}
	cout<<sum+n;
}

