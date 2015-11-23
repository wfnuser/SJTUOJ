#include<iostream>
#include<cstdlib>

using namespace std;

int main(){
	int n;
	int k;
	int i;
	int j;
	int pos=0;
	int max=0;
	int out=2000000000;
	int posmax;
	int a[2000001];

	cin>>n>>k;

	for(i=0;i<=n-1;i++)
		cin>>a[i];
	
	int count=0;
	while(pos<=n-1)
	{
		count++;
		//cout<<"the "<<count<<"'s try!"<<endl;
		max = 0;
		for(i=pos;i<=pos+k-1;i++)
		{
			if(max<=a[i%n]) {max = a[i%n];posmax=i;}
			if(a[i%n]>=out) {posmax = i;max=a[i%n];break;}
		}
		pos = posmax;
		//cout<<"the position max is: "<<pos<<" the number is: "<<max<<endl;
		if(out>=max)
			out = max;
		//cout<<"the out is: "<<out<<endl;
		pos++;
	}
	cout<<out;
}
