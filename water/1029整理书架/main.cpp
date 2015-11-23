#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int main(){
	int n;
	char buff[100000];
	string books[101];	
	int i,j;
	int a,b;

	cin>>n;
	//cout<<"the line num is: "<<n<<endl;
	//cout<<endl;
	cin.get();

	for(i=0;i<=n-1;i++){
		cin.getline(buff,100000);
		books[i] = buff;
		//cout<<"the "<<i<<" line is: "<<books[i]<<endl;
	}
	//cout<<endl;

	for(i=0;i<=n-2;i++)
	{
		cin>>a>>b;
		books[b-1] += " " + books[a-1];
		books[a-1] = "";
		//cout<<"put "<<a<<" after "<<b<<endl;
	}
	for(int i=n-1;i>=0;i--){
		if(books[i]!=""){
			cout<<books[i]<<endl;
			break;
		}
	}
}

