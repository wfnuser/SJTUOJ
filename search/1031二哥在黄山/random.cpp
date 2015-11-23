#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

int main(){
	freopen("input.dat","w",stdout);
	srand(time(0));
	cout<<100<<endl;
	for(int i=0;i<=99;i++){
		for(int j=0;j<=99;j++)
			cout<<rand()%110<<" ";
		cout<<endl;
	}
}

