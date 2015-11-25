#include<iostream>
#include<cstdlib>

using namespace std;

int a[20000];//org_input [4,3,2,1] input is serial output is value
int b[20000];//after_sort [1,2,3,4] input is order output is value
int c[20000];//input is serial output is order [3,2,1,0]
int d[20000];//input is order output is serial after sort [3,2,1,0]
int n;

void qsort(int *a, int s, int e){
	if(s>=e) return;
	int l=s;
	int r=e;
	int pivot = a[s];
	int pos = d[s];
	while(l<r){
		while(l<r&&(a[r]<pivot||(a[r]==pivot&&d[r]<=pos))) r--;
		a[l] = a[r];
		d[l] = d[r];
		
		while(l<r&&(a[l]>pivot||(a[l]==pivot&&d[l]>=pos))) l++;
		a[r] = a[l];
		d[r] = d[l];
		
	}
	a[l] = pivot;
	d[l] = pos;
	qsort(a,s,l-1);
	qsort(a,l+1,e);
}

void run(int src,int tmn){
	int flag=100;
	int temp;
	if(tmn>a[src]) flag=1;
	if(tmn<a[src]) flag=0;
	a[src] = tmn;
	b[c[src]] = tmn;
	int pos = d[c[src]];
	if(flag==1){
		for(int i=c[src]-1;i>=0;i--)
			if(b[i]<tmn||(b[i]==tmn&&d[i]>pos)){
				c[d[i]]++;
				c[d[i+1]]--;
				b[i+1] = b[i];
				b[i] = tmn;
				temp = d[i];
				d[i] = d[i+1];
				d[i+1] = temp;		
			}
			else
				break;
	}
	if(flag==0){
		for(int i=c[src]+1;i<=n-1;i++)
			if(b[i]>tmn||(b[i]==tmn&&d[i]<pos)){
				c[d[i]]--;
				c[d[i-1]]++;
				b[i-1] = b[i];
				b[i] = tmn;
				temp = d[i];
				d[i] = d[i-1];
				d[i-1] = temp;		
			}
			else
				break;
	}

}

int main(){

	int k;
	char ch;
	int r;
	int src,tmn;

	cin>>n;
	for(int i=0;i<=n-1;i++){
		cin>>a[i];
		b[i] = a[i];
		d[i] = i;
	}

	qsort(b,0,n-1);
	for(int i=0;i<=n-1;i++)
		c[d[i]] = i;

	//cout<<endl;

	//for(int i=0;i<=n-1;i++)
        //        cout<<a[i]<<" ";
        //cout<<endl;
	//
	//for(int i=0;i<=n-1;i++)
	//	cout<<c[i]<<" ";
	//cout<<endl;

	//for(int i=0;i<=n-1;i++)
	//	cout<<b[i]<<" ";
	//cout<<endl;

	//for(int i=0;i<=n-1;i++)
	//	cout<<d[i]<<" ";
	//cout<<endl;
	cin>>k;
	int q;
	for(int i=0;i<=k-1;i++)
	{
		cin>>ch;
		if(ch=='M'){
			cin>>src>>tmn;
			run(src-1,tmn);
			//for(int i=0;i<=n-1;i++)
			//	cout<<d[i]+1<<" ";
			//cout<<endl;
			//cout<<"output by order";
			//for(int i=0;i<=n-1;i++)
			//	cout<<b[i]+1<<" ";
			//cout<<endl;
		}
		if(ch=='Q'){
			cin>>r;
			for(int i=0;i<=r-1;i++){
				cin>>q;
				cout<<d[q-1]+1<<" ";
			}
			cout<<endl;
		}
	}
}
